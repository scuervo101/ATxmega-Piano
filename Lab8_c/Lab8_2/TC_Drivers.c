/*
 * TC_Drivers.c
 *
 * Created: 11/18/2019 9:43:01 PM
 *  Author: samue
 */ 

#include "TC_Drivers.h"
#include <avr/io.h>

void TC_init(void)
{
	TCC0.CNT = 0x00;
	TCC0.PER = 0x007F;
	TCC0.INTCTRLA = (0x01);
	
	TCC0.CTRLA = TC_CLKSEL_DIV1_gc;
}