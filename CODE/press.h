#ifndef _PRESS_H_
#define _PRESS_H_
#include "headfile.h"


#define key_x0 10
#define key_y0 160
#define key_width 60
#define key_height 40
#define key_width_real 75
#define key_height_real 55
#define FLASH_SAVE_ADDR  0X08070000 //设置FLASH 保存地址(必须为偶数)

u8 Get_keynum(u16 x,u16 y);
void Key_action(u8 key);
void Fill_key(u8 keyx);
void Fill_white(u8 keyx);
void Scan_key(u8 keyx);
void Input_show(u32 num);
void flash_change();
void flash_init();

extern int choose_flag;
extern int choose_season_flag;
extern u32 input_num;

#endif