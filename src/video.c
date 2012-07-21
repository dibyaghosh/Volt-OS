#include "video.h"
#include "std/stdlib.h"

u32int x_cursor = 0;
u32int y_cursor = 0;
u8int colorbyte;
u16int* mem = (u16int*) 0xB8000;
u16int cursor_location = 0;

void monitor_clear()
{
	u16int space = 0x20 | (colorbyte<<8);
	int i;
	for (i=0;i<0x7D0;i++)
	{
		*(mem+i) = space;
	}
	x_cursor = 0;
   	y_cursor = 0;
	move_cursor();
}
static void scroll()
{
	int i;
	for (i=80;i<0x780;i++)
	{
		*(mem+i-80) = *(mem+i);
	}
	u16int space = 0x20| (colorbyte<<8);
	for (i=0x730;i<0x780;i++)
	{
		*(mem+i) = space;
	}
	x_cursor = 0;
	y_cursor = 23;
	move_cursor();
}
void put_char(char c)
{
	if (c == '\n'){
		x_cursor=0;
		y_cursor++;
	}
	else if (c=='\r'){
		x_cursor=0;
	}
	else if (c=='\b' && x_cursor){
		x_cursor--;
		put_char(' ');
		x_cursor--;
	}
	else if (c=='\t'){
		x_cursor += 8 - x_cursor%8;
	}
	else if (c >= 32) {
		u16int cs = ((u16int) c) | (((u16int) colorbyte)<<8);
		*(mem+cursor_location) = cs;
		x_cursor++;
	}
	if (x_cursor>=80){
		x_cursor=0;
		y_cursor++;
	}
	if (y_cursor>=24){
		scroll();
	}
	move_cursor();
}
void print(char *c)
{
	int i = 0;
	while (c[i])
		put_char(c[i++]);
}
void print2(char *c1, char *c2) { print(c1); print(c2); }
void print3(char *c1, char *c2, char *c3) { print(c1); print(c2); print(c3); }
void print4(char *c1, char *c2, char *c3, char *c4) { print(c1); print(c2); print(c3); print(c4); }
void print5(char *c1, char *c2, char *c3, char *c4, char *c5) { print(c1); print(c2); print(c3); print(c4); print(c5); }
void move_cursor()
{
	cursor_location = y_cursor*80 + x_cursor;
	outb(0x3D4, 14);
	outb(0x3D5, cursor_location>>8);
	outb(0x3D4, 15);
	outb(0x3D5, cursor_location);
}

void update_settings(u8int fgColor, u8int bgColor)
{
	colorbyte = (bgColor<<4) | (fgColor & 15);
}

void type_write(char* c){
	int i = 0;
	while (c[i])
	{
		put_char(c[i++]);
		delay(50,5);
	}
}
void relocate_cursor(u8int direction) {
	if (direction==UP && y_cursor>0)
		y_cursor--;
	if (direction==DOWN && y_cursor<23)
		y_cursor++;
	if (direction==LEFT && x_cursor>0)
		x_cursor--;
	if (direction==RIGHT && x_cursor<79)
		x_cursor++;
	move_cursor();
}
