
CROSS_COMPILER ?= ../../../linaro/gcc-linaro-arm-linux-gnueabihf-4.8-2013.12_linux/bin/arm-linux-gnueabihf-

CC = ${CROSS_COMPILER}gcc

id: id.c 
	${CC} id.c -o id -mfloat-abi=hard -lm

scp: id 
	scp -P 9547 id root@localhost:/home/root/id

clean:
	rm -f id *.o *~

