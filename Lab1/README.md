# Lab 1
 
Let's build some kernel modules. 
This Lab will be dealing with only the hello world modules. 
 
# Reading Material
  
- Intro to kernel module programming (slides) 

# Instructions 
 
- Build the modules with `make`. If the kernel image and source have been prepared for ARM64 use `make arm`.
- Copy the resulting .ko files to the kernel via scp, the password is `123`.
```sh
scp -P 5022 <modulename>.ko root@localhost:.
```
- Insert the kernel modules using the `insmod <modulename>.ko`
- Interact with the kernel modules and check the results in the kernel logs with `dmesg`
- Remove the kernel modules with the `rmmod <modulename>` command
- Have fun !!!!

# Basic Commands

- `insmod`
- `rmmod`
- `modinfo`
