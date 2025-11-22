#pragma once
#include <lvgl/lvgl.h>
#include "Point2.h"

// 定义播放和暂停图标
#define PLAY_ICON  LV_SYMBOL_PLAY
#define PAUSE_ICON LV_SYMBOL_PAUSE

// 播放状态枚举
typedef enum {
	MUSIC_STATE_PLAYING,
	MUSIC_STATE_PAUSED
} MusicPlayState;

typedef struct MusicPage
{
	lv_obj_t* Parent;
	lv_obj_t* Handle;
	/*
		控件
			专辑（歌词、图片块）
			上一曲按钮
			下一曲按钮
			播放按钮
			进度条
			播放状态
	*/
	lv_obj_t* prev_button;
	lv_obj_t* prev_label;
	lv_obj_t* next_button;
	lv_obj_t* next_label;
	lv_obj_t* play_button;
	lv_obj_t* play_label;
	lv_obj_t* album_rect;
	lv_obj_t* music_name_rect;
	lv_obj_t* singer_name_rect;
	lv_obj_t* user_rect;
	lv_obj_t* play_buttons_widgets;

	lv_obj_t* music_name_label;
	Point2    music_name_label_size;
	Point2    music_name_label_pos;

	lv_obj_t* singer_name_label;
	Point2    singer_name_label_size;
	Point2    singer_name_label_pos;

	lv_obj_t* progress_bar;
	Point2    progress_bar_size;
	Point2    progress_bar_pos;

	MusicPlayState play_state;

}MusicPage;

#ifdef __cplusplus
extern "C"
{
#endif
	void CreateMusicPage(MusicPage* Page, lv_obj_t* Parent);
	void CreatePlayBtn(MusicPage* Page);
	void CreateMusicNameLabel(MusicPage* Page);
	void CreateSingerNameLabel(MusicPage* Page);
	void SetMusicPlayState(MusicPage* Page, bool is_playing);
#ifdef __cplusplus
}
#endif