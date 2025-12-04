#include "../Application.h"
#include <lvgl/lvgl.h>
#include <stdio.h>

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
	lv_obj_clear_flag(App->PageClock.stop_button, LV_OBJ_FLAG_HIDDEN);
	lv_obj_add_flag(App->PageClock.start_button, LV_OBJ_FLAG_HIDDEN);

	lv_timer_reset(App->Clock);
	lv_timer_resume(App->Clock);
	//ShowPage(App, ClockPageNum, 1);
}

void  CallbackClockStop(lv_event_t* e)
{
	lv_obj_clear_flag(App->PageClock.start_button, LV_OBJ_FLAG_HIDDEN);
	lv_obj_add_flag(App->PageClock.stop_button, LV_OBJ_FLAG_HIDDEN);

	lv_timer_pause(App->Clock);
}


void  CallbackClockTimeUp(lv_timer_t* e)
{
	printf("CallbackClockTimeUp\n");
	lv_timer_pause(App->Clock);

	lv_obj_add_flag(App->PageClock.Handle, LV_OBJ_FLAG_HIDDEN);
	lv_obj_clear_flag(App->PageClock.TimeUpPageHandle, LV_OBJ_FLAG_HIDDEN);

	lv_obj_add_flag(App->PageClock.stop_button, LV_OBJ_FLAG_HIDDEN);
	lv_obj_clear_flag(App->PageClock.start_button, LV_OBJ_FLAG_HIDDEN);
}


void  CallbackDockBarTimerStart(lv_event_t* e)
{
	lv_timer_reset(App->DockBarTimer);
	lv_timer_resume(App->DockBarTimer);
}

void  CallbackDockBarTimerStop(lv_event_t* e)
{
	lv_timer_pause(App->DockBarTimer);
}

void  CallbackDockBarTimerUp(lv_timer_t* e)
{
	//lv_obj_add_flag(App->RowLayout, LV_OBJ_FLAG_HIDDEN);
	lv_obj_set_style_bg_opa(App->RowLayout, LV_OPA_0, 0);
}

void  CallbackClockReturn(lv_event_t* e)
{
	lv_obj_add_flag(App->PageClock.TimeUpPageHandle, LV_OBJ_FLAG_HIDDEN);
	lv_obj_clear_flag(App->PageClock.Handle, LV_OBJ_FLAG_HIDDEN);
}

void CallbackDockBarHovered(lv_event_t* e)
{
	lv_obj_t* obj = lv_event_get_target_obj(e);
	if (lv_obj_has_state(obj, LV_STATE_HOVERED))
	{
		//lv_obj_clear_flag(App->RowLayout, LV_OBJ_FLAG_HIDDEN);
		lv_obj_set_style_bg_opa(App->RowLayout, LV_OPA_COVER, 0);
		printf("App->RowLayout hovered\n");
	}
}

void  CallbackAutoHideDock(lv_event_t* e)
{
	lv_obj_t* obj = lv_event_get_target_obj(e);
	App->Setings.AutoHideDock = false;
	CallbackDockBarTimerStop(e);
	if (lv_obj_has_state(obj, LV_STATE_CHECKED)) {
		App->Setings.AutoHideDock = true;
		CallbackDockBarTimerStart(e);
	}
	printf("AutoHideDock: %d\n", App->Setings.AutoHideDock);
}

void  CallbackShowDock(lv_event_t* e)
{
	lv_obj_t* obj = lv_event_get_target_obj(e);
	App->Setings.ShowDock = false;
	//lv_obj_add_flag(App->RowLayout, LV_OBJ_FLAG_HIDDEN);
	/*
	 * 透明代替隐藏
	 */
	lv_obj_set_style_bg_opa(App->RowLayout, LV_OPA_0,  0);
	if (lv_obj_has_state(obj, LV_STATE_CHECKED))
	{
		App->Setings.ShowDock = true;
		//lv_obj_clear_flag(App->RowLayout, LV_OBJ_FLAG_HIDDEN);
		/*
		 *	不透明代表显示
		 */
		lv_obj_set_style_bg_opa(App->RowLayout, LV_OPA_COVER,0);
	}
	printf("ShowDock: %d\n", App->Setings.ShowDock);
}

