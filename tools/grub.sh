cat /boot/grub2/grub.cfg |grep menuentry
grub2-set-default 'CentOS Linux (3.10.0+) 7 (Core)'
grub2-editenv list
grub2-mkconfig -o /boot/grub2/grub.cfg //更新grub

