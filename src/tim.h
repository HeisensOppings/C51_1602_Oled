#ifndef __TIM_H__
#define __TIM_H__

/*************************************************
*ʵ��������ʱ��ʵ��
*ʵ��Ч������һ��led���Զ�ʱ��0�趨��ʱ��������˸
*************************************************/

sbit led = P1^0;

void timer0_init()
{
	TMOD = 0x01; //��ʱ��0ѡ������ʽ1
    TH0 = 0x00;	 //���ó�ʼֵ
    TL0 = 0x00; 
    EA = 1;			 //�����ж�
    ET0 = 1;		 //�򿪶�ʱ��0�ж�
    TR0 = 1;		 //������ʱ��0
}

void tim_1()
{
	led = 1;
	timer0_init();
	while(1);
}

void timer0() interrupt 1
{
    TH0 = 0x00;	 //���ó�ʼֵ
    TL0 = 0x00; 
	led = ~led;
}

/*************************************************
*ʵ��������ʱ��ʵ��
*ʵ��Ч������һ��led����500msһ�εľ�ȷƵ����˸
*************************************************/


int i = 0;

void timer1_init()
{
	TMOD = 0x20; //��ʱ��0ѡ������ʽ1
    TH1 = 0x24;	 //���ó�ʼֵ����ʱ50ms
    TL1 = 0x24; 
    EA = 1;			 //�����ж�
    ET1 = 1;		 //�򿪶�ʱ��0�ж�
    TR1 = 1;		 //������ʱ��0
}

void tim_2()
{
	led = 1;
	timer1_init();//��ʱ��1�ĳ�ʼ��
	while(1)
	{
		if(i==5000)
		{
		  led = ~led;
		  i = 0; //ע��i��Ҫ��
		}
	}


}

void timer1() interrupt 3
{
//    TH1 = 0x4C;	 //���ó�ʼֵ����ʱ50ms
//    TL1 = 0x00;
	i++;
}

#endif