/*
 * TC_Drivers.c
 *
 * Created: 11/18/2019 9:43:01 PM
 *  Author: samue
 */ 

#include "TC_Drivers.h"

void TC_init(void)
{
	EVSYS.CH0MUX = EVSYS_CHMUX_TCC0_OVF_gc;
	
	TCE0.CNT = 0x00;
	TCE0.PER = 0xC350;
	TCE0.INTCTRLA = TC_OVFINTLVL_LO_gc;
	
	TCE0.CTRLA = TC_CLKSEL_DIV64_gc;
}

void TC_Disable(void)
{
	TCC0.CTRLA = TC_CLKSEL_OFF_gc;
}

void key_TC(uint8_t key)
{
	TCC0.CNT = 0x00;
	if(key == 0x77)								//C key
	{
		TCC0.PER = 0x007A;
		TCC0.CTRLA = TC_CLKSEL_DIV1_gc;
	}								
	
	else if(key == 0x33)						//CD key
	{
		TCC0.PER = 0x0073;
		TCC0.CTRLA = TC_CLKSEL_DIV1_gc;
	}
	else if(key == 0x65)						//D key
	{
		TCC0.PER = 0x006C;
		TCC0.CTRLA = TC_CLKSEL_DIV1_gc;
	}
	else if(key == 0x34)						//DE key
	{
		TCC0.PER = 0x0066;
		TCC0.CTRLA = TC_CLKSEL_DIV1_gc;
	}
	else if(key == 0x72)						//E key
	{
		TCC0.PER = 0x0060;
		TCC0.CTRLA = TC_CLKSEL_DIV1_gc;
	}
	else if(key == 0x74)						//F key
	{
		TCC0.PER = 0x005B;
		TCC0.CTRLA = TC_CLKSEL_DIV1_gc;
	}
	else if(key == 0x36)						//FG key
	{
		TCC0.PER = 0x0056;
		TCC0.CTRLA = TC_CLKSEL_DIV1_gc;
	}
	else if(key == 0x79)						//G key
	{
		TCC0.PER = 0x0051;
		TCC0.CTRLA = TC_CLKSEL_DIV1_gc;
	}
	else if(key == 0x37)						//GA key
	{
		TCC0.PER = 0x004C;
		TCC0.CTRLA = TC_CLKSEL_DIV1_gc;
	}
	else if(key == 0x75)						//A key
	{
		TCC0.PER = 0x0048;
		TCC0.CTRLA = TC_CLKSEL_DIV1_gc;
	}
	else if(key == 0x38)						//AB key
	{
		TCC0.PER = 0x0044;
		TCC0.CTRLA = TC_CLKSEL_DIV1_gc;
	}	
	else if(key == 0x69)						//B key
	{
		TCC0.PER = 0x0040;	
		TCC0.CTRLA = TC_CLKSEL_DIV1_gc;
	}
		
		
	
}