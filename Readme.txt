===============================
Prepare a custom PXE bootloader
@author Tim Lauv 
@created 03.2016

@credit Warren Block (2013) wblock@wonkity.com
@ref http://www.wonkity.com/~wblock/docs/html/pxe.html
===============================
0. download syslinux (contains pxelinux)
https://www.kernel.org/pub/linux/utils/boot/syslinux/

1. install nasm before make
```
Quoting Readme.txt in syslinux-6.03
SYSLINUX now builds in a Linux environment, using nasm.  You need nasm
version 2.03 or later (2.07 or later recommended) to build SYSLINUX
from source.
```
Use v4 if PXE ROM says 2012...

2. after make, targets are ready in:
/bios (we use this one)
/efi32
/efi64

3. under each boot type dist we need:
[g]pxe/[g]pxelinux.0 (bios only)
com32/menu/menu.c32
[com32/menu/vesamenu.c32] -- for graphical menu support
com32/modules/reboot.c32
com32/modules/poweroff.c32
com32/hdt/hdt.c32

(into /boot if you prefer)

4. create /boot/pxelinux.cfg/default menu
see boot/pxelinux.cfg/

5. modify dnsmasq to point to boot
# /etc/dnsmasq.conf
enable-tftp
tftp-no-blocksize
tftp-root=/mnt/pxe/boot
pxe-service=x86PC, "Install Linux", pxelinux -- indicates <tftp-root>/pxelinux.0
# or
dhcp-boot=boot/gpxelinux.0
[#dhcp-option-force=209, boot/pxelinux.cfg/default]

# cli
sudo systemctl restart dnsmasq
journalctl -u dnsmasq -f