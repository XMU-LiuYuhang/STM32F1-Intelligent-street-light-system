#ifndef _MENU_H_
#define _MENU_H_
#include "stm32f10x.h"


extern int mode_flag; //模式标志位 0为时间控制；1为手动控制；2为光线控制
extern int seasonmenu_flag; //季节菜单标志位 0为不显示；1为显示

void ChangeMode();
void DrawMenu();
void DrawTimeMenu();
void DrawLightMenu();
void DrawManualMenu();
void DrawLight(u16 x,u16 y);
void DrawKeyboard(u16 x,u16 y,u16 w,u16 h);
void DrawKey(u16 x,u16 y,u16 w,u16 h,u8 *str);
void DrawSeasonMenu();
void SetRun();


#endif // _MENU_H_