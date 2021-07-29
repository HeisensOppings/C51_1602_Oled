#ifndef __CHUANKOU_H__
#define __CHUANKOU_H__


/************************************************************
*实验名：串口通讯实验
*实验效果：配合串口助手使用 将pc机发出的数据传送到单片机中
*		   单片机将接收到的数据发送到pc机 可以在串口助手上显示
*波特率：9600
************************************************************/

void UsartConfiguration()
{
	SCON=0X50;			//设置为工作方式1
	TMOD=0X20;			//设置计数器工作方式2
	PCON=0X00;		//SMOD=0，32分频
	TH1=0Xfd;		//计数器初始值设置，注意波特率是9600的
	TL1=0Xfd;
	ES=1;					//打开接收中断
	EA=1;						//打开总中断
	TR1=1;					//打开计数器
}

void chuankou()
{
	UsartConfiguration();
	while(1);
}

void uart() interrupt 4
{
	unsigned char date;
	
	date = SBUF;//取出接收到的数据
	RI = 0;//清除接收中断标志位	
	SBUF = date;//将接收到的数据放回发送缓存器
	while(!TI);//等待发送数据完成
	TI = 0;//清除发送中断标志位
}


#endif