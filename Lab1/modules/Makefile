ifneq (${KERNELRELEASE},)
obj-m += hello-1.o
obj-m += hello-2.o
obj-m += hello-3.o
obj-m += hello-4.o
#obj-m += hello-5.o
else
KERNEL_SOURCE := ../../kernel_source/linux-4.18.16/
PWD := $(shell pwd)
default:
	$(MAKE) -C $(KERNEL_SOURCE) SUBDIRS=${PWD} modules
arm:
	ARCH=arm64 CROSS_COMPILE=aarch64-linux-gnu- $(MAKE) -C $(KERNEL_SOURCE) SUBDIRS=${PWD} modules
clean:
	$(MAKE) -C $(KERNEL_SOURCE) SUBDIRS=${PWD} clean
endif
