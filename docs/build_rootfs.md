## Creating a root filesystem with buildroot

Download latest buildroot image from https://buildroot.org/download.html 

After extracting the downloaded file.

```
cd buildroot-2018.02.7
```
As we are building a rootfs image for aarch64 you van find the .config file here. You always have the option of configuring it  yourselves using the menuconfig option.
```
$ make menuconfig
```
#### Check these option in the GUI

Target option --> Target acrhitecture --> (X) AArch64 (little endian)

Toolchain --> Toolchain type --> (X) External toolchain 

Toolchain --> Toolchain --> (X) Linaro AArch64 2016.02

System Configuration --> "Set a Root password"

System Configuration --> Run a getty (login prompt) after boot --> TTY port --> "set to TTYAMA0"

Target Packages --> (X) Show packages that are also provided by busybox 

Target Packages --> Debugging --> (X) strace

Target Packages --> Text editor --> (X) "your choice" 

Filesystem image --> (x) cpio root filesystem

#### New .config file will be created.

Now to build the image
```
$ make
```

Once the build is complete the image will be in output/images

### We have successfully created a cpio root filesystem with buildroot






