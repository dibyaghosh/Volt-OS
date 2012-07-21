// timer.h -- Defines the interface for all PIT-related functions.
//            Written for JamesM's kernel development tutorials.

#ifndef TIMER_H
#define TIMER_H

#include "common.h"

void init_timer (u32int frequency);
void delay (u32int time, u8int spot);
s32int waitTime[5];
u32int waitFlag[5];

#endif
