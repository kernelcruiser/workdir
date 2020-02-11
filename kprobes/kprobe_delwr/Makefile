CONFIG_MODULE_SIG=y
obj-m += Kprobe.o
Kprobe-objs := kprobe.o
Kprobe-objs += filter.o 
CURRENT_PATH := $(shell pwd)
#LINUX_KERNEL := /usr/src/kernels/$(shell uname -r)
LINUX_KERNEL := /usr/src/kernels/$(shell uname -r)
LINUX_KERNEL_PATH := $(LINUX_KERNEL)
#LINUX_KERNEL_PATH := /home/hjk/wankeyun/amlogicbuildroot/output/meson8b_m201/build/linux
all:
	make -C $(LINUX_KERNEL_PATH) M=$(CURRENT_PATH) modules
clean:
	make -C $(LINUX_KERNEL_PATH) M=$(CURRENT_PATH) clean
