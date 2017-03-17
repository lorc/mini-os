/*
 * traps.c
 */

#include <mini-os/os.h>
#include <mini-os/traps.h>
#include <console.h>

extern void (*IRQ_handler)(void);

/*
 * TODO
 */
void stack_walk(void)
{
    xprintk("stack walk\n");
    while(1);
}

/*
 * TODO
 */
void do_bad_mode (struct pt_regs *regs, int reason)
{
	BUG();
}

void do_irq (struct pt_regs *regs)
{
    if (IRQ_handler)
	IRQ_handler();
}

/*
 * TODO
 */
void do_sync (struct pt_regs *regs)
{
    uint64_t esr, far;
    xprintk("*** Sync exception at PC = %lx *** \n", regs->pc);
    xprintk("Thread state:\n");
    xprintk("\tX0  = 0x%016lx X1  = 0x%016lx\n", regs->x0, regs->x1);
    xprintk("\tX2  = 0x%016lx X3  = 0x%016lx\n", regs->x2, regs->x3);
    xprintk("\tX4  = 0x%016lx X5  = 0x%016lx\n", regs->x4, regs->x5);
    xprintk("\tX6  = 0x%016lx X7  = 0x%016lx\n", regs->x6, regs->x7);
    xprintk("\tX8  = 0x%016lx X9  = 0x%016lx\n", regs->x8, regs->x9);
    xprintk("\tX10 = 0x%016lx X11 = 0x%016lx\n", regs->x10, regs->x11);
    xprintk("\tX12 = 0x%016lx X13 = 0x%016lx\n", regs->x12, regs->x13);
    xprintk("\tX14 = 0x%016lx X15 = 0x%016lx\n", regs->x14, regs->x15);
    xprintk("\tX16 = 0x%016lx X17 = 0x%016lx\n", regs->x16, regs->x17);
    xprintk("\tX18 = 0x%016lx X19 = 0x%016lx\n", regs->x18, regs->x19);
    xprintk("\tX20 = 0x%016lx X21 = 0x%016lx\n", regs->x20, regs->x21);
    xprintk("\tX22 = 0x%016lx X23 = 0x%016lx\n", regs->x22, regs->x23);
    xprintk("\tX24 = 0x%016lx X25 = 0x%016lx\n", regs->x24, regs->x25);
    xprintk("\tX26 = 0x%016lx X27 = 0x%016lx\n", regs->x26, regs->x27);
    xprintk("\tX28 = 0x%016lx X29 = 0x%016lx\n", regs->x28, regs->x19);
    xprintk("\tX30 (lr) = 0x%016lx\n", regs->lr);
    xprintk("\tsp  = 0x%016lx\n", regs->sp);
    xprintk("\tpstate  = 0x%016lx\n", regs->pstate);

    __asm__ __volatile__("mrs %0, esr_el1":"=r"(esr));
    __asm__ __volatile__("mrs %0, far_el1":"=r"(far));
    xprintk("\tesr_el1 = %08lx\n", esr);
    xprintk("\tfar_el1 = %08lx\n", far);
    while(1);
}

/*
 * TODO: need implementation.
 */
void trap_init(void)
{
}

/*
 * TODO
 */
void trap_fini(void)
{
}
