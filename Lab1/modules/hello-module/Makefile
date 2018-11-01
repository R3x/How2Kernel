ifneq (${KERNELRELEASE},)
obj-m += hello-2.o
else
KERNEL_SOURCE :=/lib/modules/$(shell uname -r)/build
PWD := $(shell pwd)

default:
	$(MAKE) -C $(KERNEL_SOURCE) SUBDIRS=${PWD} modules
clean: 
	$(MAKE) -C $(KERNEL_SOURCE) SUBDIRS=${PWD} clean
endif
