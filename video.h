#ifndef video_h
#define video_h

#include "common.h"

u32int x_cursor;
u32int y_cursor;
void monitor_clear();
static void scroll();
void put_char(char c);
void print(char *c);
void move_cursor();
void update_settings(u8int fgColor,u8int bgColor);
void type_write(char* c);
void relocate_cursor(u8int direction);
/*void charIn (u8int c);
char *getInput ();*/

#define UP 1
#define LEFT 2
#define RIGHT 3
#define DOWN 4

#endif
