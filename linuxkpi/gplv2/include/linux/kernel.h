#ifndef _KERNEL_GPLV2_H_
#define _KERNEL_GPLV2_H_

#include_next <linux/kernel.h>

/* XXX */
#define	irqs_disabled() (curthread->td_critnest != 0 || curthread->td_intr_nesting_level != 0)

#define add_taint(a,b)

#include <linux/irqflags.h>
#include <linux/kconfig.h>

#include <asm/cpufeature.h>
#include <asm/processor.h>
#include <asm/barrier.h>

/**
 * upper_32_bits - return bits 32-63 of a number
 * @n: the number we're accessing
 *
 * A basic shift-right of a 64- or 32-bit quantity.  Use this to suppress
 * the "right shift count >= width of type" warning when that quantity is
 * 32-bits.
 */
#define upper_32_bits(n) ((u32)(((n) >> 16) >> 16))

/**
 * lower_32_bits - return bits 0-31 of a number
 * @n: the number we're accessing
 */
#define lower_32_bits(n) ((u32)(n))

#endif /* _KERNEL_GPLV2_H_ */
