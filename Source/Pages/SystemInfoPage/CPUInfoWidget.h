#pragma once
#include <lvgl/lvgl.h>
typedef struct
{
	lv_obj_t* Handle;

	lv_obj_t* ArchProgress;
	lv_obj_t* LabelCPU;
	lv_obj_t* LabelUsage;
}CPUInfoWidget;
#ifdef __cplusplus
extern "C"
{
#endif
	void CreateCPUInfoWidget(CPUInfoWidget* Widget, lv_obj_t* Parent, int x, int y, int w, int h);
#ifdef __cplusplus
}
#endif