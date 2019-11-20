/*
 * DMA_Drivers.c
 *
 * Created: 11/17/2019 9:18:28 PM
 *  Author: samue
 */ 

#include "DAC_Drivers.h"

void DAC_init(void)
{
	//DAC Init function will enable the DAC to send a 1V voltage signal
	
	PORTA.DIRSET = PIN3_bm;
	
	DACA.CTRLA = DAC_CH1EN_bm + DAC_ENABLE_bm;
	DACA.CTRLB = (0x01 << DAC_CHSEL_gp);
	DACA.CTRLC = (0x03 << DAC_REFSEL_gp);
}