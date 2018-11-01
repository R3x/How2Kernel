# HowToKernel

This Repository aims at giving a basic idea about Kernel Exploitation.

## Setup the environment

- Clone the repository to your system `git clone https://github.com/R3x/How2Kernel ~/How2Kernel`.
- Go to the folder containing the setup `cd ~/How2kernel`
- run setup.sh to setup the Lab and testing environment
 - In case you want to run the modules in your own system `./setup.sh -local`
 - To build a virtual environment with QEMU `./setup.sh -virt -<architecture>`.
- Start Hacking the kernel !!!

* Make sure there are no spaces in the path to the directory that you have cloned. This will cause errors while building.
* Architectures supported currently `-arm` for Aarch 64 architecture and `-x86` for amd64 architecture.

 ## Labs

### Lab 1 - Intro to Kernel and Kernel Modules

This lab aims to give an idea about the kenrel and the kenrel space to the user. 
We will try building some basic kernel modules and see their impact with the kernel.
 
## Takeaways

### Images

There are a couple of precomplied images in the images folder which can be used with qemu.

### Qemu Scripts

There are some example scripts made for debugging the kernel with qemu.
