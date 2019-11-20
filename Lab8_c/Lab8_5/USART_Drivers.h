
/*
 * UASRT_Driver.h
 *
 * Created: 11/19/2019 8:26:20 PM
 *  Author: samue
 */ 

#include <avr/io.h>

#define BSel 117
#define BScale -3

#define PORTD_TX PIN3_bm
#define PORTD_RX PIN2_bm

#define carriage_feed 0x0d
#define line_feed 0x0a

void USART_init(void);