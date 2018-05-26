#ifndef _USER_H
#define _USER_H

#define LED1_ON() (LPC_GPIO2->DATA&=~(1<<0))//点亮P2.0引脚LED
#define LED1_OFF() (LPC_GPIO2->DATA|=(1<<0))//熄灭P2.0引脚LED

#define LED2_ON()  (LPC_GPIO2->DATA&=~(1<<1))//点亮P2.1引脚LED
#define LED2_OFF() (LPC_GPIO2->DATA|=(1<<1))//熄灭P2.1引脚LED


#define KEY1_DOWN() ((LPC_GPIO3->DATA&(1<<0))!=(1<<0))//P3.0引脚按键按下
#define KEY2_DOWN() ((LPC_GPIO3->DATA&(1<<1))!=(1<<1))//P3.1引脚按键按下
void LEDInit();
#endif



