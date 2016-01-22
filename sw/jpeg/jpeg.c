#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <poll.h>
#include <fcntl.h>
#include <errno.h>
#include <sys/mman.h>

#define JPEG_BASE     0xd0001000
#define JPEG_REG_SIZE     0x1000
#define JPEG_BUFFER   0xe0000000
#define JPEG_BUF_SIZE 0x00200000

typedef struct {
  unsigned source;
  unsigned ssize;
  unsigned dest;
  unsigned sdest;
  unsigned status;
  unsigned start;
} volatile jpeg_reg_t;

jpeg_reg_t * jpeg_reg;

volatile unsigned char * jpeg_src;
volatile unsigned char * jpeg_dst;


int main(void)
{
    printf("Opening /dev/uio1!\n");

    int fd = open("/dev/uio1", O_RDWR);
    if (fd < 0) {
        perror("open");
        exit(EXIT_FAILURE);
    }

    /* mmap the UIO device */
    jpeg_reg = (jpeg_reg_t *)mmap(NULL, JPEG_REG_SIZE, PROT_READ|PROT_WRITE, MAP_SHARED, fd, 0);
    if (!jpeg_reg) {
        printf("mmapn jpeg_reg failed");
        return -1; }

    int loop = 0;

    while (1) {

        jpeg_reg->source = JPEG_BUFFER;
        jpeg_reg->dest = JPEG_BUFFER + JPEG_BUF_SIZE;
        jpeg_reg->start = 1;

        uint32_t info = 1; /* unmask */

        ssize_t nb = write(fd, &info, sizeof(info));
        if (nb < sizeof(info)) {
            perror("write");
            close(fd);
            exit(EXIT_FAILURE);
        }

        struct pollfd fds = {
            .fd = fd,
            .events = POLLIN,
        };

        int ret = poll(&fds, 1, -1);
        if (ret >= 1) {
            nb = read(fd, &info, sizeof(info));
            if (nb == sizeof(info)) {
                /* Do something in response to the interrupt. */
                printf("Interrupt #%u!\n", info);
            }
        } else {
            perror("poll()");
            close(fd);
            exit(EXIT_FAILURE);
        }
    }

    close(fd);
    exit(EXIT_SUCCESS);
}
