#ifndef _JPEGHW_H_
#define _JPEGHW_H_

#include "ac_fixed.h"

#define FPGA_BASE     0xc0000000
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

struct argb_t {
  uint8 a;
  uint8 r;
  uint8 g;
  uint8 b;
};

#endif