void  CallbackAutoGetTime(lv_event_t* e)
{
	lv_obj_t* obj = lv_event_get_target_obj(e);
	App->Setings.AutoGetTime = false;
	if (lv_obj_has_state(obj, LV_STATE_CHECKED))
		App->Setings.AutoGetTime = true;
	printf("AutoGetTime: %d\n", App->Setings.AutoGetTime);
}

void  CallbackHomePageShowTime(lv_event_t* e)
{
	lv_obj_t* obj = lv_event_get_target_obj(e);
	App->Setings.HomePageShowTime = false;
	if (lv_obj_has_state(obj, LV_STATE_CHECKED))
		App->Setings.HomePageShowTime = true;

	lv_obj_clear_flag(App->PageHome.LabelTime, LV_OBJ_FLAG_HIDDEN);
	lv_obj_clear_flag(App->PageHome.LabelWeekDay, LV_OBJ_FLAG_HIDDEN);
	if (!App->Setings.HomePageShowTime)
	{
		lv_obj_add_flag(App->PageHome.LabelTime, LV_OBJ_FLAG_HIDDEN);
		lv_obj_add_flag(App->PageHome.LabelWeekDay, LV_OBJ_FLAG_HIDDEN);
	}
	printf("HomePageShowTime: %d\n", App->Setings.HomePageShowTime);
}

void  CallbackYear(lv_event_t* e)
{
	//printf("CallbackYear\n");
	lv_event_code_t code = lv_event_get_code(e);
	lv_obj_t* obj = lv_event_get_target_obj(e);
	if (code == LV_EVENT_VALUE_CHANGED) {
		lv_dropdown_get_selected_str(obj, App->Setings.Year, sizeof(App->Setings.Year));
		printf("year: %s\n", App->Setings.Year);
	}
}

void  CallbackMonth(lv_event_t* e)
{
	lv_event_code_t code = lv_event_get_code(e);
	lv_obj_t* obj = lv_event_get_target_obj(e);
	if (code == LV_EVENT_VALUE_CHANGED) {
		lv_dropdown_get_selected_str(obj, App->Setings.Month, sizeof(App->Setings.Month));
		printf("Month: %s\n", App->Setings.Month);
	}
}

void  CallbackDay(lv_event_t* e)
{
	lv_event_code_t code = lv_event_get_code(e);
	lv_obj_t* obj = lv_event_get_target_obj(e);
	if (code == LV_EVENT_VALUE_CHANGED) {
		lv_dropdown_get_selected_str(obj, App->Setings.Day, sizeof(App->Setings.Day));
		printf("Day: %s\n", App->Setings.Day);
	}
}

void  CallbackHour(lv_event_t* e)
{
	lv_event_code_t code = lv_event_get_code(e);
	lv_obj_t* obj = lv_event_get_target_obj(e);
	if (code == LV_EVENT_VALUE_CHANGED) {
		lv_dropdown_get_selected_str(obj, App->Setings.Hour, sizeof(App->Setings.Hour));
		printf("Hour: %s\n", App->Setings.Hour);
	}
}

void  CallbackMinute(lv_event_t* e)
{
	lv_event_code_t code = lv_event_get_code(e);
	lv_obj_t* obj = lv_event_get_target_obj(e);
	if (code == LV_EVENT_VALUE_CHANGED) {
		lv_dropdown_get_selected_str(obj, App->Setings.Minute, sizeof(App->Setings.Minute));
		printf("Minute: %s\n", App->Setings.Minute);
	}
}

void  CallbackSecond(lv_event_t* e)
{
	lv_event_code_t code = lv_event_get_code(e);
	lv_obj_t* obj = lv_event_get_target_obj(e);
	if (code == LV_EVENT_VALUE_CHANGED) {
		lv_dropdown_get_selected_str(obj, App->Setings.Second, sizeof(App->Setings.Second));
		printf("Second: %s\n", App->Setings.Second);
	}
}

