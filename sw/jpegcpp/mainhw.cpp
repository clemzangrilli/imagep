////////////////////////////////////////////////////////////////////////////////
// Catapult Synthesis
//
// Copyright (c) 2003-2015 Calypto Design Systems, Inc.
//       All Rights Reserved
//
// This document contains information that is proprietary to Calypto Design
// Systems, Inc. The original recipient of this document may duplicate this
// document in whole or in part for internal business purposes only, provided
// that this entire notice appears in all copies. In duplicating any part of
// this document, the recipient agrees to make every reasonable effort to
// prevent the unauthorized use and distribution of the proprietary information.
//
// The design information contained in this file is intended to be an example
// of the functionality which the end user may study in preparation for creating
// their own custom interfaces. This design does not present a complete
// implementation of the named protocol or standard.
//
// NO WARRANTY.
// CALYPTO DESIGN SYSTEMS, INC. EXPRESSLY DISCLAIMS ALL WARRANTY
// FOR THE SOFTWARE. TO THE MAXIMUM EXTENT PERMITTED BY APPLICABLE
// LAW, THE SOFTWARE AND ANY RELATED DOCUMENTATION IS PROVIDED "AS IS"
// AND WITH ALL FAULTS AND WITHOUT WARRANTIES OR CONDITIONS OF ANY
// KIND, EITHER EXPRESS OR IMPLIED, INCLUDING, WITHOUT LIMITATION, THE
// IMPLIED WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR
// PURPOSE, OR NONINFRINGEMENT. THE ENTIRE RISK ARISING OUT OF USE OR
// DISTRIBUTION OF THE SOFTWARE REMAINS WITH YOU.
//
////////////////////////////////////////////////////////////////////////////////

#include "bitstream.h"
#include "bmp.h"
#include "jpeghw.h"
#include <mc_scverify.h>

#include <unistd.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <poll.h>
#include <fcntl.h>
#include <errno.h>
#include <sys/mman.h>


#include <iostream>
#include <string.h>

using std::cout;
using std::endl;

