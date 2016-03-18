#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <poll.h>
#include <fcntl.h>
#include <errno.h>
#include <sys/mman.h>

#define FPGA_BASE     0xc0000000
#define IC_BASE       0xd0000000
#define IC_REG_SIZE   0x1000
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

int main(void)
{
    printf("Opening ImageCapture /dev/uio0\n");
    int icDevice = open("/dev/uio0", O_RDWR);
    if (icDevice < 0) { perror("open"); exit(EXIT_FAILURE); }
    printf("Opening FPGA Buffer /dev/uio2\n");
    int memDevice = open("/dev/uio2", O_RDWR);
    if (memDevice < 0) { perror("open"); exit(EXIT_FAILURE); }

    /* mmap the UIO devices */
    ic_reg = (ic_reg_t *)mmap(NULL, IC_REG_SIZE, PROT_READ|PROT_WRITE, MAP_SHARED, icDevice, 0);
    if (!ic_reg) { printf("mmapn ic_reg failed"); return -1; }

    ic_target = (volatile unsigned char *)mmap(NULL, FPGA_BUF_SIZE, PROT_READ|PROT_WRITE, 
                                              MAP_SHARED, memDevice, 0);
    if (!ic_target) { printf("mmapn ic_target failed"); return -1; }

    ic_reg->TARGET = FPGA_BUFFER - FPGA_BASE ;

    unsigned char data = 1;
    unsigned char i;

    enableInterrupt(icDevice);

    printf("Capturing Image\n");
    ic_reg->CONTROL = 1;

    if(waitForInterrupt(icDevice)) {
        ic_reg->CONTROL = 0;
        printf("Received Interrupt\n");
        printf("Size of image = %lu \n", ic_reg->SIZE);

        FILE *ptr_fp;
        if((ptr_fp = fopen("capture.bmp", "wb")) == NULL) {
            printf("Unable to open file!\n");
            exit(1);
        }

        if( fwrite((unsigned char *) ic_target, ic_reg->SIZE, 1, ptr_fp) != 1) {
            printf("Write error!\n");
            exit(1);
        }
	fclose(ptr_fp);
        printf("Wrote image as 'capture.bmp'\n");
    }
    
    close(icDevice);
    close(memDevice);
    exit(EXIT_SUCCESS);
}

