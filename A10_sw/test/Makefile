
CROSS_COMPILER ?= /home/tools/linaro/gcc-linaro-arm-linux-gnueabihf-4.8-2013.12_linux/bin/arm-linux-gnueabihf-

CC = ${CROSS_COMPILER}gcc
CXX = ${CROSS_COMPILER}g++

all: fact mem_test

fact: fact.cpp
	${CXX} -g fact.cpp -o fact

mem_test: mem_test.c
	${CC} mem_test.c -g -o mem_test -lpthread

scp: fact mem_test
	scp -P 9547 fact mem_test root@localhost:/home/root/

clean:
	rm -f fact *.o *~