void  CallbackTimeZone(lv_event_t* e)
{
	lv_event_code_t code = lv_event_get_code(e);
	lv_obj_t* obj = lv_event_get_target_obj(e);
	if (code == LV_EVENT_VALUE_CHANGED) {
		App->Setings.TimeZone = lv_dropdown_get_selected(obj);
		printf("TimeZone: %u\n", App->Setings.TimeZone);
	}
}

void  CallbackTimeFormat(lv_event_t* e)
{
	lv_event_code_t code = lv_event_get_code(e);
	lv_obj_t* obj = lv_event_get_target_obj(e);
	if (code == LV_EVENT_VALUE_CHANGED) {
		int Index = lv_dropdown_get_selected(obj);
		App->Setings.TimeFormat24 = false;
		if (1 == Index)
			App->Setings.TimeFormat24 = true;
		printf("TimeFormat24: %d\n", App->Setings.TimeFormat24);
	}
}

void  CallbackDateFormat(lv_event_t* e)
{
	lv_event_code_t code = lv_event_get_code(e);
	lv_obj_t* obj = lv_event_get_target_obj(e);
	if (code == LV_EVENT_VALUE_CHANGED) {
		App->Setings.DateFormat = lv_dropdown_get_selected(obj);
		printf("DateFormat: %u\n", App->Setings.DateFormat);
	}
}

void  CallbackTimePos(lv_event_t* e)
{
	lv_event_code_t code = lv_event_get_code(e);
	lv_obj_t* obj = lv_event_get_target_obj(e);
	if (code == LV_EVENT_VALUE_CHANGED) {
		int Index = lv_dropdown_get_selected(obj);
		App->Setings.TimePosLeft = false;
		if (0 == Index)
			App->Setings.TimePosLeft = true;
		printf("TimePosLeft: %d\n", App->Setings.TimePosLeft);
	}
}

void  CallbackAutoScreenOff(lv_event_t* e)
{
	lv_obj_t* obj = lv_event_get_target_obj(e);
	App->Setings.AutoScreenOff = false;
	if (lv_obj_has_state(obj, LV_STATE_CHECKED))
		App->Setings.AutoScreenOff = true;
	printf("AutoScreenOff: %d\n", App->Setings.AutoScreenOff);
}

void  CallbackPogoPin(lv_event_t* e)
{
	lv_obj_t* obj = lv_event_get_target_obj(e);
	App->Setings.PogoPin = false;
	if (lv_obj_has_state(obj, LV_STATE_CHECKED))
		App->Setings.PogoPin = true;
	printf("PogoPin: %d\n", App->Setings.PogoPin);
}

void  CallbackAutoScreenOffTime(lv_event_t* e)
{
	lv_event_code_t code = lv_event_get_code(e);
	lv_obj_t* obj = lv_event_get_target_obj(e);
	if (code == LV_EVENT_VALUE_CHANGED) {
		App->Setings.ScreenOffTime = lv_dropdown_get_selected(obj);
		printf("ScreenOffTime: %u\n", App->Setings.ScreenOffTime);
	}
}

/*
	��Ļ�����¼�
*/
void  CallbackGesture(lv_event_t* e)
{
	lv_event_code_t code = lv_event_get_code(e);
	lv_obj_t* obj = lv_event_get_target(e);

	if (code == LV_EVENT_GESTURE) {
		lv_dir_t dir = lv_indev_get_gesture_dir(lv_event_get_indev(e));

		switch (dir) {
		case LV_DIR_RIGHT:
			App->CurrentPage -= 1;
			if (App->CurrentPage < 0)
				App->CurrentPage = KeyboardPageNum;
			ShowPage(App, App->CurrentPage, 0);
			printf("left\n");
			break;
		case LV_DIR_LEFT:
			App->CurrentPage += 1;
			if (SettingPageNum < App->CurrentPage)
				App->CurrentPage = HomePageNum;
			ShowPage(App, App->CurrentPage, 0);
			printf("right\n");
			break;
		case LV_DIR_TOP:
			lv_obj_clear_flag(App->PageHome.Volume.Handle, LV_OBJ_FLAG_HIDDEN);
			lv_timer_reset(App->VolumeTimer);
			lv_timer_resume(App->VolumeTimer);
			printf("top\n");
			break;
		case LV_DIR_BOTTOM:
			lv_obj_add_flag(App->PageHome.Volume.Handle, LV_OBJ_FLAG_HIDDEN);
			printf("bottom\n");
			break;
		default:
			break;
		}
	}
}

