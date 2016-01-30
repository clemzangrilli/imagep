
CROSS_COMPILER ?= /home/tools/linaro/gcc-linaro-arm-linux-gnueabihf-4.8-2013.12_linux/bin/arm-linux-gnueabihf-

CC = ${CROSS_COMPILER}gcc
CXX = ${CROSS_COMPILER}g++

SRCSW = mainsw.cpp bitstream.cpp bmp.cpp jpeg.cpp huff.cpp dct.cpp
SRCHW = mainhw.cpp bitstream.cpp bmp.cpp jpeg.cpp huff.cpp dct.cpp jpeghw.cpp
OBJSW = $(SRCSW:.cpp=.o)
OBJHW = $(SRCHW:.cpp=.o)
DFILES = $(OBJSW:.o=.d) $(OBJHW:.o=.d)

INCDIR = -Icatapult
CFLAGS = -g
LIBS = 

EXE = jpegsw jpeghw

all: $(EXE)

jpeghw : $(OBJHW)
	$(CXX) $(CFLAGS) $(INCDIR) -o $@ $(OBJHW) $(LIBS) 2>&1 | c++filt

jpegsw : $(OBJSW)
	$(CXX) $(CFLAGS) $(INCDIR) -o $@ $(OBJSW) $(LIBS) 2>&1 | c++filt

scp: $(EXE)
	scp -P 9547 jpegsw jpeghw root@localhost:/home/root/

clean:
	rm -f $(EXE) *.d *.o *~

.cpp.o:
	$(CXX) $(CFLAGS) $(INCDIR) -c $< -o $*.o
	@$(CXX) -MM $(CFLAGS) $(INCDIR) -c $< > $*.d

.c.o:
	$(CC) $(CFLAGS) $(INCDIR) -c $< -o $*.o
	@$(CC) -MM $(CFLAGS) $(INCDIR) -c $< > $*.d

-include $(DFILES)
