#ifndef __HC_SR04_H__
#define __HC_SR04_H__

// void chaoshenbo_start()
// { //超声波发出声波
//     Trig = 0;
//     Trig = 1;
//     delay(200);
//     Trig = 0;
// }
// float chaoshenbo_getone()
// { //超声波计时，返回值为float型
//     chaoshenbo_start();
//     while (!Echo)
//         ;
//     TR0 = 1; //开启定时器
//     while (Echo)
//         ;
//     TR0 = 0; //关闭定时器
//     return chaoshenbo_getdis();
// }

#include "reg52.h"
#include "intrins.h"

#define u8 unsigned char
#define u16 unsigned int

unsigned long dist;
u16 time;
u16 tt, flag;
u8 DisPlay[6];
u8 smgduan[] = {0x3f, 0x06, 0x5b, 0x4f, 0x66, 0x6d, 0x7d, 0x07,
                0x7f, 0x6f, 0x77, 0x7c, 0x39, 0x5e, 0x79, 0x71};

sbit LSA = P2 ^ 4;
sbit LSB = P2 ^ 5;
sbit LSC = P2 ^ 6;
sbit LSD = P2 ^ 7;
sbit Trig = P2 ^ 1;
sbit Echo = P2 ^ 0;

void Delay(u16 z) //11.0592MHz  1ms
{
    u8 i, j;
    for (i = z; i > 0; i--)
        for (j = 110; j > 0; j--)
            ;
}

//数码管显示
void Showsmg()
{
    u8 i;
    for (i = 0; i < 4; i++)
    {
        switch (3 - i) //位选
        {
        case 0:
            LSA = 1;
            LSB = 0;
            LSC = 0;
            LSD = 0;
            break;
        case 1:
            LSA = 0;
            LSB = 1;
            LSC = 0;
            LSD = 0;
            break;
        case 2:
            LSA = 0;
            LSB = 0;
            LSC = 1;
            LSD = 0;
            break;
        case 3:
            LSA = 0;
            LSB = 0;
            LSC = 0;
            LSD = 1;
            break;
        }
        P0 = DisPlay[i];
        Delay(1);
        P0 = 0x00;
    }
}
//计算函数
void count()
{
    time = TH0 * 256 + TL0;
    TH0 = 0;
    TL0 = 0;
    dist = (long)(time / 58.0);
    if ((dist >= 4000) || (flag == 1))
    {
        flag = 0;
        DisPlay[0] = 0x40;
        DisPlay[1] = 0x40;
        DisPlay[2] = 0x40;
        DisPlay[3] = 0x40;
    }
    else
    {
        // DisPlay[0] = smgduan[dist / 1000];
        // DisPlay[1] = smgduan[dist % 1000 / 100] | 0x80;
        DisPlay[2] = smgduan[dist / 1 % 10];
        DisPlay[3] = smgduan[dist / 10 % 10];
    }
}
//定时器初始化
void TimeInit()
{
    TMOD = 0x11;
    TH0 = 0;
    TL0 = 0;
    TH1 = 0xf8; //2ms
    TL1 = 0x30;
    EA = 1;
    ET1 = 1;
    ET0 = 1;
    TR1 = 1;
    TR0 = 0;
}
void Time0() interrupt 1
{
    flag = 1;
}
void Time1() interrupt 3
{
    TH1 = 0xf8;
    TL1 = 0x30;
    Showsmg();
    tt++;
    if (tt >= 100)
    {
        tt = 0;
        Trig = 1;
        _nop_();
        _nop_();
        _nop_();
        _nop_();
        _nop_();
        _nop_();
        _nop_();
        _nop_();
        _nop_();
        _nop_();
        _nop_();
        _nop_();
        _nop_();
        _nop_();
        _nop_();
        _nop_();
        _nop_();
        _nop_();
        _nop_();
        _nop_();
        _nop_();
        Trig = 0;
    }
}
void real()
{
    TimeInit();
    while (1)
    {
        while (!Echo)
            ;
        TR0 = 1;
        while (Echo)
            ;
        TR0 = 0;
        count();
    }
}

// #include "reg52.h"
// #include "intrins.h"

