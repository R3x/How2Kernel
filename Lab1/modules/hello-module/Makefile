ifneq (${KERNELRELEASE},)
obj-m += hello-2.o
else
KERNEL_SOURCE :=/home/omen/Kernel/linux-4.18.16
PWD := $(shell pwd)

default:
	$(MAKE) -C $(KERNEL_SOURCE) SUBDIRS=${PWD} modules
clean: 
	$(MAKE) -C $(KERNEL_SOURCE) SUBDIRS=${PWD} clean
endif
