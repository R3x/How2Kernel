#!/bin/bash

# Install qemu for running the kernel Images

sudo apt update
sudo apt-get install -y qemu qemu-user qemu-user-static

if [ $1 == '-arm' ]
then
    # GDB multiarch for Debugging
    sudo apt-get install -y gdb-multiarch

    # Cross Compiler for arm
    sudo apt-get install -y gcc-arm-linux-gnueabihf libc6-dev-armhf-cross
elif [ $1 == '-x86' ]
then

else
    echo "Unknown parameter $1"
fi

mkdir kernel_source
cd kernel_source
wget https://cdn.kernel.org/pub/linux/kernel/v4.x/linux-4.18.16.tar.xz
tar -xzvf linux-4.18.16.tar.xz


