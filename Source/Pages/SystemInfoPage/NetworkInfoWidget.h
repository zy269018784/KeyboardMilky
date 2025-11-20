#pragma once
#include <lvgl/lvgl.h>
#include "Point2.h"
typedef struct
{
	lv_obj_t* Handle;

	lv_obj_t* Widget[7];
	Point2    WidgetPos[7];
	Point2    WidgetSize[7];
}NetworkInfoWidget;
#ifdef __cplusplus
extern "C"
{
#endif
	void CreateNetworkInfoWidget(NetworkInfoWidget* Widget, lv_obj_t* Parent, int x, int y, int w, int h);
#ifdef __cplusplus
}
#endif