CONFIG_MODULE_SIG=y
obj-m += Kprobe.o
Kprobe-objs := kprobe.o
Kprobe-objs += filter.o 
CURRENT_PATH := $(shell pwd)
LINUX_KERNEL := $(shell uname -r)
LINUX_KERNEL_PATH := /usr/src/kernels/$(LINUX_KERNEL)
#LINUX_KERNEL_PATH := /home/hjk/wankeyun/amlogicbuildroot/output/meson8b_m201/build/linux
#LINUX_KERNEL_PATH := /mnt/work/kernel_code/linux-stable
#EXTRA_CFLAGS = -g
all:
	make -C $(LINUX_KERNEL_PATH) M=$(CURRENT_PATH) modules
clean:
	make -C $(LINUX_KERNEL_PATH) M=$(CURRENT_PATH) clean
