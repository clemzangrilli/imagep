
export TOOL_CHAIN=../../../../linaro/gcc-linaro-arm-linux-gnueabihf-4.8-2013.12_linux/bin
export TARGET=arm-linux-gnueabihf
export CROSS_COMPILE=$TOOL_CHAIN/$TARGET-
export ARCH=arm

if [ ! -f linux-socfpga.tar.xz ]; then
	wget ftp://mentorweb.wv.mentorg.com/pub/a10ip/linux-socfpga.tar.xz
fi

if [ ! -d linux-socfpga ]; then
	tar xvf linux-socfpga.tar.xz
fi

cp -rf ../kernel_patches/* linux-socfpga/
cp -rf ../kernel_patches/.config linux-socfpga/



