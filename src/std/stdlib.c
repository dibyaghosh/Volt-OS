#include "stdlib.h"

u32int location = 0x200000;

void *malloc (size_t size)
{
  u32int temp = location;
  location += size;
  return (void *) temp;	
}
void *calloc (size_t num, size_t size)
{
  u32int temp = location;
  u8int *pointer = (u8int *) temp;
  u32int i = num * size;
  location += i;
  while (i > 0) {
    *(pointer + (i--)) = 0;
  }
  return (void *) temp;
}
u32int kmalloc_all (size_t size, s32int align, u32int *phys)
{
  if (align==1 && (location & 0xFFFFF000)) {
    location &= 0xFFFFF000;
    location += 0x1000;
  }
  if (phys)
  {
    *phys = location;
  }
  u32int temp = location;
  location += size;
  return temp;
}
u32int kmalloc_a (size_t size, u32int *phys)
{
  return kmalloc_all(size,1,phys);
}
u32int kmalloc_p (size_t size, u32int *phys)
{
  kmalloc_all(size,0,phys);
  return (u32int) phys;
}
u32int kmalloc_ap (size_t size, u32int *phys)
{
  kmalloc_all(size,1,phys);
  return (u32int) phys;
}
u32int kmalloc (size_t size)
{
  u32int *phys;
  return kmalloc_all(size,0,phys);
}
