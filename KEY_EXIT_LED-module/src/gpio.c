#include "LPC11XX.h"
#include "gpio.h"
void LEDInit()
{
		LPC_SYSCON->SYSAHBCLKCTRL|=(1<<16);//使能IOCON时钟
	  LPC_IOCON->PIO2_0&=~0x07;
	  LPC_IOCON->PIO2_0|=0x00;//把P2.0脚设置为GPIO
	  LPC_IOCON->PIO2_1&=~0x07;
	  LPC_IOCON->PIO2_1|=0x00;//把P2.1脚设置为GPIO
	  LPC_SYSCON->SYSAHBCLKCTRL&=~(1<<16);//禁能IOCON时钟
	  
	  LPC_SYSCON->SYSAHBCLKCTRL|=(1<<6);
	  LPC_GPIO2->DIR|=(1<<0);//把P2.0设置为输出引脚
	  LPC_GPIO2->DATA|=(1<<0);//把P2.0设置为高电平
	  LPC_GPIO2->DIR|=(1<<1);//把P2.1设置为输出引脚
	  LPC_GPIO2->DATA|=(1<<1);//把P2.1设置为高电平
	
		LPC_IOCON->PIO3_0&=~(0x07);//将P1_9设置为GPIO
	  LPC_GPIO3->DIR   &=~(1<<0);//将P1_9设置为输入
	  LPC_IOCON->PIO3_1&=~(0x07);//将P1_10设置为GPIO
	  LPC_GPIO3->DIR &=~(1<<1);//将P1_10设置为输入
}

	void PIOINT3_IRQHandler()//忘了改中断服务函数的序号了，结果调试了半天
	{
		if((LPC_GPIO3->MIS&(1<<0))==(1<<0))//如果是P1.9引起的中断
		{
       LED1_ON();
       while(KEY1_DOWN());
       LED1_OFF();
			 LPC_GPIO3->IC=(1<<0);//清中断
		}
		if((LPC_GPIO3->MIS&(1<<1))==(1<<1))//如果是P1.10引起的中断
		{
       LED2_ON();
       while(KEY2_DOWN());
			LED2_OFF();
			 LPC_GPIO3->IC=(1<<1);//清中断
	}
}
	
