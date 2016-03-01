#!/usr/bin/env bash
#
# Copyright (c) 2015, Altera Corporation
# All rights reserved.
#
# Redistribution and use in source and binary forms, with or without
# modification, are permitted provided that the following conditions are met:
#
#     * Redistributions of source code must retain the above copyright
#       notice, this list of conditions and the following disclaimer.
#     * Redistributions in binary form must reproduce the above copyright
#       notice, this list of conditions and the following disclaimer in the
#       documentation and/or other materials provided with the distribution.
#     * Neither the name of Altera Corporation nor the
#       names of its contributors may be used to endorse or promote products
#       derived from this software without specific prior written permission.
#
# THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
# ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
# WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
# DISCLAIMED.  IN NO EVENT SHALL ALTERA CORPORATION BE LIABLE FOR ANY
# DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
# (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
# LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
# ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
# (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
# SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.


# ------------------------------------------------------------------------------
# Inputs
# ------------------------------------------------------------------------------

# Example:  buildsd.sd ~/angstrom arria10swvp arria10_swvp

ANGSTROM_PATH=$1 # This should be the path to the angstrom disribution,
                 # a dir containing angstrom-socfpga

PLATFORM=$2      # Either arria10swvp or stratix10swvp

DTBPLATFORM=$3   # Either arria10_swvp or stratix10_swvp, for device tree

# ------------------------------------------------------------------------------
# Definitions
# ------------------------------------------------------------------------------

ANGSTROM_VER=v2014.12

DEPLOY_PATH=${ANGSTROM_PATH}/angstrom-socfpga/deploy/glibc/images/${PLATFORM}

ZIMAGE=${DEPLOY_PATH}/zImage
SOCFPGA_DTB=${DEPLOY_PATH}/socfpga_${DTBPLATFORM}.dtb
ROOT_FILE_SYSTEM_TARBALL=${DEPLOY_PATH}/Angstrom-console-image-glibc-ipk-${ANGSTROM_VER}-${PLATFORM}.rootfs.tar.xz
SD_IMAGE_NAME=sd-angstrom-${ANGSTROM_VER}-${PLATFORM}.img

# Definitions of the partitions we wish to create on the SD card

# ------------------------------------------------------------------------------
# Implementaton
# ------------------------------------------------------------------------------

# Copy the root file system tarball to a temporary directory and uncompress it

if [ -d rfs ] ; then
    echo "Removing the old root file system temporary directory..."
    sudo rm -r rfs
    if [ $? -ne 0 ] ; then
        echo "Error: failed to remove the temporary diectory"
    fi
fi

# Make a temporary directory to store our root file system


echo "Creating the root file system temporary directory..."
sudo mkdir rfs
if [ $? -ne 0 ] ; then
    echo "Error: failed to create the temporary directory"
    exit $?
fi

# Unpack the root file system tarball to a temporary directory

echo "Root File System Tarball: ${ROOT_FILE_SYSTEM_TARBALL}"

if [ ! -f ${ROOT_FILE_SYSTEM_TARBALL} ]; then
    echo "Error: Root File system tarball does not exist"
    exit $?
fi

echo "Untarring the root file system..."
sudo tar xf ${ROOT_FILE_SYSTEM_TARBALL} -C rfs
if [ $? -ne 0 ] ; then
    echo "Error: failed to untar: ${ROOT_FILE_SYSTEM_TARBALL}"
    exit $?
fi

if [ ! -d rfs ]; then
    echo "Error: untar command did not work"
    exit $?
fi

# Create the SD card image using the make_sdimage.py script

P1_DATA="${ZIMAGE},${SOCFPGA_DTB}"
P2_DATA="$(readlink -f rfs)"

echo "Making the SD card image..."
sudo ./make_sdimage.py \
  -P "${P1_DATA}",num=1,format=vfat,size=20M \
  -P "${P2_DATA}",num=2,format=ext3,size=1G \
  -s 2G -n ${SD_IMAGE_NAME}

if [ $? -ne 0 ] ; then
    echo "Error: failed to create image"
fi

# Remove the temporary directory

echo "Removing the root file system temporary directory..."
sudo rm -r rfs
#sudo mv rfs rfs.$$
if [ $? -ne 0 ] ; then
    echo "Error: failed to remove the temporary diectory"
fi

# Tell the user if we passed or failed

if [ ! -f ${SD_IMAGE_NAME} ]; then
    echo "Error: failed to create the SD card image"
else
    echo "Created the SD card image: ${SD_IMAGE_NAME}"
fi


