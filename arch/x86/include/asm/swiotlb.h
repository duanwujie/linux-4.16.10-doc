/* SPDX-License-Identifier: GPL-2.0 */
#ifndef _ASM_X86_SWIOTLB_H
#define _ASM_X86_SWIOTLB_H

#include <linux/swiotlb.h>

#ifdef CONFIG_SWIOTLB
extern int swiotlb;
extern int __init pci_swiotlb_detect_override(void);
extern int __init pci_swiotlb_detect_4gb(void);
extern void __init pci_swiotlb_init(void);
extern void __init pci_swiotlb_late_init(void);
#else
#define swiotlb 0
static inline int pci_swiotlb_detect_override(void)
{
	return 0;
}
static inline int pci_swiotlb_detect_4gb(void)
{
	return 0;
}
static inline void pci_swiotlb_init(void)
{
}
static inline void pci_swiotlb_late_init(void)
{
}
#endif

extern void *x86_swiotlb_alloc_coherent(struct device *hwdev, size_t size,
					dma_addr_t *dma_handle, gfp_t flags,
					unsigned long attrs);
extern void x86_swiotlb_free_coherent(struct device *dev, size_t size,
					void *vaddr, dma_addr_t dma_addr,
					unsigned long attrs);

#endif /* _ASM_X86_SWIOTLB_H */
