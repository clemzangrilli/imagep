# imagep
## Getting Started
This example requires a recent Vista42 alpha release as of January 2015, or more current if available.
From a fresh git clone these steps will let you run the demo.
- The Arria10 platform is required.  It should be installed under \<vista-dir\>/platforms/Arria10.

- A cross compiler is needed on the host.  It can be downloaded using the following:
  - wget https://releases.linaro.org/archive/13.12/components/toolchain/binaries/gcc-linaro-arm-linux-gnueabihf-4.8-2013.12_linux.tar.bz2

The toolchain should be extracted in a linaro directory parrallel to the imagep directory.  From this directory the path to the cross-compiler gcc should be:
  - ../linaro/gcc-linaro-arm-linux-gnueabihf-4.8-2013.12_linux/bin/arm-linux-gnueabihf-gcc

- Setup the sw environment. A makefile under A10_sw will download and build the linux image and filesystem.
  - make

- On the host the libgd-dev package is required
  - sudo apt-get install libgd-dev

- Under A10_hw execute
  - make mb
  - make
  - make run

Assuming everything went smoothly this should boot linux and open the framebuffer.

To add a program to display jpg or bmp files on the framebuffer execute the following in the console.
> opkg update
> opkg install fbida

You should then be able to display an image with:
> fbi -T 1 -d /dev/fb0 <image-file>

This project depends on the jpeg project.  If the jpeg project is cloned into the directory
parrallel to the imagep project all of the links and references should work correctly.
