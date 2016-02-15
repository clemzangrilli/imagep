#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <poll.h>
#include <fcntl.h>
#include <errno.h>
#include <sys/mman.h>
#include <linux/fb.h>
#include <string.h>
#include <time.h>
#include <math.h>

#define IWIDTH 352
#define IHEIGHT 288

#define FPGA_BASE     0xc0000000
#define IC_BASE       0xd0000000
#define IC_REG_SIZE   0x1000
#define IP_BASE       0xd0002000
#define IP_REG_SIZE   0x1000
#define FPGA_BUFFER   0xe0000000
#define FPGA_BUF_SIZE 0x00200000

typedef struct {
  unsigned CONTROL;
  unsigned WIDTH;
  unsigned HEIGHT;
  unsigned TARGET;
  unsigned SIZE;
} volatile ic_reg_t;

ic_reg_t * ic_reg;

typedef struct {
  unsigned CONTROL;
  unsigned SOURCE;
  unsigned SIZE;
  unsigned TARGET;
} volatile ip_reg_t;

ip_reg_t * ip_reg;

int icDevice;
int ipDevice;
int memDevice;

volatile unsigned char * ic_target;

void enableInterrupt(int fd) 
{
    uint32_t info = 1; /* unmask */
    ssize_t nb = write(fd, &info, sizeof(info));
    if (nb < sizeof(info)) { 
      perror("write"); 
      close(fd); 
      exit(EXIT_FAILURE);
    }
}

int waitForInterrupt(int fd)
{
    struct pollfd fds = {
           .fd = fd,
           .events = POLLIN, };

    uint32_t info;
    ssize_t nb;

    int ret = poll(&fds, 1, -1);
    if (ret <= 0) { 
        perror("poll()"); 
        close(fd); 
        exit(EXIT_FAILURE);
    } 

    nb = read(fd, &info, sizeof(info));
    if (nb == sizeof(info)) {
        return info;
    } 

    printf("Interrupt read returned wrong size #%u!\n", info);
    return 0;
}

int captureImage(void)
{
    enableInterrupt(icDevice);

    ic_reg->TARGET = FPGA_BUFFER - FPGA_BASE ;
    ic_reg->CONTROL = 1;

    if(waitForInterrupt(icDevice)) {
        ic_reg->CONTROL = 0;
    }    
}


typedef struct {
  unsigned char red;
  unsigned char green;
  unsigned char blue;
} pixel_t;

double sRGB_to_linear(double x) {
    if (x < 0.04045) return x/12.92;
    return pow((x+0.055)/1.055, 2.4);
}

double linear_to_sRGB(double y) {
    if (y <= 0.0031308) return 12.92 * y;
    return 1.055 * pow(y, 1/2.4) - 0.055;
}

void getPixel(unsigned char* bmp, int x, int y, pixel_t* p)
{
  unsigned char* top = (bmp + ic_reg->SIZE) - (IHEIGHT * IWIDTH * 3);
  p->red = top[0 + ((y * IWIDTH + x) * 3)];
  p->green = top[1 + ((y * IWIDTH + x) * 3)];
  p->blue = top[2 + ((y * IWIDTH + x) * 3)];
}

void setPixel(unsigned char* bmp, int x, int y, pixel_t* p)
{
  unsigned char* top = (bmp + ic_reg->SIZE) - (IHEIGHT * IWIDTH * 3);
  top[0 + ((y * IWIDTH + x) * 3)] = p->red;
  top[1 + ((y * IWIDTH + x) * 3)] = p->green;
  top[2 + ((y * IWIDTH + x) * 3)] = p->blue;
}


void grayScale(pixel_t* p)
{
  double R_linear = sRGB_to_linear(p->red/255.0);
  double G_linear = sRGB_to_linear(p->green/255.0);
  double B_linear = sRGB_to_linear(p->blue/255.0);
  double gray_linear = 0.2126 * R_linear + 0.7152 * G_linear + 0.0722 * B_linear;
  double gray_color = round(linear_to_sRGB(gray_linear) * 255);
  p->red = gray_color;
  p->green = gray_color;
  p->blue = gray_color;
}

unsigned char* SW_ProcessImage()
{
    char *b = (char*) malloc(ic_reg->SIZE + 1);
    pixel_t p;
    int i, j, x, y;
    int res = 8;
    for (y = 0; y < IHEIGHT; y+=res) {
      for(x = 0; x < IWIDTH; x+=res) {
        getPixel((unsigned char*) ic_target, x, y, &p);
        for(i = 0; i < res; i++) {
          for(j = 0; j < res; j++) {
            grayScale(&p);
            setPixel(b, x+i, y+j, &p);
          }
        }
      }
    }
    return(b);
}

int FPGA_ProcessImage(void)
{
    enableInterrupt(ipDevice);

    ip_reg->SOURCE = FPGA_BUFFER - FPGA_BASE ;
    ip_reg->SIZE = ic_reg->SIZE;
    ip_reg->TARGET = FPGA_BUFFER - FPGA_BASE ;
    ip_reg->CONTROL = 1;

    if(waitForInterrupt(ipDevice)) {
        ip_reg->CONTROL = 0;
    }    
}

