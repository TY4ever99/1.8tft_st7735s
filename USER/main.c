#include "led.h"
#include "delay.h"
#include "key.h"
#include "sys.h"
#include "usart.h"	 
#include "usmart.h"	
#include "lcd.h"

 
/************************************************
 ALIENTEK精英STM32开发板实验14
 USMART调试组件实验   
 技术支持：www.openedv.com
 淘宝店铺：http://eboard.taobao.com 
 关注微信公众平台微信号："正点原子"，免费获取STM32资料。
 广州市星翼电子科技有限公司  
 作者：正点原子 @ALIENTEK
************************************************/


//LED状态设置函数
void led_set(u8 sta)
{
	LED1=sta;
} 
//函数参数调用测试函数
void test_fun(void(*ledset)(u8),u8 sta)
{
	ledset(sta);
}  	
 int main(void)
 {	 
	LCD_GPIO_Config();
	LCD_init();
	LCD_clear(BLACK);
	delay_init();	    	 //延时函数初始化	  
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2); 	 //设置NVIC中断分组2:2位抢占优先级，2位响应优先级
	uart_init(115200);	 	//串口初始化为115200
 	LED_Init();			     //LED端口初始化
	usmart_dev.init(SystemCoreClock/1000000);	//初始化USMART	
	 
	BACK_COLOR = BLACK;
  LCD_showString(32, 32, "Junle's Blog", GREEN);
  	while(1) 
	{		 	  
		LED0=!LED0;	
		delay_ms(500);
	}			
 }

