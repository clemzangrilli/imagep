#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <poll.h>
#include <fcntl.h>
#include <errno.h>
#include <sys/mman.h>

#define MAP_SIZE 0x1000


int main(void)
{
    volatile unsigned *ic;

    printf("Opening /dev/uio0!\n");

    int fd = open("/dev/uio0", O_RDWR);
    if (fd < 0) {
        perror("open");
        exit(EXIT_FAILURE);
    }

    /* mmap the UIO device */
    ic = (volatile unsigned *)mmap(NULL, MAP_SIZE, PROT_READ|PROT_WRITE, MAP_SHARED, fd, 0);
    if (!ic) {
        perror("mmap failure");
        exit(EXIT_FAILURE);
    }

    int loop = 0;

    uint32_t info = 1; /* unmask */

    struct pollfd fds = {
        .fd = fd,
        .events = POLLIN,
    };

    while (1) {

	/* Enable interrupts */
	info = 1;
        ssize_t nb = write(fd, &info, sizeof(info));
        if (nb < sizeof(info)) {
            perror("write");
            close(fd);
            exit(EXIT_FAILURE);
        }

        /* Wait for an interrupt */
        int ret = poll(&fds, 1, -1);
        if (ret >= 1) {
            nb = read(fd, &info, sizeof(info));
            if (nb == sizeof(info)) {
                /* Do something in response to the interrupt. */
	        ic[0] = loop++; /* Write to register */
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
