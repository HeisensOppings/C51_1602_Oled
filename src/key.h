#ifndef __KEY_H__
#define __KEY_H__


sbit k5 = P3^3;

sbit k1 = P3^4;
sbit k2 = P3^5;
sbit k3 = P3^6;
sbit k4 = P3^7;

void key_1(void);
void key_2(void)
;
void key_1(void)//两灯按键
{
	P1 = 0xff;//熄灭所有led灯
	while(1)
	{
	led1 = k1;
	led2 = k1;
	led3 = k2;
	led4 = k2;
	led5 = k3;	
	led6 = k3;
	led7 = k4;
	led8 = k4;
	}
}

void key_2(void)//消抖按键
{
	P1 = 0xff;//熄灭所有led灯
	while(1)
	{
		if(k1 == 0)//判断是否有按下按键的信号
		{
			delay_xms(10);//延时10ms 消抖
			if(k1 == 0)//再次判断按键是否被按下
			{
				while(k1 == 0);//直到按键判断松开
				led1 = ~led1;//松开后执行程序 翻转led灯
			}
		}
	}
}


#endif
