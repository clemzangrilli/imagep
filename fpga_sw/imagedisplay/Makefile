
CROSS_COMPILER ?= ../../../linaro/gcc-linaro-arm-linux-gnueabihf-4.8-2013.12_linux/bin/arm-linux-gnueabihf-
#CROSS_COMPILER ?= ../../../linaro/gcc-linaro-4.8-2015.06-x86_64_aarch64-linux-gnu/bin/aarch64-linux-gnu-
#CROSS_COMPILER ?= ../../S10_sw/angstrom-socfpga/build/tmp-angstrom_v2014_12-glibc/sysroots/x86_64-linux/usr/bin/aarch64-angstrom-linux/aarch64-angstrom-linux-

CC = ${CROSS_COMPILER}gcc

all: id id2

id: id.c 
	${CC} id.c -ggdb -o id -lm

id2: id2.c 
	${CC} id2.c -ggdb -o id2 -lm -lpthread

scp: id id2
	scp -o StrictHostKeyChecking=no -P 9547 id id2 root@localhost:/home/root/

clean:
	rm -f id id2 *.o *~

