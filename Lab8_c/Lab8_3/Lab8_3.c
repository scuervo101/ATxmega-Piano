/*
 * Lab8_2.c
 *
 * Created: 11/18/2019 3:03:16 PM
 * Author : samue
 */ 

#include <avr/io.h>
#include <avr/interrupt.h>
#include "DAC_Drivers.h"
#include "DMA_Drivers.h"
#include "TC_Drivers.h"
#include "Wave_LUT.h"

volatile uint8_t table_cnt = 0;
volatile uint8_t cnt = 0;

extern void Clock_init(void);

int main(void)
{
	Clock_init();
	DAC_init();
	DMA_init(wave, (uint16_t)sizeof(wave));
	TC_init();
	
    /* Replace with your application code */
    while (1) 
    {
    }
}