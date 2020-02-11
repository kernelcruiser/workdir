dracut -fH initramfs-$(uname -r).img $(uname -r)
vim /etc/systemd/system.conf
JoinControllers=cpu,cpuacct net_cls,net_prio blkio,memory
