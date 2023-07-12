#include "temp.h"

void temp_run()
{   
    static short temp = 00.00;
    LCD_ShowString(12,85,200,16,16,"Temperature:");
    temp=Get_Temprate();	//更新温度值
    if(temp<0)
    {
        temp=-temp;
        LCD_ShowString(2*8,105,16,16,16,"-");	//负值
    }else LCD_ShowString(2*8,105,16,16,16," ");	//正值		
    LCD_ShowxNum(24,105,temp/100,2,16,0);		//小数点前
    LCD_ShowString(40,105,16,16,16,".");                    //小数点
    LCD_ShowxNum(45,105,temp%100,2,16, 0X80);	//小数点后
    LCD_ShowString(62,105,16,16,16,"C");		//单位
}