// #define u8 unsigned char
// #define u16 unsigned int

// unsigned long dist;
// u16 time;
// u16 tt, flag;
// u8 DisPlay[6];
// u8 smgduan[] = {0x3f, 0x06, 0x5b, 0x4f, 0x66, 0x6d, 0x7d, 0x07,
//                 0x7f, 0x6f, 0x77, 0x7c, 0x39, 0x5e, 0x79, 0x71};

// sbit LSA = P2 ^ 4;
// sbit LSB = P2 ^ 5;
// sbit LSC = P2 ^ 6;
// sbit Trig = P2 ^ 1;
// sbit Echo = P2 ^ 0;

// void Delay(u16 z) //11.0592MHz  1ms
// {
//     u8 i, j;
//     for (i = z; i > 0; i--)
//         for (j = 110; j > 0; j--)
//             ;
// }

// //数码管显示
// void Showsmg()
// {
//     u8 i;
//     for (i = 0; i < 4; i++)
//     {
//         switch (3 - i) //位选
//         {
//         case 0:
//             LSA = 0;
//             LSB = 0;
//             LSC = 0;
//             break;
//         case 1:
//             LSA = 1;
//             LSB = 0;
//             LSC = 0;
//             break;
//         case 2:
//             LSA = 0;
//             LSB = 1;
//             LSC = 0;
//             break;
//         case 3:
//             LSA = 1;
//             LSB = 1;
//             LSC = 0;
//             break;
//         case 4:
//             LSA = 0;
//             LSB = 0;
//             LSC = 1;
//             break;
//         case 5:
//             LSA = 1;
//             LSB = 0;
//             LSC = 1;
//             break;
//         case 6:
//             LSA = 0;
//             LSB = 1;
//             LSC = 1;
//             break;
//         case 7:
//             LSA = 1;
//             LSB = 1;
//             LSC = 1;
//             break;
//         }
//         P0 = DisPlay[i];
//         Delay(1);
//         P0 = 0x00;
//     }
// }
// //计算函数
// void count()
// {
//     time = TH0 * 256 + TL0;
//     TH0 = 0;
//     TL0 = 0;
//     dist = (long)(time * 0.17);
//     if ((dist >= 4000) || (flag == 1))
//     {
//         flag = 0;
//         DisPlay[0] = 0x40;
//         DisPlay[1] = 0x40;
//         DisPlay[2] = 0x40;
//         DisPlay[3] = 0x40;
//     }
//     else
//     {
//         DisPlay[0] = smgduan[dist / 1000];
//         DisPlay[1] = smgduan[dist % 1000 / 100] | 0x80;
//         DisPlay[2] = smgduan[dist % 100 / 10];
//         DisPlay[3] = smgduan[dist % 10];
//     }
// }
// //定时器初始化
// void TimeInit()
// {
//     TMOD = 0x11;
//     TH0 = 0;
//     TL0 = 0;
//     TH1 = 0xf8; //2ms
//     TL1 = 0x30;
//     EA = 1;
//     ET1 = 1;
//     ET0 = 1;
//     TR1 = 1;
//     TR0 = 0;
// }
// void Time0() interrupt 1
// {
//     flag = 1;
// }
// void Time1() interrupt 3
// {
//     TH1 = 0xf8;
//     TL1 = 0x30;
//     Showsmg();
//     tt++;
//     if (tt >= 100)
//     {
//         tt = 0;
//         Trig = 1;
//         _nop_();
//         _nop_();
//         _nop_();
//         _nop_();
//         _nop_();
//         _nop_();
//         _nop_();
//         _nop_();
//         _nop_();
//         _nop_();
//         _nop_();
//         _nop_();
//         _nop_();
//         _nop_();
//         _nop_();
//         _nop_();
//         _nop_();
//         _nop_();
//         _nop_();
//         _nop_();
//         _nop_();
//         Trig = 0;
//     }
// }
// void real()
// {
//     TimeInit();
//     while (1)
//     {
//         while (!Echo)
//             ;
//         TR0 = 1;
//         while (Echo)
//             ;
//         TR0 = 0;
//         count();
//     }
// }

#endif