void jpgencoder(const char * bmpfilename, const char * jpgfilename)
{

  volatile jpeg_reg_t *jpeg_reg;
  volatile unsigned char * jpeg_src;
  volatile unsigned char * jpeg_dst;
  unsigned char * jpeg_mmap;

  cout << " Reading BMP file " << bmpfilename << endl;
  bmp * bitmap = new bmp(bmpfilename);

  int fdjpg = open(jpgfilename, O_RDWR | O_CREAT | O_TRUNC, (mode_t)0600);
  if (fdjpg == -1) { perror("Error opening file for jpg"); exit(EXIT_FAILURE); }

  int fd = open("/dev/uio1", O_RDWR);
  if (fd < 0) { perror("open"); exit(EXIT_FAILURE); }

  int fdmem = open("/dev/uio2", O_RDWR);
  if (fdmem < 0) { perror("open"); exit(EXIT_FAILURE); }

  /* mmap the UIO devices */
  jpeg_reg = (jpeg_reg_t *)mmap(NULL, JPEG_REG_SIZE, PROT_READ|PROT_WRITE, MAP_SHARED, fd, 0);
  if (!jpeg_reg) { printf("mmapn jpeg_reg failed"); return; }

  jpeg_src = (volatile unsigned char *)mmap(NULL, 2*JPEG_BUF_SIZE, PROT_READ|PROT_WRITE,
                                              MAP_SHARED, fdmem, 0);
  if (!jpeg_src) { printf("mmapn jpeg_reg failed"); return; }

  jpeg_dst = &jpeg_src[JPEG_BUF_SIZE];

  jpeg_reg->source = JPEG_BUFFER - FPGA_BASE ;
  jpeg_reg->dest = JPEG_BUFFER + JPEG_BUF_SIZE - FPGA_BASE;

  cout << " Compressing to JPG file " << jpgfilename << endl;

  // rows and columns must be divisible by 8, so make bigger if necessary
  if (bitmap->rows() % 8) {
    printf("  ERROR: number of rows (image width) must be divisible by 8. please resize original bitmap image\n");
    exit(-1);
  }
  if (bitmap->columns() % 8) {
    printf("  ERROR: number of columns (image height) must be divisible by 8. please resize original bitmap image\n");
    exit(-1);
  }

  unsigned int img_rows = bitmap->rows();
  unsigned int img_columns = bitmap->columns();

  jpeg_reg->ssize = (img_columns << 13) | img_rows;

  volatile argb_t *rgb = (argb_t *)jpeg_src;           // 8x8 RGB block (R:0, G:1, B:2)

  int offset = 0;
  int loc;
  unsigned int a, r, g, b;
  // for every 8x8 pixel block in the bitmap image
  for (unsigned i = 0; i < img_rows; i += 8) {
    for (unsigned j = 0; j < img_columns; j += 8) {
      // extract 8x8 RGB block from bitmap array
      for (unsigned int x=0; x<8; x++) {
        for (unsigned int y=0; y<8; y++) {
          loc = (((x*8)+y)*4) + offset;
          jpeg_src[loc] = a = (unsigned char) 0;
          jpeg_src[loc+1] = r = bitmap->red(i+x, j+y);
          jpeg_src[loc+2] = g = bitmap->green(i+x, j+y);
          jpeg_src[loc+3] = b = bitmap->blue(i+x, j+y);
          //rgb[x*8+y].a = (uint8) 0;
          //rgb[x*8+y].r = bitmap->red(i+x, j+y);
          //rgb[x*8+y].g = bitmap->green(i+x, j+y);
          //rgb[x*8+y].b = bitmap->blue(i+x, j+y);
        }
      }
      offset += 256;
    }
  }
  jpeg_reg->start = 1;

  uint32_t info = 1; /* unmask */
  ssize_t nb = write(fd, &info, sizeof(info));
  if (nb < sizeof(info)) { perror("write"); close(fd); exit(EXIT_FAILURE); }

  struct pollfd fds = {
      .fd = fd,
      .events = POLLIN, };

  int ret = poll(&fds, 1, -1);
  if (ret <= 0) { perror("poll()"); close(fd); exit(EXIT_FAILURE); } 

  nb = read(fd, &info, sizeof(info));
  jpeg_reg->start = 0;
  if (nb != sizeof(info)) {
    printf("Interrupt read returned wrong size #%u!\n", info);
  } else {
    /* Do something in response to the interrupt. */
    printf("Interrupt #%u!  \n", info);
    int jpegsize = jpeg_reg->sdest;
    assert (ftruncate(fdjpg, jpegsize) == 0);
    printf("Creating output jpg file.\n");
    jpeg_mmap = (unsigned char *)mmap(0, jpegsize, PROT_READ | PROT_WRITE, MAP_SHARED, fdjpg, 0);
    memcpy((void *)jpeg_mmap, (void *)jpeg_dst, jpegsize);
    munmap(jpeg_mmap, jpegsize);
    close(fdjpg);
  }

  munmap((void *)jpeg_reg, JPEG_REG_SIZE);
  munmap((void *)jpeg_src, 2*JPEG_BUF_SIZE);
  close(fd);
  close(fdmem);

  cout << " ...Done" << endl << endl;

}


CCS_MAIN(int argc, const char *argv[])
{
  char *output;
  
  switch (argc) {
    case 3:
      jpgencoder(argv[1], argv[2]);
      break;
    case 2:
      output = (char *)malloc(strlen(argv[1])+4);
      strcpy(output, argv[1]);
      strcat(output, ".jpg");
      jpgencoder(argv[1], output);
      break;
    default:
      jpgencoder("small1.bmp", "small1.bmp.jpg");
      break;
  }
  CCS_RETURN(0);
}
