#include "video.h"
#include "common.h"
#include "colors.h"
#include "malloc.h"
#include "std/ctype.h"
#include "std/stdio.h"
#include "isr.h"
#include "descriptor_tables.h"
#include "timer.h"
#include "keyboard.h"

int main(struct multiboot *mboot_ptr)
{
	// All our initialisation calls will go in here.
	update_settings(WHITE,BLACK);
	monitor_clear();
	init_descriptor_tables();
	asm("sti");
	init_keyboard();
	init_timer(1000);
	type_write("Hello guys! This is Dibya Type_Writing!\n");
	type_write("Welcome to Volt OS!\n Just start typing!\n");
	type_write("Volt OS version 0.1.0 copyright Dibya Jyoti Ghosh\n");
	while (1) {}
	return 0;
}
