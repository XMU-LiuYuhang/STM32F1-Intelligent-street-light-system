#include "led.h"

//////////////////////////////////////////////////////////////////////////////////	 
//本程序只供学习使用，未经作者许可，不得用于其它任何用途
//ALIENTEK战舰STM32开发板
//LED驱动代码	   
//正点原子@ALIENTEK
//技术论坛:www.openedv.com
//修改日期:2012/9/2
//版本：V1.0
//版权所有，盗版必究。
//Copyright(C) 广州市星翼电子科技有限公司 2009-2019
//All rights reserved									  
////////////////////////////////////////////////////////////////////////////////// 	   

//初始化PB5和PE5为输出口.并使能这两个口的时钟		    
//LED IO初始化
void LED_Init(void)
{
 
 GPIO_InitTypeDef  GPIO_InitStructure;
 	
 RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB|RCC_APB2Periph_GPIOE, ENABLE);	 //????PB,PE?????±??
	
 GPIO_InitStructure.GPIO_Pin = GPIO_Pin_5;				 //LED0-->PB.5 ????????
 GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP; 		 //???ì????
 GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;		 //IO????????50MHz
 GPIO_Init(GPIOB, &GPIO_InitStructure);					 //?ù???è?¨??????????GPIOB.5
 GPIO_SetBits(GPIOB,GPIO_Pin_5);						 //PB.5 ??????

 GPIO_InitStructure.GPIO_Pin = GPIO_Pin_5;	    		 //LED1-->PE.5 ????????, ???ì????
 GPIO_Init(GPIOE, &GPIO_InitStructure);	  				 //???ì???? ??IO????????50MHz
 GPIO_SetBits(GPIOE,GPIO_Pin_5); 						 //PE.5 ?????? 
}
 
