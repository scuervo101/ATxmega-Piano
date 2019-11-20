
/*
 * USART_Drivers.c
 *
 * Created: 11/19/2019 8:27:18 PM
 *  Author: samue
 */ 

#include "USART_Drivers.h"

void USART_init(void)
{
	PORTD.OUTSET = PORTD_TX;		//Here we must set the direct and the default output for the transmit pin
	PORTD.DIRSET = PORTD_TX;		//
	
	PORTD.DIRCLR = PORTD_RX;		//Enable the pin for USART receive to input
	
	USARTD0.CTRLA = USART_RXCINTLVL_MED_gc;		//Turned the receive pin into a low level interrupt
	USARTD0.CTRLB = USART_RXEN_bm + USART_TXEN_bm;		//enable the receiver and transmitter
	USARTD0.CTRLC = USART_CMODE_ASYNCHRONOUS_gc + USART_PMODE_EVEN_gc + USART_CHSIZE_8BIT_gc;	//Frame options, asynchronous, even parity, 8-bit data
	USARTD0.BAUDCTRLA = (0xFF & BSel);					//Baud rate => bsel
	USARTD0.BAUDCTRLB = (0xF0 & BScale << 4) + (0x0F & BSel >> 8);			//Baud rate => bscale/ bsel
}