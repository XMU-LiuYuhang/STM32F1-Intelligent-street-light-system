#include  "menu.h"
#include  "lcd.h"
#include  "headfile.h"


//绘制时间菜单
void DrawTimeMenu(){
    LCD_Clear(WHITE);
    LCD_DrawRectangle(10,10,10+300,10+150);
    LCD_DrawRectangle(140,100,190,130);
		LCD_ShowString(12,12,200,16,16,"    -  -  ");	//显示字符串
		LCD_ShowString(12,28,200,16,16,"  :  :  ");
    LCD_ShowString(12,65,200,16,16,"Time Mode");
    DrawLight(170,55);
    DrawLight(260,55);
    DrawKeyboard(10,160,300,310);
}

//绘制手动菜单
void DrawManualMenu(){
    LCD_Clear(WHITE);
    LCD_DrawRectangle(10,10,10+300,10+150);
		LCD_ShowString(12,12,200,16,16,"    -  -  ");	//显示字符串
		LCD_ShowString(12,28,200,16,16,"  :  :  ");
    LCD_ShowString(12,65,200,16,16,"Manual Mode");
    DrawLight(170,55);
    DrawLight(260,55);
    DrawKeyboard(10,160,300,310);
}

//绘制光线菜单
void DrawLightMenu(){
    LCD_Clear(WHITE);
    LCD_DrawRectangle(10,10,10+300,10+150);
		LCD_ShowString(12,12,200,16,16,"    -  -  ");	//显示字符串
		LCD_ShowString(12,28,200,16,16,"  :  :  ");
    LCD_ShowString(12,65,200,16,16,"Light Mode");
    DrawLight(170,55);
    DrawLight(260,55);
    DrawKeyboard(10,160,300,310);
}


int seasonmenu_flag = 0; //季节标志 0,1 1表示进入季节模式
//绘制季节菜单
void DrawSeasonMenu()
{   
    seasonmenu_flag = 1;
    //先清空一个范围
    LCD_Fill(10,10,10+300,10+150,WHITE);
    LCD_DrawRectangle(10,10,10+300,10+150);
    LCD_DrawRectangle(230,100,280,130);
    LCD_ShowString(12,12,200,16,16,"    -  -  ");
		LCD_ShowString(12,28,200,16,16,"  :  :  ");
    LCD_ShowString(100,12,200,16,16,"S_s_mon");
    LCD_ShowString(100,28,200,16,16,"S_s_day");
    LCD_ShowString(100,44,200,16,16,"S_e_mon");
    LCD_ShowString(100,60,200,16,16,"S_e_day");
    LCD_ShowString(100,76,200,16,16,"S_s_hour");
    LCD_ShowString(100,92,200,16,16,"S_s_min");
    LCD_ShowString(100,108,200,16,16,"S_c_hour");
    LCD_ShowString(100,124,200,16,16,"S_c_min");
    LCD_ShowString(200,12,200,16,16,"W_s_hour");
    LCD_ShowString(200,28,200,16,16,"W_s_min");
    LCD_ShowString(200,44,200,16,16,"W_c_hour");
    LCD_ShowString(200,60,200,16,16,"W_c_min");

    DrawKeyboard(10,160,300,310);
}

//选择展示
void Choose_Season_Show(u16 x,u16 y,u32 num,u8 len,u8 size,int my_choose_flag)
{	
	if(choose_season_flag == my_choose_flag)
		POINT_COLOR=RED;
	else
		POINT_COLOR=BLUE;
	LCD_ShowNum(x,y,num,len,size);
	
	POINT_COLOR=BLUE;
}

void SetRun()
{
  
  Choose_Season_Show(170,12,summer_begin_month,2,16,0);
  Choose_Season_Show(170,28,summer_begin_day,2,16,1);
  Choose_Season_Show(170,44,summer_end_month,2,16,2);
  Choose_Season_Show(170,60,summer_end_day,2,16,3);
  Choose_Season_Show(170,76,summer_begin_hour,2,16,4);
  Choose_Season_Show(170,92,summer_begin_min,2,16,5);
  Choose_Season_Show(170,108,summer_end_hour,2,16,6);
  Choose_Season_Show(170,124,summer_end_min,2,16,7);
  Choose_Season_Show(270,12,winter_begin_hour,2,16,8);
  Choose_Season_Show(270,28,winter_begin_min,2,16,9);
  Choose_Season_Show(270,44,winter_end_hour,2,16,10);
  Choose_Season_Show(270,60,winter_end_min,2,16,11);
}

//绘制灯
void DrawLight(u16 x,u16 y){
    u16 d = (u16)(20*0.7071);
		u16 d1 = d + 10*0.7071;
		LCD_Draw_Circle(x,y,20);
		LCD_DrawLine(x,y-20,x,y-30);
		LCD_DrawLine(x,y+20,x,y+30);
    LCD_DrawLine(x-20,y,x-30,y);
    LCD_DrawLine(x+20,y,x+30,y);
    LCD_DrawLine(x-d,y-d,x-d1,y-d1);
    LCD_DrawLine(x+d,y-d,x+d1,y-d1);
    LCD_DrawLine(x-d,y+d,x-d1,y+d1);
    LCD_DrawLine(x+d,y+d,x+d1,y+d1);
}

//绘制键盘
void DrawKeyboard(u16 x,u16 y,u16 w,u16 h){
    LCD_DrawRectangle(x,y,x+w,y+h);
	if(mode_flag == 1)
		{
    DrawKey(x+10,y+10,60,40,"L1");
		DrawKey(x+80,y+10,60,40,"L2");
		}
		else
		{
		DrawKey(x+10,y+10,60,40,"Choose");	
		DrawKey(x+80,y+10,60,40,"Season");
		}
    DrawKey(x+150,y+10,60,40,"Mode");
    DrawKey(x+220,y+10,60,40,"Save");

    DrawKey(x+10,y+60,60,40,"1");
    DrawKey(x+80,y+60,60,40,"2");
    DrawKey(x+150,y+60,60,40,"3");
    DrawKey(x+220,y+60,60,40,"AC");

    DrawKey(x+10,y+110,60,40,"4");
    DrawKey(x+80,y+110,60,40,"5");
		DrawKey(x+150,y+110,60,40,"6");
    DrawKey(x+220,y+110,60,40,"Del");

		DrawKey(x+10,y+160,60,40,"7");
    DrawKey(x+80,y+160,60,40,"8");
		DrawKey(x+150,y+160,60,40,"9");
    DrawKey(x+220,y+160,60,40,"Enter");

    DrawKey(x+10,y+210,60,40,"*");
    DrawKey(x+80,y+210,60,40,"0");
    DrawKey(x+150,y+210,60,40,"#");
    DrawKey(x+220,y+210,60,40,"Back");
}

//绘制按键
void DrawKey(u16 x,u16 y,u16 w,u16 h,u8 *str){
    LCD_DrawRectangle(x,y,x+w,y+h);
    LCD_ShowString(x+5,y+5,200,16,16,str);
}

//绘制菜单
void DrawMenu()
{
  switch(mode_flag)
  {
    case 0:
      DrawTimeMenu();
      break;
    case 1:
      DrawManualMenu();
      break;
    case 2:
      DrawLightMenu();
      break;
    default:
      break;
  }
}

int mode_flag = 0;  //模式标志位 0为时间控制；1为手动控制；2为光线控制
//模式改变
void ChangeMode()
{
    if(mode_flag < 2)
    {
        mode_flag++;
    }
    else
    {
        mode_flag = 0;
    }
		
    DrawMenu();
}