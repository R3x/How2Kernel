#### What is a kernel module ?

A kernel module is a C program that can be loaded and unloaded (ie.,inserted or removed) from the kernel itself.

#### Why are modules used ?

A module is used to extend the functionality of the kernel. When a new device is connected to the computer, for an interaction to take place, a module or C program is loaded into the kernel to communicate with the device. This is called a driver module. 

#### Why are kernel modules made loadable ?

Modules are loadable so that the kernel can be extended without having to recomiple and reboot it. Imagine having to restart your system everytime you connect to a device !!!

The informatiion on all the modules loaded into the kernel can be found in /proc/modules.

#### How are modules loaded into the kernel ?
Modules are loaded only when they are required by the kernel. The kernel achieves this feature with the kmod daemon. The kmod daemon executes modprobe to load the required modules. The arguments to modprobe can be pased in two ways:
* A module name like hello_world.
* An identifier (alias)

The aliases are found in /etc/modprobe.conf or /etc/modprobe.d 

## Basic Commands

#### lsmod
Lists all the modules currently loaded into the kernel. This data is fetched from /proc/modules

#### insmod
Inserts a module that is passed as argument, into the kernel.

#### rmmod
Remove or unload a module passed as argument, from the kernel.


#### modprobe 
Inserts a module into the kernel. Smarter than insmod, as modprobe checks for any prequisite modules that has to be loaded before the requested module to avoid any dependency issues. Modules to be preloaded are found in /lib/modules/version/modules.dep/ .

#### depmod 
Generates the modules.dep file








