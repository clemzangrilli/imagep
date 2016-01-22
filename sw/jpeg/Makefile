
CROSS_COMPILER ?= ../../../linaro/gcc-linaro-arm-linux-gnueabihf-4.8-2013.12_linux/bin/arm-linux-gnueabihf-

CC = ${CROSS_COMPILER}gcc

jpeg: jpeg.c
	${CC} jpeg.c -o jpeg -mfloat-abi=hard
