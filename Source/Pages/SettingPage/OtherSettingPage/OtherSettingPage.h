#pragma once
#include <lvgl/lvgl.h>
/*
	需求:
		自动息屏						开启：设置屏幕无操作自动息屏时间：1分钟，2分钟，5分钟，10分钟，20分钟，30分钟
										开启的判定条件：用户一段时间内没有使用键盘的物理按键或触屏
										关闭：屏幕常亮
		通过Pogo-Pin识别自动更换主题	开：若开启，则断电后，每次再通过Pogopin识别面板从而确定主题
										关：若关闭，则在应用主题时保存状态至本地，保证断电重启后仍然是用户指定的主题
		恢复出厂设置					恢复至出厂时版本的初始状态
*/
typedef struct SettingsOtherPage
{
	lv_obj_t* Handle;
	lv_obj_t* Label;

	/*
		自动息屏
	*/
	lv_obj_t* LabelAutoScreenOff;
	lv_obj_t* SwitchAutoScreenOff;

	/*
		自动息屏时间
	*/
	lv_obj_t* LabelAutoScreenOffTime;
	lv_obj_t* DropdownAutoScreenOffTime;

	/*
		通过Pogo-Pin识别自动更换主题
	*/
	lv_obj_t* LabelPogoPin;
	lv_obj_t* SwitchPogoPin;
	/*
		恢复出厂设置
	*/
	lv_obj_t* ButtonFactoryReset;
	lv_obj_t* LabelFactoryReset;
}SettingsOtherPage;