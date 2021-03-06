#include "common.h"
#include "keyboard.h"
#include "isr.h"
#include "video.h"
#include "timer.h"
#include "std/ctype.h"
#include "std/string.h"

u8int keyboard[] = {
  27, '1', '2', '3', '4', '5', '6', '7', '8', '9', '0',  '-', '=', '\b',
   '\t', 'q', 'w', 'e', 'r', 't', 'y', 'u', 'i', 'o', 'p',  '[', ']', '\n', 0,
         'a', 's', 'd', 'f', 'g', 'h', 'j', 'k', 'l', ';', '\'', '`',    253,
        '\\', 'z', 'x', 'c', 'v', 'b', 'n', 'm', ',', '.',  '/', 253,  '*',
           0, ' ', 254,   0,   0,   0/*60*/,   0,   0,   0,   0,    0,   0,    0,
           0,   0,   0, 245/*71*/,   0, '-', 246,   0, 247, '+',    0,   248,    0,
           0,   0,   0,   0,   0,   0,   0,   0,
};
u8int typeEnabled  = 0;
u8int caps = 0;
u8int shiftKey = 0;

s8int keyboardFlag=0;
char input='\0';
static void keyboard_callback (registers_t regs) {
	static unsigned char scancode;

	/*
	 Read keyboard status
	*/
	u8int modChar;
	scancode = inb (0x60);
	scancode--;
	if ((scancode & 0x80) && (keyboard[scancode-128]==253)) {
		caps = !caps;
		shiftKey = !shiftKey;
		return;
	}
	if ((scancode & 0x80))
		return;
	if (keyboard[scancode] == 254) {
		caps = !caps;
		return;
	}
	if (keyboard[scancode] == 253) {
		caps = !caps;
		shiftKey = !shiftKey;
		return;
	}
	if (keyboard[scancode]>=245 && keyboard[scancode]<=248) {
		relocate_cursor(keyboard[scancode]-244);
		return;
	}
	modChar = keyboard[scancode];
	if (caps)
		modChar = toupper(modChar);
	if (shiftKey)
		modChar = numToSymbol(modChar);
	input = modChar;
	keyboardFlag = 1;
	put_char(modChar);
}

void init_keyboard () {
    // Firstly, register our timer callback.
    register_interrupt_handler(IRQ1, &keyboard_callback);
}

u8int numToSymbol (u8int n) {
	if (n=='1')
		return '!';
	else if (n=='2')
		return '@';
	else if (n=='3')
		return '#';
	else if (n=='4')
		return '$';
	else if (n=='5')
		return '%';
	else if (n=='6')
		return '^';
	else if (n=='7')
		return '&';
	else if (n=='8')
		return '*';
	else if (n=='9')
		return '(';
	else if (n=='0')
		return ')';
	else if (n=='-')
		return '_';
	else if (n=='=')
		return '+';
	else if (n=='[')
		return '{';
	else if (n==']')
		return '}';
	else if (n=='\\')
		return '|';
	else if (n==',')
		return '<';
	else if (n=='.')
		return '>';
	else if (n=='/')
		return '?';
	else if (n=='`')
		return '~';
	else if (n==';')
		return ':';
	else if (n=='\'')
		return '"';
	return n;
}

char getfromstdin(){
	char chara = '\0';
	if (keyboardFlag == 1) {
		keyboardFlag = 0;
		chara = input;
	}
	input='\0';
	return chara;
}
