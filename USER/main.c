#include "led.h"
#include "delay.h"
#include "key.h"
#include "sys.h"
#include "usart.h"	 
#include "usmart.h"	
#include "lcd.h"

 
/************************************************
 ALIENTEK��ӢSTM32������ʵ��14
 USMART�������ʵ��   
 ����֧�֣�www.openedv.com
 �Ա����̣�http://eboard.taobao.com 
 ��ע΢�Ź���ƽ̨΢�źţ�"����ԭ��"����ѻ�ȡSTM32���ϡ�
 ������������ӿƼ����޹�˾  
 ���ߣ�����ԭ�� @ALIENTEK
************************************************/


//LED״̬���ú���
void led_set(u8 sta)
{
	LED1=sta;
} 
//�����������ò��Ժ���
void test_fun(void(*ledset)(u8),u8 sta)
{
	ledset(sta);
}  	
 int main(void)
 {	 
	LCD_GPIO_Config();
	LCD_init();
	LCD_clear(BLACK);
	delay_init();	    	 //��ʱ������ʼ��	  
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2); 	 //����NVIC�жϷ���2:2λ��ռ���ȼ���2λ��Ӧ���ȼ�
	uart_init(115200);	 	//���ڳ�ʼ��Ϊ115200
 	LED_Init();			     //LED�˿ڳ�ʼ��
	usmart_dev.init(SystemCoreClock/1000000);	//��ʼ��USMART	
	 
	BACK_COLOR = BLACK;
  LCD_showString(32, 32, "Junle's Blog", GREEN);
  	while(1) 
	{		 	  
		LED0=!LED0;	
		delay_ms(500);
	}			
 }

