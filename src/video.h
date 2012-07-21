#ifndef VIDEO_H
#define VIDEO_H

#include "common.h"

// Cursor position
u32int x_cursor;
u32int y_cursor;
// Display methods
void monitor_clear ();
static void scroll ();
// Output methods
void put_char (char c);
void print (char *c);
void print2 (char *c1, char *c2);
void print3 (char *c1, char *c2, char *c3);
void print4 (char *c1, char *c2, char *c3, char *c4);
void print5 (char *c1, char *c2, char *c3, char *c4, char *c5);
void move_cursor ();
void update_settings (u8int fgColor,u8int bgColor);
void type_write (char* c);
void relocate_cursor (u8int direction);

#define UP 1
#define LEFT 2
#define RIGHT 3
#define DOWN 4

#endif
