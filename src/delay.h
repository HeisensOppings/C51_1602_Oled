#ifndef __DELAY_H__
#define __DELAY_H__

#include<intrins.h>

#define uint unsigned int   //16  0-65535

#define on 0
#define off 1

sbit led1 = P1^0;
sbit led2 = P1^1;
sbit led3 = P1^2;
sbit led4 = P1^3;
sbit led5 = P1^4;
sbit led6 = P1^5;
sbit led7 = P1^6;
sbit led8 = P1^7;

void delay_xms(uint s);

void delay_xms(uint s)				
{
	uint i,j;
	for(i=s;i>0;i--)		      //i=xms¼´ÑÓÊ±Ô¼xmsºÁÃë
		for(j=112;j>0;j--);
}

#endif
