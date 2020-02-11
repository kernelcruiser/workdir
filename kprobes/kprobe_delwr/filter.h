#ifndef _FILTER_H_
#define _FILTER_H_
extern void hello(void);
extern int filter(struct pt_regs *regs);
extern int bio_filter(struct pt_regs *regs);
extern int direct_filter(struct pt_regs *regs);
extern int mmap_filter(struct pt_regs *regs);
extern int wb_filter(struct pt_regs *regs);
extern int dm_filter(struct pt_regs *regs);
extern int kmalloc_filter(struct pt_regs *regs);
extern int alloc_filter(struct pt_regs *regs, unsigned long s);
extern int test_init(void);
#endif
