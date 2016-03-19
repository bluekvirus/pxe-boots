#!/bin/bash

syslinuxver=4.06

#cd ./syslinux-$syslinuxver/make clean && make installer && cd ../

cp -rf ./syslinux-$syslinuxver/core/pxelinux.0 ./boot/
cp -rf ./syslinux-$syslinuxver/com32/menu/menu.c32 ./boot/
cp -rf ./syslinux-$syslinuxver/memdisk/memdisk ./boot/
cp -rf ./syslinux-$syslinuxver/com32/hdt/hdt.c32 ./boot/
cp -rf ./syslinux-$syslinuxver/com32/modules/reboot.c32 ./boot/
cp -rf ./syslinux-$syslinuxver/modules/poweroff.com ./boot/