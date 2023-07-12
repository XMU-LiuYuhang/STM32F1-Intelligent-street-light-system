#ifndef _LIGHT_H_
#define _LIGHT_H_
#include "headfile.h"

extern int summer_begin_month;//夏令时开始月份
extern int summer_end_month;//夏令时结束月份
extern int summer_begin_day;//夏令时开始日期
extern int summer_end_day;//夏令时结束日期

extern int summer_begin_hour;//夏季路灯开启小时
extern int summer_end_hour;//夏季路灯关闭小时
extern int summer_begin_min;//夏季路灯开启分钟
extern int summer_end_min;//夏季路灯关闭分钟

extern int winter_begin_hour;//冬季路灯开启小时
extern int winter_end_hour;//冬季路灯关闭小时
extern int winter_begin_min;//冬季路灯开启分钟
extern int winter_end_min;//冬季路灯关闭分钟

extern int season_flag;//季节标志位 0为夏令时；1为冬令时 

extern light_flag;//路灯开关标志位 0为关；1为开

void Show_light();
void Show_light_value();
void Control_time_light();
void Control_light_light();
void Light_up();
void Light_down();

#endif /* _LIGHT_H_ */