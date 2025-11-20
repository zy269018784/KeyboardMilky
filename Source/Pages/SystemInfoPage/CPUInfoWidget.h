#pragma once
#include <lvgl/lvgl.h>
typedef struct
{
	lv_obj_t* Handle;

	lv_obj_t* Temp1;
	lv_obj_t* Temp2;
	lv_obj_t* TempProgress1;
	lv_obj_t* TempProgress2;

	lv_obj_t* Clock1;
	lv_obj_t* Clock2;
	lv_obj_t* ClockProgress1;
	lv_obj_t* ClockProgress2;
}CPUInfoWidget;
#ifdef __cplusplus
extern "C"
{
#endif
	void CreateCPUInfoWidget(CPUInfoWidget* Widget, lv_obj_t* Parent, int x, int y, int w, int h);
#ifdef __cplusplus
}
#endif