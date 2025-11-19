#pragma once
#include <lvgl/lvgl.h>
#include "Point2.h"

typedef struct VolumeWidget
{
	lv_obj_t* Handle;
	lv_obj_t* Volume;
	lv_obj_t* Muted;
	lv_obj_t* Label;
}VolumeWidget;

#ifdef __cplusplus
extern "C"
{
#endif
void CreateVolumeWidget(VolumeWidget* Widget, lv_obj_t* Parent, int32_t x, int32_t y, int32_t w, int32_t h);
#ifdef __cplusplus
}
#endif
