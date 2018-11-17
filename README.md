# HowToKernel

This repository is hosted with the aim of having a straightforward way to get started with kernel exploitaion in Linux OS.

## Setup the environment
 
- Clone the repository to your system `git clone https://github.com/R3x/How2Kernel ~/How2Kernel`.
- Go to the folder containing the setup `cd ~/How2kernel`
- run setup.sh to setup the Lab and testing environment
    - In case you want to run the modules in your own system `./setup.sh -l`
    - To build a virtual environment with QEMU `./setup.sh -v <architecture>`.
- Start Hacking the kernel !!!

#### Note
* Make sure there are no spaces in the path to the directory that you have cloned. This will cause errors while building.
* Architectures supported currently `arm` for Aarch 64 architecture and `x86` for amd64 architecture.
* Labs 1 - 3 focus only on developing kernel modules. This is done since we feel that it helps in getting a better idea of the kernel space. We recommend that you don't skip that part.

## Labs

|Lab No|Topic|Short Description|
|:-:|:-:|:-:|
|[Lab 1](Lab1/)|Hello world|Build and insert your 1st kernel module|
|[Lab 2](Lab2/)|Playing with Devices|Have fun with device|
|[Lab 3](Lab3/)|Proc filesytem fun|Build your way upto to a keylogger|
|[Lab 4](Lab4/)|Baby Kernel|Find your first kernel primitives|
|[Lab 5](Lab5/)|Null pointers|Exploit the null pointer derference bug and look at mitigations|
|[Lab_6](Lab6/)|Stack Smashing|Exploit a basic stack overflow bug|
|[Lab_7](Lab7/)|Rop Chaining|Create a ROP chain to bypass mitigation techniques|


## Takeaways

### Ksploit Library (_Work in progress_)

A library which can help you in writing exploits for kernels. We have added a couple of features that might come in handy. 

### CTF Challenges 

We have cherry picked CTF challenges across the years and have setup environments for them so that people can try them out without the hassle of setting up the proper environment. 

Moreover we have our own writeups written with the help of ksploit lib.

### Docs

Our docs contain a lot of facts that might come in handy if you are trying to write a kernel exploit.

- Setups - Documentation on how to setup kernel images for the kernel of your choice.
- Debugging - Documentation on how to setup a proper debugging channel for the kernel. Tips and tricks that might help you during debugging.
- Primitives - Documentation on the various attack vectors and ideas that might come in handy during exploits. 

### Images

There are a couple of precomplied images stored in our servers which can be used with qemu. Say Goodbye to the hassle of compiling your own images!

### Qemu Scripts

There are some example scripts made for debugging the kernel with qemu. 
 
## Contributors
 
This repository is maintained by

- Akul Pillai (k4iz3n)
- Vishnu Dev T J (n1ght_f0x)
- Mahesh Hari (slashbash)
- Siddharth Muralee (R3x) 

from team [bi0s](https://bi0s.in)
