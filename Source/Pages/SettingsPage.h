#pragma once
#include <lvgl/lvgl.h>
#include "Point2.h"
#include "ThemePage.h"
#include "WallpapperPage.h"

typedef enum {
	SETTING_HOME_PAGE_NUM = 0,
	THEME_PAGE_NUM = 1,
	WALLPAPER_PAGE_NUM = 2,
	DOCK_PAGE_NUM = 3,
	CLOCK_PAGE_NUM = 4,
	OTHER_PAGE_NUM = 5,
	UPDATE_PAGE_NUM = 6
}SettingPageNumber;

typedef struct SettingsHomePage
{
	lv_obj_t* Handle;

	lv_obj_t* ButtonWallpapper;
	lv_obj_t* ButtonTheme;
	lv_obj_t* ButtonDock;
	lv_obj_t* ButtonClock;
	lv_obj_t* ButtonOther;
	lv_obj_t* ButtonUpdate;

	lv_obj_t* LabelWallpapper;
	lv_obj_t* LabelTheme;
	lv_obj_t* LabelDock;
	lv_obj_t* LabelClock;
	lv_obj_t* LabelOther;
	lv_obj_t* LabelUpdate;

}SettingsHomePage;

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
}SettingsWallpapperPage;

typedef struct SettingsThemePage
{
	lv_obj_t* Handle;
	lv_obj_t* Label;

	lv_obj_t* ReturnRow;
	lv_obj_t* ButtonReturn;
	lv_obj_t* LabelCurrentPage;
	lv_obj_t* ButtonUSBDownload;

	lv_obj_t* ContentRow;
	ThemePage Themes[10];
}SettingsThemePage;

typedef struct SettingsDockPage
{
	lv_obj_t* Handle;
	lv_obj_t* Label;
}SettingsDockPage;

typedef struct SettingsClockPage
{
	lv_obj_t* Handle;
	lv_obj_t* Label;
}SettingsClockPage;

typedef struct SettingsOtherPage
{
	lv_obj_t* Handle;
	lv_obj_t* Label;
}SettingsOtherPage;

typedef struct SettingsUpdatePage
{
	lv_obj_t* Handle;
	lv_obj_t* Label;
}SettingsUpdatePage;

typedef struct SettingsPage
{
	lv_obj_t* Parent;

	lv_obj_t* Handle;

	SettingsHomePage PageHome;
	SettingsWallpapperPage PageWallpapper;
	SettingsThemePage PageTheme;
	SettingsDockPage PageDock;
	SettingsClockPage PageClock;
	SettingsOtherPage PageOther;
	SettingsUpdatePage PageUpdate;

	//ThemePage ThemeSettingPage;
	//WallpapperPage WallpapperSettingPage;
}SettingsPage;


#ifdef __cplusplus
extern "C"
{
#endif
	void CreateSettingsPage(SettingsPage* Page, lv_obj_t* Parent);
	void ShowSettingPage(SettingsPage* Page, int PageNo);
#ifdef __cplusplus
}
#endif