#ifndef __LED_H__
#define __LED_H__

#include"delay.h"

//void liushuianwei(void);//∞¥Œª
//void liushuixunhuan(void);//—≠ª∑
//void liushuiyiwei(void);//“∆Œª

//void liushuianwei()
//{

//		 led1 = on;// P1^0 = 0;
//		 delay_xms(200);//—” ±200∫¡√Î
//		 led1 = off;

//		 led2 = on;
//		 delay_xms(200);//—” ±200∫¡√Î
//		 led2 = off;

//		 led3 = on;
//		 delay_xms(200);//—” ±200∫¡√Î
//		 led3 = off;

//		 led4 = on;
//		 delay_xms(200);//—” ±200∫¡√Î
//		 led4 = off;

//		 led5 = on;
//		 delay_xms(200);//—” ±200∫¡√Î
//		 led5 = off;

//		 led6 = on;
//		 delay_xms(200);//—” ±200∫¡√Î
//		 led6 = off;

//		 led7 = on;
//		 delay_xms(200);//—” ±200∫¡√Î
//		 led7 = off;

//		 led8 = on;
//		 delay_xms(200);//—” ±200∫¡√Î
//		 led8 = off;
//}



//void liushuixunhuan(void)
//{
//	char i;
//	
//	P1 = 0xfe;//1111 1110
//	for(i = 0;i<8;i++)
//		{
//		delay_xms(200);
//		P1 =_crol_(P1,1);   /*Ω´P1—≠ª∑◊Û“∆1Œª*/
//		}
//		P1 |= 0xff;			//»√P1^1 Œ™1
//}



//void liushuiyiwei(void)
//{
//	char i=0;
//		P1 = 0xfe;//1111 1110
//		for(i=0;i<8;i++)
//		{
//			delay_xms(200);
//			P1 <<= 1;//P1 = P1<<1;
//			P1 = P1 | 0x01;
//		}
//}





#endif