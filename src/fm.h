#ifndef __FM_H__
#define __FM_H__

#include"delay.h"

#define on 0
#define off 1
sbit fm = P2^3;

void fm_1(void);

void fm_deng(void);

void fm_1(void)
{
	while(1)
	{
		fm = on;//P2^3 = 0;·äÃùÆ÷Ïì
		delay_xms(100);
		fm = off;
		delay_xms(100);
	}
}

void fm_deng(void)
{
	P1 = 0xfe;//1111 1110
	while(1)
	{
		delay_xms(100);
		P1 =_crol_(P1,1);/*½«P1Ñ­»·×óÒÆ1Î»*/
		fm = on;
		delay_xms(100);
		fm = off;
	}
}


#endif
