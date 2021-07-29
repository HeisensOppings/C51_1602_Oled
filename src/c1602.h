#ifndef __C1602_H__
#define __C1602_H__

#include<reg52.h>
 
#include <string.h>						  //strlenͷ�ļ�
 
//Ϊ����ͬλ���������Ͷ����Զ������
 
#define uint8    unsigned char
 
#define uint16   unsigned short int
 
#define uint32   unsigned long int
 
#define int8     signed char
 
#define int16    signed short int
 
#define int32    signed long int
 
#define uint64   unsigned long long int
 
#define int64    signed long long int
 
//����1602��һЩ���õ�ָ����㲻ͬ�Ķ��߿��Ը����Լ����޸�
 
#define SETMODE   0x38          //16*2��ʾ,5*7����,8λ���ݽӿ�
 
#define DISOPEN   0x0C          //��ʾ��,����ʾ���,��겻��˸
 
#define DISMODE   0x06          //��д�ַ����ַ��1,���Բ��ƶ�
 
#define SETADDR   0x80          //�������ݵ�ַָ���ʼֵ
 
#define CLEAR     0x01          //����,����ָ������
 
#define RET       0x02          //�س�,����ָ������ 
 
#define PORT      P0            //I/O�� 
 
sbit RS = P1^0;
 
sbit E = P2^5; 
 
sbit dula = P2^6;
 
sbit wela = P2^7;

void delay(uint16 time);
 
void Write1602_Com(uint8 com);
 
void Write1602_Dat(uint8 dat);
 
void Init1602(void);
 
void Write1602_Str(uint8 addr,uint8 length,uint8 *pbuf);
 
uint8 code xin[8]={									 //����ģ
0x00,0x1B,0x1F,0x1F,0x1F,0x0E,0x04,0x00
};
 
uint8 code hot[8]={                                  //�����¶���ģ
 
0x10,0x06,0x09,0x08,0x08,0x09,0x06,0x00
 
};
 
uint8 code zuo[8]={									 //�����󲿷���ģ
0x00,0x02,0x01,0x02,0x01,0x01,0x02,0x00
};
 
uint8 code you[8]={									 //�����Ҳ�����ģ
0x00,0x1e,0x12,0x0c,0x0a,0x11,0x00,0x00		            
};
 
uint8 i; 
 
void real()
 
{
 
    Init1602();                                      //��ʼ��1602 
 
    //�Զ���CGRAM
 
    Write1602_Str(0x40,8,hot);                                           //�����±�->CGRAM���ڴ�000��
    Write1602_Str(0x48,8,zuo);						 //�����󲿷�->CGRAM���ڴ�001��
    Write1602_Str(0x50,8,you);						 //�����Ҳ���->CGRAM���ڴ�010��
    Write1602_Str(0x58,8,xin);						 //��->CGRAM���ڴ�011��
    Write1602_Com(0x80); 
    							 //����DDRAM��ַ������ʾ��λ��
    for(i=0;i<8;i++)
       Write1602_Dat(0);
	for(i=0;i<8;i++)
       Write1602_Dat(3);
    Write1602_Com(0xc0);                             //ͬ��
    for(i=0;i<16;i++)
       Write1602_Dat(1+i%2);
    while(1);
} 
void delay(uint16 time)
{
    uint8 i,j;
	for(i=time;i>0;i--)
		for(j=0;j<110;j++);
} 

void Init1602(void) 
{
	dula=0;					   //�ر����ݹܵ���ʾ����Ϊ�ҵ�51��Ӧ�������ݹܵ�����
	wela=0;					   //������Ҫ�������������ر�Ӱ��
    Write1602_Com(SETMODE);     //ģʽ����
    delay(5);
 
    Write1602_Com(DISOPEN);     //��ʾ����
 
    delay(5);
 
    Write1602_Com(DISMODE);     //��ʾģʽ
 
    delay(5);
 
    Write1602_Com(CLEAR);       //����
 
    delay(5);
 
} 
 
void Write1602_Dat(uint8 dat)
 
{
 
    E=0;
 
    RS=1;                    //����
 
    delay(5);               //��ʱ
 
    PORT=dat;                //�˿ڸ�ֵ
 
    delay(5);
 
    E=1;                     //������
 
    delay(5);
 
    E=0;
 
} 
 
void Write1602_Com(uint8 com)
{
    E=0;
    RS=0;                    //����
    delay(5);               //��ʱ
    PORT=com;                //�˿ڸ�ֵ
    delay(5);
    E=1;                     //������
    delay(5);
    E=0;
}
 
void Write1602_Str(uint8 addr,uint8 length,uint8 *pbuf) 
{ 
    uint8 i; 
    Write1602_Com(addr); 
    for(i=0;i<length;i++)
    { 
       Write1602_Dat(pbuf[i]);
    }
} 
#endif