void  CallbackVoulueTimeOut(lv_timer_t* e)
{
	lv_obj_add_flag(App->PageHome.Volume.Handle, LV_OBJ_FLAG_HIDDEN);
	lv_timer_pause(App->VolumeTimer);
}

void  CallbackLongPressed(lv_event_t* e)
{
	lv_event_code_t code = lv_event_get_code(e);
	//if (code == LV_EVENT_LONG_PRESSED || code == LV_EVENT_LONG_PRESSED_REPEAT)
	//printf("long pressed\n");

	if (code == LV_EVENT_GESTURE)
	{
		CallbackGesture(e);
	}
}



void InitEventHandle()
{
	if (!App)
	{
		printf("App is Null\n");
		return;
	}

	/*
	 * Docker Bar
	 */
	lv_obj_add_event_cb(App->RowLayout, CallbackDockBarHovered, LV_EVENT_HOVER_OVER, NULL);
	/*
		�����¼�
	*/
	//lv_obj_add_event_cb(lv_screen_active(), CallbackGesture, LV_EVENT_GESTURE, NULL);
	
	/*
		�����¼�
	*/
	//lv_indev_set_long_press_time(lv_indev_get_next(NULL), 500);
	//lv_indev_set_long_press_repeat_time(lv_indev_get_next(NULL), 150);
	lv_obj_add_event_cb(lv_screen_active(), CallbackLongPressed, LV_EVENT_ALL, NULL);

	/*
		Dock��
	*/
	lv_obj_add_event_cb(App->ButtonHomePage,							CallbackShowHomePage,				LV_EVENT_CLICKED, NULL);
	lv_obj_add_event_cb(App->ButtonMusic,								CallbackShowMusicPage,				LV_EVENT_CLICKED, NULL);
	lv_obj_add_event_cb(App->ButtonClock,								CallbackShowClockPage,				LV_EVENT_CLICKED, NULL);
	lv_obj_add_event_cb(App->ButtonSystemInfo,							CallbackShowSystemInfoPage,			LV_EVENT_CLICKED, NULL);
	lv_obj_add_event_cb(App->ButtonSetting,								CallbackShowSettingPage,			LV_EVENT_CLICKED, NULL);

	/*
		������ҳ
	*/
	lv_obj_add_event_cb(App->PageSettings.PageHome.ButtonTheme,			CallbackShowThemeSettingPage,		LV_EVENT_CLICKED, NULL);
	lv_obj_add_event_cb(App->PageSettings.PageHome.ButtonWallpapper,	CallbackShowWallpapperSettingPage,	LV_EVENT_CLICKED, NULL);
	lv_obj_add_event_cb(App->PageSettings.PageHome.ButtonDock,			CallbackShowDockSettingPage,		LV_EVENT_CLICKED, NULL);
	lv_obj_add_event_cb(App->PageSettings.PageHome.ButtonClock,			CallbackShowClockSettingPage,		LV_EVENT_CLICKED, NULL);
	lv_obj_add_event_cb(App->PageSettings.PageHome.ButtonOther,			CallbackShowOtherSettingPage,		LV_EVENT_CLICKED, NULL);
	lv_obj_add_event_cb(App->PageSettings.PageHome.ButtonUpdate,		CallbackShowUpgradeSettingPage,		LV_EVENT_CLICKED, NULL);	

	/*
		ʱ��
	*/
	App->Clock = lv_timer_create(&CallbackClockTimeUp, 5000, NULL);
	lv_timer_pause(App->Clock);

	App->VolumeTimer = lv_timer_create(&CallbackVoulueTimeOut, 5000, NULL);
	lv_timer_pause(App->VolumeTimer);

	App->DockBarTimer = lv_timer_create(&CallbackDockBarTimerUp, 5000, NULL);
	lv_timer_pause(App->DockBarTimer);

	/*
		����ҳ
	*/
	lv_obj_add_event_cb(App->PageSettings.ButtonReturn,		CallbackShowSettingPage, LV_EVENT_CLICKED, NULL);
	/*
		��ֽҳ
	*/
	lv_obj_add_event_cb(App->PageSettings.ButtonReturn,	CallbackShowSettingPage, LV_EVENT_CLICKED, NULL);
	/*
		ʱ��ҳ
	*/
	lv_obj_add_event_cb(App->PageClock.start_button, CallbackClockStart, LV_EVENT_CLICKED, NULL);
	lv_obj_add_event_cb(App->PageClock.stop_button, CallbackClockStop, LV_EVENT_CLICKED, NULL);
	lv_obj_add_event_cb(App->PageClock.back_button, CallbackClockReturn, LV_EVENT_CLICKED, NULL);

	/*
		Clock����
	*/
	lv_obj_add_event_cb(App->PageSettings.PageClock.SwitchAutoGetTime, CallbackAutoGetTime, LV_EVENT_CLICKED, NULL);
	lv_obj_add_event_cb(App->PageSettings.PageClock.SwitchHideTime, CallbackHomePageShowTime, LV_EVENT_CLICKED, NULL);
#if 0
	lv_obj_add_event_cb(App->PageSettings.PageClock.DropdownYear,	CallbackYear, LV_EVENT_ALL, NULL);
	lv_obj_add_event_cb(App->PageSettings.PageClock.DropdownMonth,	CallbackMonth, LV_EVENT_ALL, NULL);
	lv_obj_add_event_cb(App->PageSettings.PageClock.DropdownDay,	CallbackDay, LV_EVENT_ALL, NULL);
	lv_obj_add_event_cb(App->PageSettings.PageClock.DropdownHour,	CallbackHour, LV_EVENT_ALL, NULL);
	lv_obj_add_event_cb(App->PageSettings.PageClock.DropdownMinute, CallbackMinute, LV_EVENT_ALL, NULL);
	lv_obj_add_event_cb(App->PageSettings.PageClock.DropdownSecond, CallbackSecond, LV_EVENT_ALL, NULL);
	lv_obj_add_event_cb(App->PageSettings.PageClock.DropdownSecond, CallbackSecond, LV_EVENT_ALL, NULL);

	lv_obj_add_event_cb(App->PageSettings.PageClock.DropdownTimeZone,   CallbackTimeZone, LV_EVENT_ALL, NULL);
	lv_obj_add_event_cb(App->PageSettings.PageClock.DropdownTimeFormat, CallbackTimeFormat, LV_EVENT_ALL, NULL);
	lv_obj_add_event_cb(App->PageSettings.PageClock.DropdownDateFormat, CallbackDateFormat, LV_EVENT_ALL, NULL);
	lv_obj_add_event_cb(App->PageSettings.PageClock.DropdownTimePos, CallbackTimePos, LV_EVENT_ALL, NULL);
#endif

	/*
		Dock����
	*/
	lv_obj_add_event_cb(App->PageSettings.PageDock.SwitchAutoHideDock, CallbackAutoHideDock, LV_EVENT_CLICKED, NULL);
	lv_obj_add_event_cb(App->PageSettings.PageDock.SwitchShowDock, CallbackShowDock, LV_EVENT_CLICKED, NULL);

	/*
		��������
	*/
	lv_obj_add_event_cb(App->PageSettings.PageOther.SwitchAutoScreenOff,	CallbackAutoScreenOff, LV_EVENT_CLICKED, NULL);
	lv_obj_add_event_cb(App->PageSettings.PageOther.SwitchPogoPin,			CallbackPogoPin, LV_EVENT_CLICKED, NULL);
	lv_obj_add_event_cb(App->PageSettings.PageOther.DropdownAutoScreenOffTime, CallbackAutoScreenOffTime, LV_EVENT_ALL, NULL);
}