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
//#include "xfs/xfs_mount.h"

int filter(struct pt_regs *regs)
{
	//struct inode *inode = regs->di;
        //struct xfs_inode    *ip = container_of(inode, struct xfs_inode, i_vnode);
        struct xfs_inode *ip = regs->di;
	if(ip->i_vnode.i_ino == 67)
	{
	//	if(ip->i_df.if_flags)	
	//		printk(KERN_INFO"if_flags :%lx!\n",ip->i_df.if_flags);
	//		printk(KERN_INFO"i_ino :%ld!\n",ip->i_vnode.i_ino);
		//printk(KERN_INFO"inode->i_fop %pf!\n",(void*)inode->i_fop);
	//	printk("inode  :%lx!\n",inode);
		printk("di_magic     :%lx!\n",ip->i_d.di_magic);
		printk("if_flags %lx!\n",ip->i_df.if_flags);
		printk("di_format:%lx!\n",ip->i_d.di_format);
		if(ip->i_d.di_flags & 1)
			printk("real time mode!\n");
		//dump_stack();
	//	printk("inode2 :%lx!\n",&ip->i_vnode);
//		printk("span   :%lx!\n",((char*)inode - (char*)ip));
	        //printk("magic %lx!\n",ip->i_d.di_magic);
	//        printk("fsname %s!\n",ip->i_mount->m_fsname);
	}

	return 0;	
}

int mmap_filter(struct pt_regs *regs)
{
	struct address_space *mapping = regs->di;
	struct inode *inode = mapping->host;
	
	if(inode->i_ino == 10097584){	
		//printk("flags %lx!\n",(unsigned long)regs->cx);
		//printk("inode no %ld!\n",(unsigned long)inode->i_ino);
		dump_stack();
	}

	return 0;

}

