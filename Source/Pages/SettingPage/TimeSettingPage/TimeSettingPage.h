#pragma once
#include "lvgl/lvgl.h"
/*
	����:
		ʱ����������			�Զ���ȡ
								�ֶ�ѡ��ʱ��
								�ֶ�����ʱ�䡢����
		�Ƿ���ʾʱ��			�Ƿ�����ҳ��ʾʱ��
		ʱ���ʽ				24:00��12:00 AM
		���ڸ�ʽ				Ӣ�ģ�9 August 2025��9 August��9 Aug
								���ģ�2025��8��9�ջ�2025.8.9��8��9��
		ʱ�䡢����λ��ѡ��		����/����
*/

typedef struct SettingsClockPage
{
	lv_obj_t* Handle;

	lv_obj_t* LabelAutoGetTime;
	lv_obj_t* SwitchAutoGetTime;

	//lv_obj_t* LabelTimeZone;
	//lv_obj_t* DropdownTimeZone;

	//lv_obj_t* LabelDateTime;
	//lv_obj_t* DropdownYear;
	//lv_obj_t* DropdownMonth;
	//lv_obj_t* DropdownDay;
	//lv_obj_t* DropdownHour;
	//lv_obj_t* DropdownMinute;
	//lv_obj_t* DropdownSecond;

	lv_obj_t* LabelHideTime;
	lv_obj_t* SwitchHideTime;

	lv_obj_t* LabeHideDate;
	lv_obj_t* SwitchHideDate;

	//lv_obj_t* LabelTimeFormat;
	//lv_obj_t* DropdownTimeFormat;

	//lv_obj_t* LabelDateFormat;
	//lv_obj_t* DropdownDateFormat;

	//lv_obj_t* LabelTimePos;
	//lv_obj_t* DropdownTimePos;
}SettingsClockPage;