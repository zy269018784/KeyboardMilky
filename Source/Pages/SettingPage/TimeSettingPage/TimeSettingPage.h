#pragma once
#include "lvgl/lvgl.h"
/*
	需求:
		时间日期设置			自动获取
								手动选择时区
								手动设置时间、日期
		是否显示时间			是否在首页显示时间
		时间格式				24:00或12:00 AM
		日期格式				英文：9 August 2025或9 August或9 Aug
								中文：2025年8月9日或2025.8.9或8月9日
		时间、日期位置选择		靠左/靠右
*/

typedef struct SettingsClockPage
{
	lv_obj_t* Handle;
	/*
		时间日期设置			自动获取
	*/
	lv_obj_t* LabelAutoGetTime;
	lv_obj_t* SwitchAutoGetTime;
	/*
		手动选择时区
	*/
	lv_obj_t* LabelTimeZone;
	lv_obj_t* DropdownTimeZone;
	/*
		手动设置时间、日期
	*/
	lv_obj_t* LabelDateTime;
	lv_obj_t* DropdownYear;
	lv_obj_t* DropdownMonth;
	lv_obj_t* DropdownDay;
	lv_obj_t* DropdownHour;
	lv_obj_t* DropdownMinute;
	lv_obj_t* DropdownSecond;
	/*
		是否在首页显示时间
	*/
	lv_obj_t* LabelHomePageShowTime;
	lv_obj_t* SwitchHomePageShowTime;
	/*
		时间格式			24:00或12:00 AM
	*/
	lv_obj_t* LabelTimeFormat;
	lv_obj_t* DropdownTimeFormat;
	/*
		日期格式			英文：9 August 2025或9 August或9 Aug
							中文：2025年8月9日或2025.8.9或8月9日
	*/
	lv_obj_t* LabelDateFormat;
	lv_obj_t* DropdownDateFormat;
	/*
		时间、日期位置选择		靠左/靠右
	*/
	lv_obj_t* LabelTimePos;
	lv_obj_t* DropdownTimePos;
}SettingsClockPage;