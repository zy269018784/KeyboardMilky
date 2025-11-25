#pragma once
#include <lvgl/lvgl.h>
#include "Point2.h"
#include "Widgets/VolumeWidget.h"
typedef struct HomePage
{
	lv_obj_t* Parent;
	lv_obj_t* Handle;
	/*
		大小写
	*/
	lv_obj_t* CapsLock;
	/*
		静音图标
	*/
	lv_obj_t* ImageMuted;
	/*
		音量控件
	*/
	VolumeWidget Volume;
	/*
		时间
	*/
	lv_obj_t* LabelTime;
	lv_obj_t* LabelWeekDay;
}HomePage;


#ifdef __cplusplus
extern "C"
{
#endif
	void CreateHomePage(HomePage* Page, lv_obj_t* Parent);
#ifdef __cplusplus
}
#endif