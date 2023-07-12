#include "stm32f10x.h"


/************************************************
 ALIENTEK 战舰STM32F103开发板实验0
 工程模板
 注意，这是手册中的新建工程章节使用的main文件 
 技术支持：www.openedv.com
 淘宝店铺：http://eboard.taobao.com 
 关注微信公众平台微信号："正点原子"，免费获取STM32资料。
 广州市星翼电子科技有限公司  
 作者：正点原子 @ALIENTEK
************************************************/
#include "headfile.h"




 int main(void)
 {	
	u8 t=0;	
  
  delay_init();	    	 //延时函数初始化
  NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);//设置系统中断优先级分组2
  uart_init(115200);	 //串口初始化为115200
  LED_Init();					 //初始化与LED连接的硬件接口
  LCD_Init();					 //初始化LCD
	Time_Init();				 //初始化时间
	tp_dev.init();			 //初始化触摸屏
  TP_Adjust();
  POINT_COLOR=BLUE;    //设置字体为蓝色
	DrawMenu();					 //绘制初始界面
  LED_Init();		  	//初始化LED端口
	T_Adc_Init();		  		//ADC初始化
  Lsens_Init(); 			//初始化光敏传感器
  // TIM3_PWM_Init(899,0);	 //??·?????PWM????=72000000/900=80Khz
  flash_init();       //初始化flash	
	 
  while(1)
	{
    Time_run(t);
		Scan_key(Get_keynum(10,160));
    Input_show(input_num);
    Control_time_light();
    Control_light_light();
    Show_light_value();


    if(seasonmenu_flag != 1)
    {
      Show_light();
      temp_run();
    }
    else
    { 
      SetRun();
    }

	}
 }
