#pragma once
#include <lvgl/lvgl.h>

typedef struct SettingsDockPage
{
	lv_obj_t* Handle;
	/*
		是否显示Dock栏
	*/
	lv_obj_t* LabelShowDock;
	lv_obj_t* SwitchShowDock;
	/*
		Dock栏自动隐藏
	*/
	lv_obj_t* LabelAutoHideDock;
	lv_obj_t* SwitchAutoHideDock;
}SettingsDockPage;
