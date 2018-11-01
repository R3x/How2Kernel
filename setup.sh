#!/bin/bash

if [ $# -eq 0 ]
then
    echo "Please supply the needed arguments\n"
    exit
fi

if [ $1 == '-local' ]
then
    sudo apt update
    echo -e "\n---- Installing Kernel Headers -----\n\n"
    sudo apt install -y linux-headers-$(uname -r)
elif [ $1 == '-virt' ]
    then
    # Install qemu for running the kernel Images
    sudo apt update
    echo -e "\n---- Installing QEMU -----\n\n"
    sudo apt-get install -y qemu qemu-user qemu-user-static
    if [ $2 == '-arm'  ]
        then
        # GDB multiarch for Debugging
        sudo apt-get install -y gdb-multiarch
        # Cross Compiler for arm
        sudo apt-get install -y gcc-arm-linux-gnueabihf libc6-dev-armhf-cross libelf-dev
        tar -xvzf ./images/arm64/arm64-Image.tar.gz -C ./images/arm64/
    elif [ $2 == '-x86' ]
        then
        echo "Building for x86"
    else
        echo "Unknown parameter $2"
    fi
    echo -e "\n---- Installing Kernel Sources -----\n\n"
    mkdir kernel_source
    cd kernel_source
    wget -c  https://cdn.kernel.org/pub/linux/kernel/v4.x/linux-4.18.16.tar.xz
    echo "Unpacking Kernel Image"
    tar -xvf linux-4.18.16.tar.xz
else
    echo "Unknown parameter $1"
fi



