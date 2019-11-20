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
#include "USART_Drivers.h"

volatile uint8_t table_cnt = 0;
volatile uint8_t cnt = 0;

volatile uint8_t received;

volatile uint8_t tgl_Flag = 0;
volatile uint8_t chg_Flag = 0;



extern void Clock_init(void);

void Interrupt_init(void)
{
	PMIC.CTRL |= PMIC_MEDLVLEN_bm + PMIC_LOLVLEN_bm;
	
	sei();
}

int main(void)
{
	PORTC.OUTSET = PIN7_bm;
	PORTC.DIRSET = PIN7_bm;
	
	Clock_init();
	DAC_init();
	DMA_init(wave, (uint16_t)sizeof(wave));
	USART_init();
	Interrupt_init();
	TC_init();
	
    /* Replace with your application code */
    while (1) 
    {
		//TC_Disable();
    }
}

ISR(TCE0_OVF_vect)
{
	if(chg_Flag == 1)
		chg_Flag = 0;
	else
	{
		TC_Disable();
		//DACA.CH1DATA = 0x0000;
	}
}

ISR(USARTD0_RXC_vect)
{
	received = USARTD0.DATA;
	USARTD0.DATA = received;
	
	key_TC(received);
	chg_Flag = 1;
		
	if(received == 0x73)
	{
		if(!tgl_Flag)
		{
			DMA_init(triangle, (uint16_t)sizeof(triangle));
			tgl_Flag = 1;
		}
		else
		{
			DMA_init(wave, (uint16_t)sizeof(wave));
			tgl_Flag = 0;
		}
	}
}