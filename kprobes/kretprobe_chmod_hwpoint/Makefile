CONFIG_MODULE_SIG=y
obj-m += Kretprobe.o
Kretprobe-objs := kretprobe.o
Kretprobe-objs += filter.o 
Kretprobe-objs += breakpoint.o 
CURRENT_PATH := $(shell pwd)
LINUX_KERNEL := /usr/src/kernels/$(shell uname -r)
#LINUX_KERNEL := "/home/hanjinke/kernel/kernel_stable/kernel-3.10.0-514/"
LINUX_KERNEL_PATH := $(LINUX_KERNEL)
#LINUX_KERNEL_PATH := /home/hjk/wankeyun/amlogicbuildroot/output/meson8b_m201/build/linux
#LINUX_KERNEL_PATH := /home/odin/hanjinke/kernel/kernel-3.10.0-514/
#EXTRA_CFLAGS = -g
all:
	make -C $(LINUX_KERNEL_PATH) M=$(CURRENT_PATH) modules
clean:
	make -C $(LINUX_KERNEL_PATH) M=$(CURRENT_PATH) clean
