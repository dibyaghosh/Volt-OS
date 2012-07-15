#ifndef common 
#define common 
typedef unsigned int u32int;
typedef signed int s32int;
typedef unsigned short u16int;
typedef signed short s16int;
typedef unsigned char u8int;
typedef signed char s8int;
typedef unsigned int size_t;

void outb(u16int port, u8int value);
u8int inb(u16int port);
u16int inw(u16int port);
char* fromdec(u32int n);
void open_memory_system();	

#endif
