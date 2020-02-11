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

int alloc_filter(struct pt_regs *regs, unsigned long s)
{
	int rw = regs->di;
	struct bio *bio = regs->si;
	
	if(!bio)	
		return 0;
	if(!(rw & REQ_META))
		return 0;
	if(s && (s != bio->bi_end_io))
		return 0;
	dump_stack();
	
	return 0;	

}
