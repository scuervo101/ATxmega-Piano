/*
 * Lab8_2.c
 *
 * Created: 11/18/2019 3:03:16 PM
 * Author : samue
 */ 

#include <avr/io.h>
#include <avr/interrupt.h>
#include "DAC_Drivers.h"
#include "TC_Drivers.h"
#include "Wave_LUT.h"

volatile uint8_t table_cnt = 0;

extern void Clock_init(void);

void Interrupt_init(void)
{
	PMIC.CTRL |= PMIC_LOLVLEN_bm;
	
	sei();
}

int main(void)
{
	Clock_init();
	Interrupt_init();
	DAC_init();
	TC_init();
	
	
	//uint16_t data = wave[255];
	
    /* Replace with your application code */
    while (1) 
    {
		//while(!(DACA.STATUS & DAC_CH1DRE_bm));
		DACA.CH1DATA = wave[table_cnt];
    }
}

ISR(TCC0_OVF_vect)
{
	//while(!(DACA.STATUS & DAC_CH1DRE_bm));
	//DACA.CH1DATA = wave[table_cnt];
	table_cnt++;
}

