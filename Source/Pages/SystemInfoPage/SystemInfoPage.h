#pragma once
#include <lvgl/lvgl.h>
#include "Point2.h"
#include "CPUInfoWidget.h"
#include "MemoryInfoWidget.h"
#include "NetworkInfoWidget.h"
#include "ClockInfoWidget.h"
#include "TempInfoWidget.h"
typedef struct SystemInfoPage
{
	lv_obj_t* Parent;
	lv_obj_t* Handle;
	

	lv_obj_t* Widget1;
	lv_obj_t* Widget2;
	lv_obj_t* Widget3;
	int Widget1_Width;
	int Widget1_Height;
	int Widget2_Width;
	int Widget2_Height;
	int Widget3_Width;
	int Widget3_Height;

	int Widget1_X;
	int Widget1_Y;
	int Widget2_X;
	int Widget2_Y;
	int Widget3_X;
	int Widget3_Y;

	CPUInfoWidget  CPUInfo;
	TempInfoWidget TempInfo;
	ClockInfoWidget ClockInfo;
	NetworkInfoWidget NetworkInfo;
	MemoryInfoWidget MemoryInfo;
}SystemInfoPage;

#ifdef __cplusplus
extern "C"
{
#endif
	void CreateSystemInfoPage(SystemInfoPage* Page, lv_obj_t* Parent);
#ifdef __cplusplus
}
#endif