// timer.c -- Initialises the PIT, and handles clock updates.
//            Written for JamesM's kernel development tutorials.

#include "timer.h"
#include "isr.h"
#include "video.h"

static void timer_callback (registers_t regs) {
	int i;	
	for(i=0;i<5;i++){	
	waitTime[i]--;
	if(waitTime[i]<0){
		waitFlag[i] = 1;
	}
	}
}

void init_timer (u32int frequency) {
    // Firstly, register our timer callback.
    register_interrupt_handler(IRQ0, &timer_callback);

    // The value we send to the PIT is the value to divide it's input clock
    // (1193180 Hz) by, to get our required frequency. Important to note is
    // that the divisor must be small enough to fit into 16-bits.
    u32int divisor = 1193180 / frequency;

    // Send the command byte.
    outb(0x43, 0x36);

    // Divisor has to be sent byte-wise, so split here into upper/lower bytes.
    u8int l = (u8int)(divisor & 0xFF);
    u8int h = (u8int)( (divisor>>8) & 0xFF );

    // Send the frequency divisor.
    outb(0x40, l);
    outb(0x40, h);
}
void delay (u32int time, u8int spot) {
  waitFlag[spot-1]=0;
  waitTime[spot-1]=time;
  while (!waitFlag[spot-1]){
    
  }
}
