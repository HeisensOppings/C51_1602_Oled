#ifndef __SHUMAGUAN_H__
#define __SHUMAGUAN_H__

#include"delay.h"

#define duan P0

#define uchar unsigned char

sbit wei1 = P2^4;//�����һλ�����
sbit wei2 = P2^5;//����ڶ�λ�����
sbit wei3 = P2^6;//�������λ�����
sbit wei4 = P2^7;//�������λ�����

uchar code sz[17]={0x3f , 0x06 , 0x5b ,0x4f , 0x66 , 0x6d ,0x7d ,0x07 , 0x7f , 0x6f ,0x77 , 0x7c , 0x39 , 0x5e , 0x79 , 0x71 , 0x00};

void shumaguanj(void);//��̬��ʾ  Ч��b

void shumaguand1(void);//��̬��ʾ Ч��4321

void shuamguand2(void);//��̬��ʾ ����ʾ4321

void shumaguanj(void)
{
	wei1 = 1;
	wei2 = 0;
	wei3 = 0;
	wei4 = 0;
	duan = 0x7c;//0111 1100 "b"
	while(1);
}


void shumaguand1(void)
{
	   while(1)
	   {
	   		duan = sz[4];
			wei1 = 0;
			wei2 = 0;
			wei3 = 0;
			wei4 = 1;
			delay_xms(1000);
			duan = sz[3];
			wei1 = 0;
			wei2 = 0;
			wei3 = 1;
			wei4 = 0;
			delay_xms(1000);
			duan = sz[2];
			wei1 = 0;
			wei2 = 1;
			wei3 = 0;
			wei4 = 0;
			delay_xms(1000);
			duan = sz[1];
			wei1 = 1;
			wei2 = 0;
			wei3 = 0;
			wei4 = 0;
			delay_xms(1000);
	   }
}

void shuamguand2(void)
{
	   while(1)
	   {
	   	duan = sz[4];
			wei1 = 0;
			wei2 = 0;
			wei3 = 0;
			wei4 = 1;
			delay_xms(5);
			duan = sz[3];
			wei1 = 0;
			wei2 = 0;
			wei3 = 1;
			wei4 = 0;
			delay_xms(5);
			duan = sz[2];
			wei1 = 0;
			wei2 = 1;
			wei3 = 0;
			wei4 = 0;
			delay_xms(5);
			duan = sz[1];
			wei1 = 1;
			wei2 = 0;
			wei3 = 0;
			wei4 = 0;
			delay_xms(5);
	   }
}


#endif
