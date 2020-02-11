/*
 * data_breakpoint.c - Sample HW Breakpoint file to watch kernel data address
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.
 *
 * usage: insmod data_breakpoint.ko ksym=<ksym_name>
 *
 * This file is a kernel module that places a breakpoint over ksym_name kernel
 * variable using Hardware Breakpoint register. The corresponding handler which
 * prints a backtrace is invoked every time a write operation is performed on
 * that variable.
 *
 * Copyright (C) IBM Corporation, 2009
 *
 * Author: K.Prasad <prasad@linux.vnet.ibm.com>
 */
#include <linux/module.h>	/* Needed by all modules */
#include <linux/kernel.h>	/* Needed for KERN_INFO */
#include <linux/init.h>		/* Needed for the macros */
#include <linux/kallsyms.h>

#include <linux/perf_event.h>
#include <linux/hw_breakpoint.h>
#include "breakpoint.h"

struct perf_event * __percpu *sample_hbp;
static int count = 0;

void  hw_break_exit(void);
static void sample_hbp_handler(struct perf_event *bp,
			       struct perf_sample_data *data,
			       struct pt_regs *regs)
{
	dump_stack();
//	hw_break_exit();
	printk(KERN_INFO "Dump stack from sample_hbp_handler\n");
}

int  hw_break_init(unsigned long addr)
{
	int ret;
	struct perf_event_attr attr;
	
	if(count)
		return 0;
	hw_breakpoint_init(&attr);
	attr.bp_addr = addr;
	attr.bp_len = HW_BREAKPOINT_LEN_2;
	attr.bp_type = HW_BREAKPOINT_W;

	sample_hbp = register_wide_hw_breakpoint(&attr, sample_hbp_handler, NULL);
	if (IS_ERR((void __force *)sample_hbp)) {
		ret = PTR_ERR((void __force *)sample_hbp);
		goto fail;
	}

	printk(KERN_INFO "HW Breakpoint for mode installed\n");
	count++;
	return 0;

fail:
	printk(KERN_INFO "Breakpoint registration failed\n");

	return ret;
}

void  hw_break_exit(void)
{
	if(!count)
		return;
	count--;
	unregister_wide_hw_breakpoint(sample_hbp);
	printk(KERN_INFO "HW Breakpoint for imode uninstalled\n");
}


