#include "LPC11XX.H"
#include "gpio.h"
int main()
{
		LEDInit();//配置LED
//	  LPC_IOCON->PIO3_0&=~(0x07);//将P1_9设置为GPIO
//	  LPC_GPIO3->DIR   &=~(1<<0);//将P1_9设置为输入
//	  LPC_IOCON->PIO3_1&=~(0x07);//将P1_10设置为GPIO
//	  LPC_GPIO3->DIR &=~(1<<1);//将P1_10设置为输入

	  LPC_GPIO3->IE|=(1<<0);//允许P1.9引脚上的中断，IE是中断屏蔽寄存器，0是屏蔽，1是开
	  LPC_GPIO3->IE|=(1<<1);//允许P1.10引脚上的中断
	  LPC_GPIO3->IS&=~(1<<0);//设置P1.9引脚为边沿触发
	  LPC_GPIO3->IS&=~(1<<1);//设置P1.10引脚为边沿触发
	  LPC_GPIO3->IEV&=~(1<<0);//设置P1.9引脚为下降沿触发
	  LPC_GPIO3->IEV&=~(1<<1);//设置P1.10引脚为下降沿触发
	  NVIC_EnableIRQ(EINT3_IRQn);//打开GPIO1中断
	while(1)
	{
		;
	}
}



