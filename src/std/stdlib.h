#ifndef STDLIB_H
#define STDLIB_H

#include "../common.h"

void *malloc (size_t size);
void *calloc (size_t num, size_t size);
u32int kmalloc_all (size_t size, s32int align, u32int *phys);
u32int kmalloc_a (size_t size, u32int *phys);
u32int kmalloc_p (size_t size, u32int *phys);
u32int kmalloc_ap (size_t size, u32int *phys);
u32int kmalloc (size_t size);

#endif
