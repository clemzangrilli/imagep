
CROSS_COMPILER ?= ../../../linaro/gcc-linaro-arm-linux-gnueabihf-4.8-2013.12_linux/bin/arm-linux-gnueabihf-

CC = ${CROSS_COMPILER}gcc

all: id id2

id: id.c 
	${CC} id.c -o id -lm

id2: id2.c 
	${CC} id2.c -o id -lm -lpthread

scp: id id2
	scp -P 9547 id root@localhost:/home/root/id
	scp -P 9547 id2 root@localhost:/home/root/id2

clean:
	rm -f id *.o *~

