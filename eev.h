#ifndef __eev_H
#define __eev_H
#include "include.h"
extern uchar InterTimes;
const uint8_t STEP[] ={0x08,0x0c,0x04,0x14,0x10,0x90,0x80,0x88};//PD2347:A-3 B-2 C-4 D-7
 int stepcount =0;
 int EEVSTEP=250;
extern void eevdriver();
void delay16ms(uchar time);
#endif