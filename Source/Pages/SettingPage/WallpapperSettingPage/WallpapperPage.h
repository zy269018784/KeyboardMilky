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

typedef struct SettingsWallpapperPage
{
	lv_obj_t* Handle;
	lv_obj_t* Label;

	lv_obj_t* ReturnRow;
	lv_obj_t* ButtonReturn;
	lv_obj_t* LabelCurrentPage;
	lv_obj_t* ButtonUSBDownload;

	lv_obj_t* ContentRow;
	WallpapperPage Wallpappers[10];

	List WallpapperPageLists;
}SettingsWallpapperPage;

#ifdef __cplusplus
extern "C"
{
#endif
	void CreateWallpapperPage(WallpapperPage* Page, lv_obj_t* Parent, int X, int Y, int W, int H, void* Pixels);
#ifdef __cplusplus
}
#endif