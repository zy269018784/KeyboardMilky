#include "../Application.h"
void ShowPage(Application* App, int PageIndex, int SubPageIndex);

void  CallbaShowHomePage(lv_event_t* e)
{  
	ShowPage(App, HomePageNum, 0);
}

void CallbaShowMusicPage(lv_event_t* e)
{
	ShowPage(App, MusicPageNum, 0);
}

void  CallbaShowClockPage(lv_event_t* e)
{
	ShowPage(App, ClockPageNum, 0);
}

void  CallbaShowSystemInfoPage(lv_event_t* e)
{
	ShowPage(App, SystemInfoPageNum, 0);
}

void  CallbaShowSettingPage(lv_event_t* e)
{
	ShowPage(App, SettingPageNum, SETTING_HOME_PAGE_NUM);
}

void  CallbaShowThemeSettingPage(lv_event_t* e)
{
	ShowPage(App, SettingPageNum, THEME_PAGE_NUM);
}

void  CallbaShowWallpapperSettingPage(lv_event_t* e)
{
	ShowPage(App, SettingPageNum, WALLPAPER_PAGE_NUM);
}

void  CallbaShowDockSettingPage(lv_event_t* e)
{
	ShowPage(App, SettingPageNum, DOCK_PAGE_NUM);
}

void  CallbaShowClockSettingPage(lv_event_t* e)
{
	ShowPage(App, SettingPageNum, CLOCK_PAGE_NUM);
}

void  CallbaShowOtherSettingPage(lv_event_t* e)
{
	ShowPage(App, SettingPageNum, OTHER_PAGE_NUM);
}

void  CallbaShowUpgradeSettingPage(lv_event_t* e)
{
	ShowPage(App, SettingPageNum, UPDATE_PAGE_NUM);
}

void InitEventHandle()
{
	if (!App)
	{
		printf("App is Null\n");
		return;
	}
	lv_obj_add_event_cb(App->ButtonHomePage,							CallbaShowHomePage,					LV_EVENT_CLICKED, NULL);
	lv_obj_add_event_cb(App->ButtonMusic,								CallbaShowMusicPage,				LV_EVENT_CLICKED, NULL);
	lv_obj_add_event_cb(App->ButtonClock,								CallbaShowClockPage,				LV_EVENT_CLICKED, NULL);
	lv_obj_add_event_cb(App->ButtonSystemInfo,							CallbaShowSystemInfoPage,			LV_EVENT_CLICKED, NULL);
	lv_obj_add_event_cb(App->ButtonSetting,								CallbaShowSettingPage,				LV_EVENT_CLICKED, NULL);
	lv_obj_add_event_cb(App->PageSettings.PageHome.ButtonTheme,			CallbaShowThemeSettingPage,			LV_EVENT_CLICKED, NULL);
	lv_obj_add_event_cb(App->PageSettings.PageHome.ButtonWallpapper,	CallbaShowWallpapperSettingPage,	LV_EVENT_CLICKED, NULL);
	lv_obj_add_event_cb(App->PageSettings.PageHome.ButtonDock,			CallbaShowDockSettingPage,			LV_EVENT_CLICKED, NULL);
	lv_obj_add_event_cb(App->PageSettings.PageHome.ButtonClock,			CallbaShowClockSettingPage,			LV_EVENT_CLICKED, NULL);
	lv_obj_add_event_cb(App->PageSettings.PageHome.ButtonOther,			CallbaShowOtherSettingPage,			LV_EVENT_CLICKED, NULL);
	lv_obj_add_event_cb(App->PageSettings.PageHome.ButtonUpdate,		CallbaShowUpgradeSettingPage,		LV_EVENT_CLICKED, NULL);	
	
	lv_obj_add_event_cb(App->PageSettings.PageTheme.ButtonReturn,		CallbaShowSettingPage, LV_EVENT_CLICKED, NULL);
	lv_obj_add_event_cb(App->PageSettings.PageWallpapper.ButtonReturn,	CallbaShowSettingPage, LV_EVENT_CLICKED, NULL);
}