void
bmp_dump(unsigned char *dst, unsigned char* raw)
{
    unsigned int y,x = 0;
    unsigned char* top = raw - (IWIDTH * IHEIGHT) * 3;
    unsigned char* t = top;

    dst = dst + (IWIDTH * IHEIGHT * 4) - 4;

    for (y = 0; y < IHEIGHT; y++) {
	for (x = 0; x < IWIDTH; x++) {
	    dst[0] = t[0];
	    dst[1] = t[1];
	    dst[2] = t[2];
	    dst -= 4;
	    t += 3;
	}
    }
}

int main(void)
{
    const unsigned long long nano = 1000000000;

    unsigned long long st, et, t1, t2;
    struct timespec tm;

    int fbfd = 0;
    struct fb_var_screeninfo vinfo;
    struct fb_fix_screeninfo finfo;
    long int screensize = 0;
    char *fbp = 0;

    printf("Opening ImageCapture /dev/uio0\n");
    icDevice = open("/dev/uio0", O_RDWR);
    if (icDevice < 0) { perror("open"); exit(EXIT_FAILURE); }
    printf("Opening ImageProcessing /dev/uio3\n");
    ipDevice = open("/dev/uio3", O_RDWR);
    if (ipDevice < 0) { perror("open"); exit(EXIT_FAILURE); }
    printf("Opening FPGA Buffer /dev/uio2\n");
    memDevice = open("/dev/uio2", O_RDWR);
    if (memDevice < 0) { perror("open"); exit(EXIT_FAILURE); }

    /* mmap the UIO devices */
    ic_reg = (ic_reg_t *)mmap(NULL, IC_REG_SIZE, PROT_READ|PROT_WRITE, MAP_SHARED, icDevice, 0);
    if (!ic_reg) { printf("mmapn ic_reg failed"); return -1; }

    ic_target = (volatile unsigned char *)mmap(NULL, FPGA_BUF_SIZE, PROT_READ|PROT_WRITE, 
                                              MAP_SHARED, memDevice, 0);
    if (!ic_target) { printf("mmapn ic_target failed"); return -1; }

    ip_reg = (ip_reg_t *)mmap(NULL, IP_REG_SIZE, PROT_READ|PROT_WRITE, MAP_SHARED, ipDevice, 0);
    if (!ip_reg) { printf("mmapn ip_reg failed"); return -1; }

    // Open the file for reading and writing
    fbfd = open("/dev/fb0", O_RDWR);
    if (fbfd == -1) {
        perror("Error: cannot open framebuffer device");
        exit(1);
    }
    printf("The framebuffer device was opened successfully.\n");

    // Get fixed screen information
    if (ioctl(fbfd, FBIOGET_FSCREENINFO, &finfo) == -1) {
        perror("Error reading fixed information");
        exit(2);
    }

    // Get variable screen information
    if (ioctl(fbfd, FBIOGET_VSCREENINFO, &vinfo) == -1) {
        perror("Error reading variable information");
        exit(3);
    }

    printf("%dx%d, %dbpp\n", vinfo.xres, vinfo.yres, vinfo.bits_per_pixel);

    // Figure out the size of the screen in bytes
    screensize = vinfo.xres * vinfo.yres * vinfo.bits_per_pixel / 8;

    // Map the device to memory
    fbp = (char *)mmap(0, screensize, PROT_READ | PROT_WRITE, MAP_SHARED, fbfd, 0);
    if ((int)fbp == -1) {
        perror("Error: failed to map framebuffer device to memory");
        exit(4);
    }
    printf("The framebuffer device was mapped to memory successfully.\n");

 int mode = 0;
int todo = 10;
while(1) {
    printf("~~~~~~~~~~\n");
if(mode == 0) {
    printf("Using Software Image Processing\n");
   todo = 10;
} else {
    printf("Using FPGA Image Processing\n");
    todo = 50;
}

    int frame = 0;
    clock_gettime( CLOCK_REALTIME, &tm );
    st = tm.tv_nsec + tm.tv_sec * nano;
    while(frame < todo) {
    printf("\rFrame %d/%d", frame, todo);
fflush(stdout);

      clock_gettime( CLOCK_REALTIME, &tm );
      t1 = tm.tv_nsec + tm.tv_sec * nano;

      captureImage();
      bmp_dump(fbp, (unsigned char*) ic_target + ic_reg->SIZE);

if(mode == 0) {
      unsigned char* b = SW_ProcessImage();
      bmp_dump(fbp + (IWIDTH * IHEIGHT * 4), b + ic_reg->SIZE);
      free(b);
} 
else {
      FPGA_ProcessImage();
      bmp_dump(fbp + (IWIDTH * IHEIGHT * 4), (unsigned char*) ic_target + ic_reg->SIZE);
}
      frame++;

      clock_gettime( CLOCK_REALTIME, &tm );
      t2 = tm.tv_nsec + tm.tv_sec * nano;

      int sleeper = (50000 - ((t2 - t1) / 1000)); // 20 FPS
//      int sleeper = (20000 - ((t2 - t1) / 1000)); // 50 FPS
      if(sleeper > 0) {
        usleep(sleeper); 
      }
    }
    clock_gettime( CLOCK_REALTIME, &tm );
    et = tm.tv_nsec + tm.tv_sec * nano;

//    printf("\rTime to process %d frames - %lld\n", todo, (et-st) / 1000);
    printf("Frames Per Second - %f\n", ((double) todo / ((double) (et-st) / nano)));
if(mode == 0) {
  mode = 1;
} else {
  mode = 0;
}

}
    munmap(fbp, screensize);
    close(fbfd);

    close(icDevice);
    close(memDevice);

    exit(EXIT_SUCCESS);
}

