/*
 * DMA_Drivers.c
 *
 * Created: 11/19/2019 1:43:50 AM
 *  Author: samue
 */ 
#include "DMA_Drivers.h"

void DMA_init(uint16_t source[], uint16_t length)
{
	DMA.CTRL |= DMA_RESET_bm;
	
	DMA.CH0.CTRLA = DMA_CH_SINGLE_bm + DMA_CH_REPEAT_bm + DMA_CH_BURSTLEN_2BYTE_gc;
	
	DMA.CH0.ADDRCTRL = DMA_CH_SRCRELOAD_BLOCK_gc + DMA_CH_SRCDIR_INC_gc + 
						DMA_CH_DESTRELOAD_BURST_gc + DMA_CH_DESTDIR_INC_gc;
						
	DMA.CH0.TRIGSRC =  DMA_CH_TRIGSRC_EVSYS_CH0_gc;
	
	DMA.CH0.TRFCNT = length;
	DMA.CH0.REPCNT = 0x00;
	
	DMA.CH0.SRCADDR0 = (uint8_t)((uint32_t)((uintptr_t) source));
	DMA.CH0.SRCADDR1 = (uint8_t)((uint32_t)((uintptr_t) source) >> 8);
	DMA.CH0.SRCADDR2 = (uint8_t)((uint32_t)((uintptr_t) source) >> 16);
	
	DMA.CH0.DESTADDR0 = (uint8_t)((uint32_t)((uintptr_t) &DACA.CH1DATAL));
	DMA.CH0.DESTADDR1 = (uint8_t)((uint32_t)((uintptr_t) &DACA.CH1DATAL) >> 8);
	DMA.CH0.DESTADDR2 = (uint8_t)((uint32_t)((uintptr_t) &DACA.CH1DATAL) >> 16);
	
	//DMA.CH0.CTRLB |= DMA_CH_TRNINTLVL_LO_gc;
	
	DMA.CH0.CTRLA |= DMA_CH_ENABLE_bm;
	DMA.CTRL |= DMA_ENABLE_bm;
}