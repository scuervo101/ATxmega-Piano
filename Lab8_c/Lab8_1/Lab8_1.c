/*
 * Lab8_1.c
 *
 * Created: 11/17/2019 9:15:55 PM
 * Author : samue
 */ 

#include <avr/io.h>
#include "DAC_Drivers.h"

extern void Clock_init(void);

int main(void)
{
	Clock_init();
	DAC_init();
	
	//PORTC.DIRSET = PIN7_bm;
	//PORTCFG.CLKEVOUT = 0x01;
	
	DACA.CH1DATA = 0x687;
	
    while (1) 
    {
    }
}

