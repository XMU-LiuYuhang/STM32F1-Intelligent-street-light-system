#include "time.h"
#include "headfile.h"

void Time_Init()
{
    RTC_Init();
    RTC_Set(2018,12,10,0,0,0);
}


void Choose_Show(u16 x,u16 y,u32 num,u8 len,u8 size,int my_choose_flag)
{	
	if((choose_flag == my_choose_flag) && seasonmenu_flag != 1)
		POINT_COLOR=RED;
	else
		POINT_COLOR=BLUE;
	LCD_ShowNum(x,y,num,len,size);
	
	POINT_COLOR=BLUE;
}

//获取小时
u8 Get_hour()
{
	return calendar.hour;
}


//主页时间显示
void Time_run(u8 t)
{		
		POINT_COLOR=BLUE;
         if(t!=calendar.sec)
		{
			t=calendar.sec;
			Choose_Show(12,12,calendar.w_year,4,16,0);		  
			Choose_Show(52,12,calendar.w_month,2,16,1);
			Choose_Show(78,12,calendar.w_date,2,16,2);								   
			switch(calendar.week)
			{
				case 0:
					LCD_ShowString(20,45,200,16,16,"Sunday   ");
					break;
				case 1:
					LCD_ShowString(20,45,200,16,16,"Monday   ");
					break;
				case 2:
					LCD_ShowString(20,45,200,16,16,"Tuesday  ");
					break;
				case 3:
					LCD_ShowString(20,45,200,16,16,"Wednesday");
					break;
				case 4:
					LCD_ShowString(20,45,200,16,16,"Thursday ");
					break;
				case 5:
					LCD_ShowString(20,45,200,16,16,"Friday   ");
					break;
				case 6:
					LCD_ShowString(20,45,200,16,16,"Saturday ");
					break;  
			}

			Choose_Show(12,28,calendar.hour,2,16,3);
			Choose_Show(36,28,calendar.min,2,16,4);
			Choose_Show(62,28,calendar.sec,2,16,5);	

			//判断为冬令时还是夏令时
			if(calendar.w_month >= summer_begin_month && calendar.w_month <= summer_end_month && calendar.w_date >= summer_begin_day && calendar.w_date <= summer_end_day)
			{
				//夏令时
				season_flag = 0;
				LCD_ShowString(20,120,48,16,16,"SUMMER");

			}
			else
			{
				//冬令时
				season_flag = 1;
				LCD_ShowString(20,120,48,16,16,"WINTER");
			}
   		}
   delay_ms(10);
}





