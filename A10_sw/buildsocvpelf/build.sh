#!/bin/bash 

# This script is based on Mentor Graphics' work
# Simplified the user interface and the file location expectations.
# 
# Copyright 2015 Altera Corporation.
#
# Redistribution and use in source and binary forms, with or without
# modification, are permitted provided that the following conditions are met:
#
# 1. Redistributions of source code must retain the above copyright notice,
#    this list of conditions and the following disclaimer.
#
# 2. Redistributions in binary form must reproduce the above copyright notice,
#    this list of conditions and the following disclaimer in the documentation
#    and/or other materials provided with the distribution.
#
# 3. Neither the name of the copyright holder nor the names of its contributors
#    may be used to endorse or promote products derived from this software without
#    specific prior written permission.
#
# THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
# AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
# IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
# ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE
# LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
# CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
# SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
# INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
# CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
# ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
# POSSIBILITY OF SUCH DAMAGE.

# Internals
SELF="$(basename $0)"
SELF_DIR="$(dirname $0)"

# args
KERNEL=$1
DTB=$2
ELF=${3:-"linux-system.axf"}
CROSS_COMPILE="${4}"

# functions
function usage () {

    cat <<EOT
Usage: ${SELF} [-h] <zImage> <dtb> <elf>

 -h: this message
 zImage : Linux kernel image (e.g. zImage)
 dtb    : Device tree blob 
 elf    : name of the elf image to generate (default = linux-system.axf)
 cc     : base to cross compiler (like CROSS_COMPILE)

EOT
}

# Script starts here
if [ "${1}" == "-h" -o -z "${KERNEL}" -o -z "${DTB}" ] ; then
  usage
  exit 1
fi

# build steps
make clean
make DTB="${DTB}" KERNEL="${KERNEL}" \
     CROSS_COMPILE=${CROSS_COMPILE}
if [ $? -ne 0 ] ; then
    echo "${SELF}: error: make failed"
    exit 1
fi

if [ "${ELF}" != "linux-system.axf" ] ; then
    mv linux-system.axf ${ELF}
    exit $?
fi

exit 0
