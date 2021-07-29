#ifndef __ZHONGDUAN_H__
#define __ZHONGDUAN_H__

//（低电平触发）给P3.2低电平触发中断，让led灯，在触发前后四位状态调换
//（下降沿触发）按下按键触发P3.3下降沿，让led灯，在触发前后四位状态调换

#include<reg52.h>


void zhongduan_1()//电平触发
{
	P1 = 0x0f;// 0000 1111 下面四个灯亮 上面四个灯灭
	EX0 = 1;//INT0中断允许
	EA = 1;//全局中断打开
	IT0 = 0;//触发方式为低电平触发
		
	while(1);
}

void low() interrupt 0  //外部中断编号
{
	P1 = ~P1;             //led亮灭反转
}

/*******************************************/

void zhongduan_2()     //下降沿触发
{
	P1 = 0x0f;           // 0000 1111 下面四个灯亮 上面四个灯灭
	EX1 = 1;             //INT1中断允许
	EA = 1;              //全局中断打开
	IT1 = 1;             //触发方式为下降沿触发
	while(1);

}


void jump_low()	 interrupt 2    //外部中断编号
{
	P1 = ~P1;                     //led亮灭反转
}


#endif