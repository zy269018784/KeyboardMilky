#pragma once
#include <lvgl/lvgl.h>
#include "Point2.h"
#include "Util/List.h"
typedef struct WallpapperPage
{
	ListNode Node;

	lv_obj_t* Handle;

	lv_obj_t* ImageTheme;

	lv_obj_t* ButtonApply;
	lv_obj_t* LabelApply;
}WallpapperPage;

#ifdef __cplusplus
extern "C"
{
#endif
	void CreateWallpapperPage(WallpapperPage* Page, lv_obj_t* Parent, int X, int Y, int W, int H, void* Pixels);
#ifdef __cplusplus
}
#endif