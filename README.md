# A10imagep
## Getting Started
This example requires a recent Vista42 alpha release as of January 2015, or more current if available.
From a fresh git clone these steps will let you run the demo.
- The Arria10 platform is required.  It should be installed under <vista-dir>/platforms/Arria10.
- Download the sdcard image from ftp://mentorweb.wv.mentorg.com/pub/a10ip/sd-angstrom-v2014.12-arria10swvp.img.tar.gz
  - Create a link under sw/buildsocvpsd to the extracted .img file above.
- Under hw execute
  - make mb
  - make
  - vista_simulate Arria10
Assuming everything went smoothly this should boot linux and open the framebuffer.

