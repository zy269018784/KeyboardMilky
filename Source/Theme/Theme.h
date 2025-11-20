#pragma once
#include "Point2.h"
typedef struct {
	int Index;
	/*
		main_font_color		字体主要颜色
		sub_font_color		字体辅助颜色
		main_color			主要颜色
		sub_color			辅助颜色
		focused_color		选中颜色
	*/
	lv_color_t main_font_color;
	lv_color_t sub_font_color;
	lv_color_t main_color;
	lv_color_t sub_color;
	lv_color_t focused_color;
	/*
		Music
	*/
	Point2 music_cover_size;									//		音乐界面的封面尺寸
	Point2 music_cover_postion;									//		音乐界面的封面位置
	Point2 music_cover_roundness;								//		音乐界面的封面圆角大小
	bool music_play_button_on;									//		音乐界面的播放按钮是否显示
	Point2 music_play_button_size;								//		音乐界面的按钮尺寸
	Point2 music_play_button_postion;							//		音乐界面的按钮位置
	bool music_previous_button_on;								//		音乐界面的上一曲按钮是否显示
	Point2 music_previous_button_size;							//		音乐界面的上一曲按钮尺寸
	Point2 music_previous_button_postion;						//		音乐界面的上一曲按钮位置
	bool music_next_button_on ;									//		音乐界面的下一曲按钮是否显示
	Point2 music_next_button_size;								//		音乐界面的下一曲按钮尺寸
	Point2 music_next_button_postion;							//		音乐界面的下一曲按钮位置
	bool music_progressbar_on;									//		音乐界面的进度条开关
	Point2 music_progressbar_size;								//		音乐界面的进度条尺寸
	Point2 music_progressbar_postion;							//		音乐界面的进度条位置
	bool music_progressbar_vertical;							//		音乐界面的进度条是横向还是纵向

	/*
		Clock
	*/
	Point2 timer_start_button_size;
	Point2 timer_start_button_postion;
	Point2 timer_stop_button_size;
	Point2 timer_stop_button_postion;
	Point2 timer_back_button_size;
	Point2 timer_back_button_postion;
	int timer_setting_time_font_size;
	Point2 timer_setting_time_font_postion;
	int timer_end_time_font_size;
	Point2 timer_end_time_font_postion;
}Theme;


