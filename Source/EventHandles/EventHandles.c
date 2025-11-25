#include "../Application.h"
#include <lvgl/lvgl.h>
void ShowPage(Application* App, int PageIndex, int SubPageIndex);

void  CallbackShowHomePage(lv_event_t* e)
{  
	ShowPage(App, HomePageNum, 0);
	//ShowPage(App, KeyboardPageNum, 0);
}

void CallbackShowMusicPage(lv_event_t* e)
{
	ShowPage(App, MusicPageNum, 0);
}

void  CallbackShowClockPage(lv_event_t* e)
{
	ShowPage(App, ClockPageNum, 0);
}

void  CallbackShowSystemInfoPage(lv_event_t* e)
{
	ShowPage(App, SystemInfoPageNum, 0);
}

void  CallbackShowSettingPage(lv_event_t* e)
{
	ShowPage(App, SettingPageNum, SETTING_HOME_PAGE_NUM);
}

void  CallbackShowThemeSettingPage(lv_event_t* e)
{
	ShowPage(App, SettingPageNum, THEME_PAGE_NUM);
}

void  CallbackShowWallpapperSettingPage(lv_event_t* e)
{
	ShowPage(App, SettingPageNum, WALLPAPER_PAGE_NUM);
}

void  CallbackShowDockSettingPage(lv_event_t* e)
{
	ShowPage(App, SettingPageNum, DOCK_PAGE_NUM);
}

void  CallbackShowClockSettingPage(lv_event_t* e)
{
	ShowPage(App, SettingPageNum, CLOCK_PAGE_NUM);
}

void  CallbackShowOtherSettingPage(lv_event_t* e)
{
	ShowPage(App, SettingPageNum, OTHER_PAGE_NUM);
}

void  CallbackShowUpgradeSettingPage(lv_event_t* e)
{
	ShowPage(App, SettingPageNum, UPDATE_PAGE_NUM);
}

void  CallbackClockStart(lv_event_t* e)
{
	//lv_obj_clear_flag(App->PageClock.stop_button, LV_OBJ_FLAG_HIDDEN);
	//lv_obj_add_flag(App->PageClock.start_button, LV_OBJ_FLAG_HIDDEN);

	ShowPage(App, ClockPageNum, 1);
}

void  CallbackClockStop(lv_event_t* e)
{
	lv_obj_clear_flag(App->PageClock.start_button, LV_OBJ_FLAG_HIDDEN);
	lv_obj_add_flag(App->PageClock.stop_button, LV_OBJ_FLAG_HIDDEN);
}

void  CallbackClockReturn(lv_event_t* e)
{
	lv_obj_add_flag(App->PageClock.TimeUpPageHandle, LV_OBJ_FLAG_HIDDEN);
	lv_obj_clear_flag(App->PageClock.Handle, LV_OBJ_FLAG_HIDDEN);
}


void InitEventHandle()
{
	if (!App)
	{
		printf("App is Null\n");
		return;
	}
	lv_obj_add_event_cb(App->ButtonHomePage,							CallbackShowHomePage,				LV_EVENT_CLICKED, NULL);
	lv_obj_add_event_cb(App->ButtonMusic,								CallbackShowMusicPage,				LV_EVENT_CLICKED, NULL);
	lv_obj_add_event_cb(App->ButtonClock,								CallbackShowClockPage,				LV_EVENT_CLICKED, NULL);
	lv_obj_add_event_cb(App->ButtonSystemInfo,							CallbackShowSystemInfoPage,			LV_EVENT_CLICKED, NULL);
	lv_obj_add_event_cb(App->ButtonSetting,								CallbackShowSettingPage,			LV_EVENT_CLICKED, NULL);
	lv_obj_add_event_cb(App->PageSettings.PageHome.ButtonTheme,			CallbackShowThemeSettingPage,		LV_EVENT_CLICKED, NULL);
	lv_obj_add_event_cb(App->PageSettings.PageHome.ButtonWallpapper,	CallbackShowWallpapperSettingPage,	LV_EVENT_CLICKED, NULL);
	lv_obj_add_event_cb(App->PageSettings.PageHome.ButtonDock,			CallbackShowDockSettingPage,		LV_EVENT_CLICKED, NULL);
	lv_obj_add_event_cb(App->PageSettings.PageHome.ButtonClock,			CallbackShowClockSettingPage,		LV_EVENT_CLICKED, NULL);
	lv_obj_add_event_cb(App->PageSettings.PageHome.ButtonOther,			CallbackShowOtherSettingPage,		LV_EVENT_CLICKED, NULL);
	lv_obj_add_event_cb(App->PageSettings.PageHome.ButtonUpdate,		CallbackShowUpgradeSettingPage,		LV_EVENT_CLICKED, NULL);	
	/*
		Ö÷ÌâÒ³
	*/
	lv_obj_add_event_cb(App->PageSettings.PageTheme.ButtonReturn,		CallbackShowSettingPage, LV_EVENT_CLICKED, NULL);
	/*
		±ÚÖ½Ò³
	*/
	lv_obj_add_event_cb(App->PageSettings.PageWallpapper.ButtonReturn,	CallbackShowSettingPage, LV_EVENT_CLICKED, NULL);
	/*
		Ê±ÖÓÒ³
	*/
	lv_obj_add_event_cb(App->PageClock.start_button, CallbackClockStart, LV_EVENT_CLICKED, NULL);

	lv_obj_add_event_cb(App->PageClock.stop_button, CallbackClockStop, LV_EVENT_CLICKED, NULL);

	lv_obj_add_event_cb(App->PageClock.back_button, CallbackClockReturn, LV_EVENT_CLICKED, NULL);
}