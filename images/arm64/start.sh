#!/bin/bash

/usr/bin/qemu-system-aarch64 \
	-machine virt \
	-cpu cortex-a57 \
	-machine type=virt \
	-nographic -smp 1 \
	-m 2048 \
	-kernel ./Image \
	--append "console=ttyAMA0" \
	-redir tcp:5022::22
	$1 $2



