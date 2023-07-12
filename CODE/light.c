#include "light.h"
#include "headfile.h"

// 路灯开关状态指示
void Show_light()
{
    if(LED0 == 0)
    {		
        LCD_ShowString(160,48,48,16,16,"ON ");
    }
    else
    {
        LCD_ShowString(160,48,48,16,16,"OFF");
    }

    if(LED1 == 0)
    {
        LCD_ShowString(250,48,48,16,16,"ON ");
    }
    else
    {
        LCD_ShowString(250,48,48,16,16,"OFF");
    }
}


int summer_begin_month = 6;//夏令时开始月份
int summer_end_month = 9;//夏令时结束月份
int summer_begin_day = 1;//夏令时开始日期
int summer_end_day = 1;//夏令时结束日期

int summer_begin_hour = 19;//路灯开启小时
int summer_end_hour = 5;//路灯关闭小时
int summer_begin_min = 30;//路灯开启分钟
int summer_end_min = 30;//路灯关闭分钟

int winter_begin_hour = 18;//路灯开启小时
int winter_end_hour = 6;//路灯关闭小时
int winter_begin_min = 30;//路灯开启分钟
int winter_end_min = 30;//路灯关闭分钟


int season_flag = 0;//季节标志位 0为夏令时；1为冬令时

u8 adcx; //光敏传感器值
void Show_light_value()
{   
    if(mode_flag != 2)
    {
        // 非光线模式下不执行
        return;
    }
    adcx=Lsens_Get_Val();
    LCD_ShowxNum(90,135,adcx,3,16,0);
    LCD_ShowString(12,135,128,16,16,"LightValue:");
}


int light_flag = 0;//路灯开关标志位 0为关；1为开
// 呼吸灯渐亮函数
void Light_up()
{
    int i = 0;
    for(i = 0;i <= 300;i++)
    {   
        delay_ms(10);
        TIM_SetCompare1(TIM3,i);
    }
    light_flag = 1;
}

// 呼吸灯渐暗
void Light_down()
{
    int i = 0;
    for(i = 300;i >= 0;i--)
    {
        TIM_SetCompare1(TIM3,i);
        delay_ms(10);
    }
    light_flag = 0;
}


// 光线模式下启停逻辑
void Control_light_light()
{
    if(mode_flag != 2)
    {
        // 非光线模式下不执行
        return;
    }

    if(adcx < 30)
    {
        // 开启
        LED0 = 0;
        LED1 = 0;
    }
    else
    {
        // 关闭
        LED0 = 1;
        LED1 = 1;
    }
}

// 时间模式下启停逻辑
void Control_time_light()
{
    if(mode_flag != 0)
    {
        // 非时间模式下不执行
        return;
    }

    if(season_flag == 0)
    {
        //夏令时
        if(summer_end_hour > summer_begin_hour )
        {
            //结束时间在24点前
            if( (calendar.hour > summer_begin_hour && calendar.hour < summer_end_hour) || (calendar.hour == summer_begin_hour && calendar.min >= summer_begin_min) || (calendar.hour == summer_end_hour && calendar.min <= summer_end_min) )
            {
                // 开启
                LED0 = 0;
                LED1 = 0;
            }
            else
            {
                // 关闭
                LED0 = 1;
                LED1 = 1;
            }
            
        }
        else if (summer_begin_hour == summer_end_hour)
        {
            // 开始时间和结束时间相同
            if(calendar.hour == summer_begin_hour && calendar.min >= summer_begin_min && calendar.min <= summer_end_min)
            {
                // 开启
                LED0 = 0;
                LED1 = 0;
            }
            else
            {
                // 关闭
                LED0 = 1;
                LED1 = 1;
            }
        }
        else
        {
            // 结束时间在24点后
            if( (calendar.hour > summer_begin_hour || calendar.hour < summer_end_hour) || (calendar.hour == summer_begin_hour && calendar.min >= summer_begin_min) || (calendar.hour == summer_end_hour && calendar.min <= summer_end_min) )
            {
                // 开启
                LED0 = 0;
                LED1 = 0;
            }
            else
            {
                // 关闭
                LED0 = 1;
                LED1 = 1;
            }
        }
    }
    else
    {
        // 冬令时
        if(winter_end_hour > winter_begin_hour )
        {
            //结束时间在24点前
            if( (calendar.hour > winter_begin_hour && calendar.hour < winter_end_hour) || (calendar.hour == winter_begin_hour && calendar.min >= winter_begin_min) || (calendar.hour == winter_end_hour && calendar.min <= winter_end_min) )
            {
                // 开启
                LED0 = 0;
                LED1 = 0;
            }
            else
            {
                // 关闭
                LED0 = 1;
                LED1 = 1;
            }
            
        }
        else if (winter_begin_hour == winter_end_hour)
        {
            // 开始时间和结束时间相同
            if(calendar.hour == winter_begin_hour && calendar.min >= winter_begin_min && calendar.min <= winter_end_min)
            {
                // 开启
                LED0 = 0;
                LED1 = 0;
            }
            else
            {
                // 关闭
                LED0 = 1;
                LED1 = 1;
            }
        }
        else
        {
            // 结束时间在24点后
            if( (calendar.hour > winter_begin_hour || calendar.hour < winter_end_hour) || (calendar.hour == winter_begin_hour && calendar.min >= winter_begin_min) || (calendar.hour == winter_end_hour && calendar.min <= winter_end_min) )
            {
                // 开启
                LED0 = 0;
                LED1 = 0;
            }
            else
            {
                // 关闭
                LED0 = 1;
                LED1 = 1;
            }
        }
    }


}
