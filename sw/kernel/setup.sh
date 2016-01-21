
export TOOL_CHAIN=$(dirname $(dirname `which arm-none-eabi-gcc`))
export TARGET=arm-none-eabi
export CROSS_COMPILE=$TOOL_CHAIN/bin/$TARGET-
export ARCH=arm

if [ ! -f linux-socfpga.tar.xz ]; then
	wget ftp://mentorweb/pub/a10ip/linux-socfpga.tar.xz
fi

if [ ! -d linux-socfpga ]; then
	tar xvf linux-socfpga.tar.xz
fi

cp -rf ../kernel_patches/* linux-socfpga/
cp -rf ../kernel_patches/.config linux-socfpga/



