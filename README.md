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

|Lab No|Topic|Short Description|
|:-:|:-:|:-:|
|[Lab 1](Lab1/)|Hello world|Build and insert your 1st kernel module|
|[Lab 2](Lab2/)|Playing with Devices|Have fun with device|
|[Lab 3](Lab3/)|Proc filesytem fun|Build your way upto to a keylogger|
|[Lab 4](Lab4/)|Baby Kernel|Find your first kernel primitives|
|[Lab 5](Lab5/)|Null pointer game|Exploit the null pointer derference bug and look at mitigations|

## Takeaways
 
### Images

There are a couple of precomplied images in the images folder which can be used with qemu.

### Qemu Scripts
 
There are some example scripts made for debugging the kernel with qemu.

## Contributors

This repository is the work of 4 people from team [bi0s](https://bi0s.in)

- Vishnu Dev T J (n1ght_f0x)
- Akul Pillai (k4iz3n)
- Mahesh Hari (*some random nick*)
- Siddharth Muralee (R3x)
