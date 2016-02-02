
CROSS_COMPILER ?= ../../../linaro/gcc-linaro-arm-linux-gnueabihf-4.8-2013.12_linux/bin/arm-linux-gnueabihf-

CC = ${CROSS_COMPILER}gcc

ic: ic.c
	${CC} ic.c -o ic -mfloat-abi=hard

scp: ic
	scp -P 9547 ic root@localhost:/home/root/ic

clean:
	rm -f ic *.o *~

