# this is a minimal makefile for demo purposes, keep it that way...
obj-m:=msgq.o
msgq-objs:=main.o
V?=0
KDIR?=/lib/modules/$(shell uname -r)/build
# in an embedded system:
#KDIR:=[where the system maker gave me kernel headers+makefile or the kernel itself which has a makefile]
#ARCH:=arm
#CROSS_COMPILE:=[path+common prefix to where the toolchain is]
# You could also use W=2 and W=3 for more warnings but most kernel headers
# fail those...
W?=1
.PHONY: modules
modules:
	$(MAKE) -C $(KDIR) M=$(CURDIR) V=$(V) W=$(W) modules
.PHONY: clean
clean:
	$(MAKE) -C $(KDIR) M=$(CURDIR) V=$(V) clean
	rm -f *.stamp

.PHONY: user_space
user_space: usr/rm usr/sm usr/test

.PHONY: clean_user_space
clean_user_space:
	rm -f usr/rm usr/sm usr/test


usr/rm usr/sm usr/test: %: %.c
	cc -pedantic -g -ansi -Wall -o $@ $<

.PHONY: rmmod
rmmod:
	sudo rmmod msgq

.PHONY: insmod
insmod:
	sudo insmod ./msgq.ko
	sudo chmod 666 /dev/msgq*

.PHONY: remod
remod: rmmod insmod
