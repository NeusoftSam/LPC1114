#include "LPC11XX.H"
#include "gpio.h"
int main()
{
		LEDInit();//����LED
//	  LPC_IOCON->PIO3_0&=~(0x07);//��P1_9����ΪGPIO
//	  LPC_GPIO3->DIR   &=~(1<<0);//��P1_9����Ϊ����
//	  LPC_IOCON->PIO3_1&=~(0x07);//��P1_10����ΪGPIO
//	  LPC_GPIO3->DIR &=~(1<<1);//��P1_10����Ϊ����

	  LPC_GPIO3->IE|=(1<<0);//����P1.9�����ϵ��жϣ�IE���ж����μĴ�����0�����Σ�1�ǿ�
	  LPC_GPIO3->IE|=(1<<1);//����P1.10�����ϵ��ж�
	  LPC_GPIO3->IS&=~(1<<0);//����P1.9����Ϊ���ش���
	  LPC_GPIO3->IS&=~(1<<1);//����P1.10����Ϊ���ش���
	  LPC_GPIO3->IEV&=~(1<<0);//����P1.9����Ϊ�½��ش���
	  LPC_GPIO3->IEV&=~(1<<1);//����P1.10����Ϊ�½��ش���
	  NVIC_EnableIRQ(EINT3_IRQn);//��GPIO1�ж�
	while(1)
	{
		;
	}
}



