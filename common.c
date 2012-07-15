// common.c -- Defines some global functions.
//             From JamesM's kernel development tutorials.

#include "common.h"

// Write a byte out to the specified port.
void outb(u16int port, u8int value)
{
    asm volatile ("outb %1, %0" : : "dN" (port), "a" (value));
}

u8int inb(u16int port)
{
    u8int ret;
    asm volatile("inb %1, %0" : "=a" (ret) : "dN" (port));
    return ret;
}

u16int inw(u16int port)
{
    u16int ret;
    asm volatile ("inw %1, %0" : "=a" (ret) : "dN" (port));
    return ret;
}



char* fromdec(u32int n) {
	if (n == 0) {
		return "0";
	}
	char c[32];
	int i=0;
	while (n>=1){ //189
		c[i++] = '0'+n%10;
		n /= 10;	
	}
	char *c2 = (char *) malloc(i);
	int j=0;
	i--;
	while (i>=0){
		c2[j++]=c[i--];
	}
	return c2;
}

void open_memory_system(){} 
