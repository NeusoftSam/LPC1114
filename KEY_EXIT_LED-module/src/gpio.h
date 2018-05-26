#ifndef _USER_H
#define _USER_H

#define LED1_ON() (LPC_GPIO2->DATA&=~(1<<0))//����P2.0����LED
#define LED1_OFF() (LPC_GPIO2->DATA|=(1<<0))//Ϩ��P2.0����LED

#define LED2_ON()  (LPC_GPIO2->DATA&=~(1<<1))//����P2.1����LED
#define LED2_OFF() (LPC_GPIO2->DATA|=(1<<1))//Ϩ��P2.1����LED


#define KEY1_DOWN() ((LPC_GPIO3->DATA&(1<<0))!=(1<<0))//P3.0���Ű�������
#define KEY2_DOWN() ((LPC_GPIO3->DATA&(1<<1))!=(1<<1))//P3.1���Ű�������
void LEDInit();
#endif



