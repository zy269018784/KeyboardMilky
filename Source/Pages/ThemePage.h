#pragma once
#include <lvgl/lvgl.h>
#include "LVGLDemo/Point2.h"

typedef struct ThemePage
{
	lv_obj_t* Parent;
	lv_obj_t* Handle;

	lv_obj_t* LabelThemeTitle;
	lv_obj_t* ImageTheme;

	lv_obj_t* ButtonApply;
	lv_obj_t* LabelApply;
}ThemePage;

#ifdef __cplusplus
extern "C"
{
#endif
	void CreateThemePage(ThemePage* Page, lv_obj_t* Parent, const char* Title, int X, int Y, int W, int H, void* Pixels);
#ifdef __cplusplus
}
#endif