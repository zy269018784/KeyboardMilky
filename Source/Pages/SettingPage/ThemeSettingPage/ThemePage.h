#pragma once
#include <lvgl/lvgl.h>
#include "Point2.h"
#include "Util/List.h"
typedef struct ThemePage
{
	ListNode Node;

	lv_obj_t* Handle;

	lv_obj_t* ImageTheme;

	lv_obj_t* ButtonApply;
	lv_obj_t* LabelApply;
	
	lv_obj_t* LabelThemeTitle;
	
}ThemePage;

typedef struct SettingsThemePage
{
	lv_obj_t* Handle;
#if 0
	lv_obj_t* ReturnRow;
	lv_obj_t* ButtonReturn;
	lv_obj_t* LabelCurrentPage;
	//lv_obj_t* ButtonUSBDownload;
#endif

	lv_obj_t* ContentRow;
	ThemePage Themes[10];
	List ThemePageLists;
}SettingsThemePage;


#ifdef __cplusplus
extern "C"
{
#endif
	void CreateThemePage(ThemePage* Page, lv_obj_t* Parent, const char* Title, int X, int Y, int W, int H, void* Pixels);
#ifdef __cplusplus
}
#endif