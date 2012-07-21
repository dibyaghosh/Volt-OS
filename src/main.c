#include "video.h"
#include "common.h"
#include "colors.h"
#include "std/stdlib.h"
#include "std/ctype.h"
#include "std/stdio.h"
#include "isr.h"
#include "descriptor_tables.h"
#include "timer.h"
#include "keyboard.h"

void initialize(u32int fg, u32int bg) {
	// Initialization calls
	update_settings(fg,bg);
	monitor_clear();
	init_descriptor_tables();
	asm("sti");
	init_keyboard();
	init_timer(1000);
}

int main(struct multiboot *mboot_ptr)
{
	initialize(WHITE,BLACK);
	print("What's your name? ");
	char *name = malloc(80);
	gets(name);
	print3("Hello, ",name,"!\n");
	gets(name);
	monitor_clear();
	print("I'm COMPUTER!");
	while (1) {}
	return 0;
}
