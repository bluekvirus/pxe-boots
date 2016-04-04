===============================
Prepare a custom PXE bootloader
@author Tim Lauv 
@created 03.2016

@credit Warren Block (2013) wblock@wonkity.com
@ref http://www.wonkity.com/~wblock/docs/html/pxe.html
@ref http://www.syslinux.org/wiki/index.php?title=Doc/building
@ref http://releng.archlinux.org/pxeboot/boot/cfg
===============================

pre. connect to serial port (e.g tinyserial)
```
sudo com /dev/ttyUSB0 115200 [or 9600]
```

0. download syslinux (contains pxelinux)
https://www.kernel.org/pub/linux/utils/boot/syslinux/
or
http://releng.archlinux.org/pxeboot/boot

1. install nasm before make

Use v4.06 if PXE ROM says 2012...

 make installer

Use v6+
 make [firmware[,firwmware]] [target[,target]]
 make bios efi64 installer

2. we need:
core/pxelinux.0 (bios only)
com32/menu/menu.c32
/memdisk/memdisk
[com32/menu/vesamenu.c32] -- for graphical menu support
com32/hdt/hdt.c32
com32/modules/reboot.c32
/modules/poweroff.com

(run ./extract-deployment.sh so the above files can be copied into /boot)

4. create /boot/pxelinux.cfg/default menu
see boot/pxelinux.cfg/

5. modify dnsmasq to point to boot
# /etc/dnsmasq.conf
enable-tftp
tftp-no-blocksize
tftp-root=/mnt/pxe/boot
dhcp-boot=pxelinux.0
[#dhcp-option-force=209, boot/pxelinux.cfg/default]

6. enable dns and dhcp
see Appendix A

# cli
sudo systemctl restart dnsmasq
journalctl -u dnsmasq -f

===============================
Appendix A - Share internet (as router)
===============================
see https://gist.github.com/bluekvirus/0f05e2f1251ebe3b23c7#file-team-server-readme-md
