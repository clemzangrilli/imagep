# A10imagep
## Getting Started
This example requires a recent Vista42 alpha release as of January 2015, or more current if available.
From a fresh git clone these steps will let you run the demo.
- The Arria10 platform is required.  It should be installed under \<vista-dir\>/platforms/Arria10.
- Download the sdcard image from ftp://mentorweb.wv.mentorg.com/pub/a10ip/sd-angstrom-v2014.12-arria10swvp.img.tar.gz
  - Create a link under sw/buildsocvpsd to the extracted .img file above.
- Under hw execute
  - make mb
  - make
  - make run

Assuming everything went smoothly this should boot linux and open the framebuffer.

sudo apt-get install libgd-dev

wget https://releases.linaro.org/archive/13.12/components/toolchain/binaries/gcc-linaro-arm-linux-gnueabihf-4.8-2013.12_linux.tar.bz2

To add a program to display jpg or bmp files on the framebuffer execute the following in the console.
> opkg update
> opkg install fbida

You should then be able to display an image with:
> fbi -T 1 -d /dev/fb0 <image-file>

This project depends on the A10jpeg project.  If the A10jpeg project is cloned into the directory
parrallel to the A10imagep project all of the links and references should work correctly.
