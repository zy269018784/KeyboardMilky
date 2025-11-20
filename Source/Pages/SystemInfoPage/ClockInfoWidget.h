#pragma once
#include <lvgl/lvgl.h>
typedef struct
{
	lv_obj_t* Handle;
	
	lv_obj_t* Temp1;
	lv_obj_t* Temp2;
	lv_obj_t* Progress1;
	lv_obj_t* Progress2;
}ClockInfoWidget;
#ifdef __cplusplus
extern "C"
{
#endif
void CreateClockInfoWidget(ClockInfoWidget *Widget, lv_obj_t* Parent, int x, int y, int w, int h);
#ifdef __cplusplus
}
#endif