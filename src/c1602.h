#ifndef __C1602_H__
#define __C1602_H__

#include<reg52.h>
 
#include <string.h>						  //strlen头文件
 
//为各不同位数变量类型定义自定义符号
 
#define uint8    unsigned char
 
#define uint16   unsigned short int
 
#define uint32   unsigned long int
 
#define int8     signed char
 
#define int16    signed short int
 
#define int32    signed long int
 
#define uint64   unsigned long long int
 
#define int64    signed long long int
 
//定义1602中一些常用的指令，方便不同的读者可以根据自己的修改
 
#define SETMODE   0x38          //16*2显示,5*7点阵,8位数据接口
 
#define DISOPEN   0x0C          //显示开,不显示光标,光标不闪烁
 
#define DISMODE   0x06          //读写字符后地址加1,屏显不移动
 
#define SETADDR   0x80          //设置数据地址指针初始值
 
#define CLEAR     0x01          //清屏,数据指针清零
 
#define RET       0x02          //回车,数据指针清零 
 
#define PORT      P0            //I/O口 
 
sbit RS = P1^0;
 
sbit E = P2^5; 
 
sbit dula = P2^6;
 
sbit wela = P2^7;

void delay(uint16 time);
 
void Write1602_Com(uint8 com);
 
void Write1602_Dat(uint8 dat);
 
void Init1602(void);
 
void Write1602_Str(uint8 addr,uint8 length,uint8 *pbuf);
 
uint8 code xin[8]={									 //心字模
0x00,0x1B,0x1F,0x1F,0x1F,0x0E,0x04,0x00
};
 
uint8 code hot[8]={                                  //摄氏温度字模
 
0x10,0x06,0x09,0x08,0x08,0x09,0x06,0x00
 
};
 
uint8 code zuo[8]={									 //汉的左部分字模
0x00,0x02,0x01,0x02,0x01,0x01,0x02,0x00
};
 
uint8 code you[8]={									 //汉的右部分字模
0x00,0x1e,0x12,0x0c,0x0a,0x11,0x00,0x00		            
};
 
uint8 i; 
 
void real()
 
{
 
    Init1602();                                      //初始化1602 
 
    //自定义CGRAM
 
    Write1602_Str(0x40,8,hot);                                           //摄氏温标->CGRAM的内存000中
    Write1602_Str(0x48,8,zuo);						 //汉的左部分->CGRAM的内存001中
    Write1602_Str(0x50,8,you);						 //汉的右部分->CGRAM的内存010中
    Write1602_Str(0x58,8,xin);						 //心->CGRAM的内存011中
    Write1602_Com(0x80); 
    							 //设置DDRAM地址，即显示的位置
    for(i=0;i<8;i++)
       Write1602_Dat(0);
	for(i=0;i<8;i++)
       Write1602_Dat(3);
    Write1602_Com(0xc0);                             //同上
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
	dula=0;					   //关闭数据管的显示，因为我的51对应的是数据管的输入
	wela=0;					   //所以需要锁存器锁定来关闭影响
    Write1602_Com(SETMODE);     //模式设置
    delay(5);
 
    Write1602_Com(DISOPEN);     //显示设置
 
    delay(5);
 
    Write1602_Com(DISMODE);     //显示模式
 
    delay(5);
 
    Write1602_Com(CLEAR);       //清屏
 
    delay(5);
 
} 
 
void Write1602_Dat(uint8 dat)
 
{
 
    E=0;
 
    RS=1;                    //数据
 
    delay(5);               //延时
 
    PORT=dat;                //端口赋值
 
    delay(5);
 
    E=1;                     //高脉冲
 
    delay(5);
 
    E=0;
 
} 
 
void Write1602_Com(uint8 com)
{
    E=0;
    RS=0;                    //命令
    delay(5);               //延时
    PORT=com;                //端口赋值
    delay(5);
    E=1;                     //高脉冲
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