#ifndef __LED_H__
#define __LED_H__

#include"delay.h"

//void liushuianwei(void);//��λ
//void liushuixunhuan(void);//ѭ��
//void liushuiyiwei(void);//��λ

//void liushuianwei()
//{

//		 led1 = on;// P1^0 = 0;
//		 delay_xms(200);//��ʱ200����
//		 led1 = off;

//		 led2 = on;
//		 delay_xms(200);//��ʱ200����
//		 led2 = off;

//		 led3 = on;
//		 delay_xms(200);//��ʱ200����
//		 led3 = off;

//		 led4 = on;
//		 delay_xms(200);//��ʱ200����
//		 led4 = off;

//		 led5 = on;
//		 delay_xms(200);//��ʱ200����
//		 led5 = off;

//		 led6 = on;
//		 delay_xms(200);//��ʱ200����
//		 led6 = off;

//		 led7 = on;
//		 delay_xms(200);//��ʱ200����
//		 led7 = off;

//		 led8 = on;
//		 delay_xms(200);//��ʱ200����
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
//		P1 =_crol_(P1,1);   /*��P1ѭ������1λ*/
//		}
//		P1 |= 0xff;			//��P1^1 Ϊ1
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