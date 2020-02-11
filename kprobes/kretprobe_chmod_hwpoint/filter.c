#include <linux/kernel.h>
#include <linux/kprobes.h>
#include <linux/fs.h>
#include <linux/writeback.h>
#include <linux/mm.h>
#include "filter.h"
#include "xfs/xfs_linux.h"
#include "xfs/xfs_inode_buf.h"
#include "xfs/xfs_format.h"
#include "xfs/xfs_log_format.h"
#include "xfs/xfs_inode.h"
#include "xfs/xfs_bmap.h"
#include <linux/device-mapper.h>

int alloc_filter(struct pt_regs *regs)
{
        struct dentry *dentry = regs->si;
        umode_t mode = regs->dx;

        if(!dentry)
                return 0;
        if(strcmp(dentry->d_name.name,"tmp"))
                return 0;
        mode = (mode & 0x7) + ((mode >> 3) & 0x7) * 10 + ((mode >> 6) & 0x7) * 100;
        printk("xfs-----------------------------------!\n");
        printk("<comm> %s ",current->comm);
        if(current->real_parent)
                printk("<parent comm> %s ",current->real_parent->comm);
        printk("<name>: %s ",dentry->d_name.name);
        printk("<mode> %d!\n",mode);
        printk("xfs-----------------------------------!\n");


        return 1;
}

