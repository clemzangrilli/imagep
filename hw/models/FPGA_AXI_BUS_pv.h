
/**************************************************************/
/*                                                            */
/*      Copyright Mentor Graphics Corporation 2006 - 2015     */
/*                  All Rights Reserved                       */
/*                                                            */
/*       THIS WORK CONTAINS TRADE SECRET AND PROPRIETARY      */
/*         INFORMATION WHICH IS THE PROPERTY OF MENTOR        */
/*         GRAPHICS CORPORATION OR ITS LICENSORS AND IS       */
/*                 SUBJECT TO LICENSE TERMS.                  */
/*                                                            */
/**************************************************************/


#pragma once
#include "FPGA_AXI_BUS_model.h"

class FPGA_AXI_BUS_pv : public FPGA_AXI_BUS_base1_pv {
public:
  FPGA_AXI_BUS_pv(sc_module_name module_name)
    : FPGA_AXI_BUS_base1_pv(module_name) {
  }
};
