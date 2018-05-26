#include "LPC11XX.h"
#include "gpio.h"
void LEDInit()
{
		LPC_SYSCON->SYSAHBCLKCTRL|=(1<<16);//ʹ��IOCONʱ��
	  LPC_IOCON->PIO2_0&=~0x07;
	  LPC_IOCON->PIO2_0|=0x00;//��P2.0������ΪGPIO
	  LPC_IOCON->PIO2_1&=~0x07;
	  LPC_IOCON->PIO2_1|=0x00;//��P2.1������ΪGPIO
	  LPC_SYSCON->SYSAHBCLKCTRL&=~(1<<16);//����IOCONʱ��
	  
	  LPC_SYSCON->SYSAHBCLKCTRL|=(1<<6);
	  LPC_GPIO2->DIR|=(1<<0);//��P2.0����Ϊ�������
	  LPC_GPIO2->DATA|=(1<<0);//��P2.0����Ϊ�ߵ�ƽ
	  LPC_GPIO2->DIR|=(1<<1);//��P2.1����Ϊ�������
	  LPC_GPIO2->DATA|=(1<<1);//��P2.1����Ϊ�ߵ�ƽ
	
		LPC_IOCON->PIO3_0&=~(0x07);//��P1_9����ΪGPIO
	  LPC_GPIO3->DIR   &=~(1<<0);//��P1_9����Ϊ����
	  LPC_IOCON->PIO3_1&=~(0x07);//��P1_10����ΪGPIO
	  LPC_GPIO3->DIR &=~(1<<1);//��P1_10����Ϊ����
}

	void PIOINT3_IRQHandler()//���˸��жϷ�����������ˣ���������˰���
	{
		if((LPC_GPIO3->MIS&(1<<0))==(1<<0))//�����P1.9������ж�
		{
       LED1_ON();
       while(KEY1_DOWN());
       LED1_OFF();
			 LPC_GPIO3->IC=(1<<0);//���ж�
		}
		if((LPC_GPIO3->MIS&(1<<1))==(1<<1))//�����P1.10������ж�
		{
       LED2_ON();
       while(KEY2_DOWN());
			LED2_OFF();
			 LPC_GPIO3->IC=(1<<1);//���ж�
	}
}
	
