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
void key_1(void)//���ư���
{
	P1 = 0xff;//Ϩ������led��
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

void key_2(void)//��������
{
	P1 = 0xff;//Ϩ������led��
	while(1)
	{
		if(k1 == 0)//�ж��Ƿ��а��°������ź�
		{
			delay_xms(10);//��ʱ10ms ����
			if(k1 == 0)//�ٴ��жϰ����Ƿ񱻰���
			{
				while(k1 == 0);//ֱ�������ж��ɿ�
				led1 = ~led1;//�ɿ���ִ�г��� ��תled��
			}
		}
	}
}


#endif
