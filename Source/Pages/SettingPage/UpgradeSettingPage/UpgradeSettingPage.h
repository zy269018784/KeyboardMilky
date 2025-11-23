#pragma once
#include <lvgl/lvgl.h>
/*
	需求:
		显示当前版本				展示当前的版本号
		检查是否有新的版本			检查当前状态是否有新版本可供更新
		海外版和国内版分开推送		将海外版与国内版分开进行推送新版本
*/

typedef struct SettingsUpdatePage
{
	lv_obj_t* Handle;
	lv_obj_t* Label;

	/*
		显示当前版本	
	*/
	lv_obj_t* LabelCurrentVersion1;
	lv_obj_t* LabelCurrentVersion2;

	/*
		检查是否有新的版本
	*/
	lv_obj_t* ButtonCheckNewVersion;
	lv_obj_t* LabelCheckNewVersion;
	lv_obj_t* LabelNewVersion;
}SettingsUpdatePage;
