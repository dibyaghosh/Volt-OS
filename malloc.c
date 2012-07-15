#include "malloc.h"

u32int location = 0x100000;

char *malloc(u16int size){
	u32int temp = location;
	location+=size;
	return (char *) temp;	
}
