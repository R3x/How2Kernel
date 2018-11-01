ifneq (${KERNELRELEASE},)
obj-m += hello-1.o
obj-m += hello-2.o
obj-m += hello-3.o
obj-m += hello-4.o
#obj-m += hello-5.o
else
KERNEL_SOURCE :=/lib/modules/$(shell uname -r)/build
PWD := $(shell pwd)

default:
	$(MAKE) -C $(KERNEL_SOURCE) SUBDIRS=${PWD} modules
clean: 
	$(MAKE) -C $(KERNEL_SOURCE) SUBDIRS=${PWD} clean
endif
