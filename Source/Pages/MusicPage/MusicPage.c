#include "MusicPage.h"
#include <stdio.h>

LV_IMG_DECLARE(play);
LV_IMG_DECLARE(pause);

static void play_button_click_callback(lv_event_t* e);
void CreatePlayBtnDefaultTheme(MusicPage* Page);
void CreateMusicNameLabelDefaultTheme(MusicPage* Page);
void CreateSingerNameLabelDefaultTheme(MusicPage* Page);
void CreateProgressBarDefaultTheme(MusicPage* Page);
void CreateCtrlBtnsTheme2(MusicPage* Page);

void CreateMusicPage(MusicPage* Page, lv_obj_t* Parent) {
    Page->Parent = Parent;
    Page->Handle = lv_obj_create(Parent);

    lv_obj_set_size(Page->Handle, LV_PCT(100), LV_PCT(100)); // 全屏
    lv_obj_set_style_pad_all(Page->Handle, 0, 0);
    lv_obj_set_style_border_width(Page->Handle, 0, 0);
    lv_obj_set_style_margin_all(Page->Handle, 0, 0);
    lv_obj_set_style_bg_color(Page->Handle, lv_color_hex(0x3966A2), 0);
    lv_obj_set_style_bg_opa(Page->Handle, LV_OPA_COVER, 0);
    lv_obj_set_style_radius(Page->Handle, 0, 0);
    // 关闭滚动条
    lv_obj_clear_flag(Page->Handle, LV_OBJ_FLAG_SCROLLABLE);

    CreatePlayBtnDefaultTheme(Page);
    CreateMusicNameLabelDefaultTheme(Page);
    CreateSingerNameLabelDefaultTheme(Page);
    CreateProgressBarDefaultTheme(Page);
}

void CreateMusicPageTheme2(MusicPage* Page, lv_obj_t* Parent) {
    Page->Parent = Parent;
    Page->Handle = lv_obj_create(Parent);
    lv_obj_set_size(Page->Handle, LV_PCT(100), LV_PCT(100)); // 全屏
    lv_obj_set_style_pad_all(Page->Handle, 10, 0);
    lv_obj_set_style_border_width(Page->Handle, 0, 0);
    lv_obj_set_style_margin_all(Page->Handle, 0, 0);
    lv_obj_set_style_bg_color(Page->Handle, lv_color_hex(0xB7799E), 0);
    lv_obj_set_style_bg_opa(Page->Handle, LV_OPA_COVER, 0);
    lv_obj_set_style_radius(Page->Handle, 0, 0);
    // 关闭滚动条
    lv_obj_clear_flag(Page->Handle, LV_OBJ_FLAG_SCROLLABLE);

    CreateCtrlBtnsTheme2(Page);
};

// 播放按钮
void CreatePlayBtnDefaultTheme(MusicPage* Page) {
    Page->play_button = lv_btn_create(Page->Handle);

    lv_obj_set_size(Page->play_button, 50, 50);
    lv_obj_align(Page->play_button, LV_ALIGN_TOP_RIGHT, -10, 10); // 距离右上角 10px

    lv_obj_set_style_pad_all(Page->play_button, 0, 0);
    lv_obj_set_style_border_width(Page->play_button, 0, 0);
    lv_obj_set_style_margin_all(Page->play_button, 0, 0);
    lv_obj_set_style_bg_color(Page->play_button, lv_color_hex3(0x000), 0);
    lv_obj_set_style_radius(Page->play_button, 25, 0);

    // 确保按钮可点击（通常创建按钮会自动可点击）
    lv_obj_add_flag(Page->play_button, LV_OBJ_FLAG_CLICKABLE);
    // 绑定点击事件回调
    lv_obj_add_event_cb(Page->play_button, play_button_click_callback, LV_EVENT_CLICKED, Page);

    Page->play_state = MUSIC_STATE_PAUSED; // 初始状态为暂停，并创建 imgage
    lv_obj_t* play_img = lv_img_create(Page->play_button);
    /* 初始显示图片 */
    lv_img_set_src(play_img, &play);
    lv_obj_center(play_img);
    lv_img_set_zoom(play_img, 128);

    lv_obj_clear_flag(Page->play_button, LV_OBJ_FLAG_SCROLLABLE);
}
// 音乐名称
void CreateMusicNameLabelDefaultTheme(MusicPage* Page) {
    Page->music_name_label = lv_label_create(Page->Handle);
    lv_label_set_text_static(Page->music_name_label, "Don't Be So Serious");
    lv_obj_set_style_text_align(Page->music_name_label, LV_TEXT_ALIGN_LEFT, 0);
    lv_obj_set_pos(Page->music_name_label, 10, 420 - 70);
    //lv_obj_set_size(Page->music_name_label, LV_PCT(100), 50);
    lv_obj_set_style_text_font(Page->music_name_label, lv_font_get_default(), 0);
    lv_obj_set_style_pad_all(Page->music_name_label, 0, 0);
    lv_obj_set_style_border_width(Page->music_name_label, 0, 0);
    lv_obj_set_style_margin_all(Page->music_name_label, 0, 0);
    lv_obj_set_style_text_color(Page->music_name_label, lv_color_hex3(0xFFF), 0);
    lv_obj_clear_flag(Page->music_name_label, LV_OBJ_FLAG_SCROLLABLE);
}

// 歌手名称
void CreateSingerNameLabelDefaultTheme(MusicPage* Page) {
    Page->singer_name_label = lv_label_create(Page->Handle);
    lv_label_set_text_static(Page->singer_name_label, "Low Roar");
    lv_obj_set_style_text_align(Page->singer_name_label, LV_TEXT_ALIGN_LEFT, 0);
    lv_obj_set_pos(Page->singer_name_label, 10, 420 - 50);
    //lv_obj_set_size(Page->singer_name_label, LV_PCT(100), 50);
    lv_obj_set_style_text_font(Page->music_name_label, lv_font_get_default(), 0);
    lv_obj_set_style_pad_all(Page->singer_name_label, 0, 0);
    lv_obj_set_style_border_width(Page->singer_name_label, 0, 0);
    lv_obj_set_style_margin_all(Page->singer_name_label, 0, 0);
    lv_obj_set_style_text_color(Page->singer_name_label, lv_color_hex3(0xFFF), 0);
    lv_obj_clear_flag(Page->singer_name_label, LV_OBJ_FLAG_SCROLLABLE);
}

// 播放进度条
void CreateProgressBarDefaultTheme(MusicPage* Page) {
    Page->progress_bar = lv_bar_create(Page->Handle);
    lv_bar_set_value(Page->progress_bar, 50, LV_ANIM_OFF);
    lv_obj_set_pos(Page->progress_bar, 10, 390);
    lv_obj_set_size(Page->progress_bar, LV_PCT(95), 10);

    // 主轨道（背景）
    lv_obj_set_style_pad_all(Page->progress_bar, 0, LV_PART_MAIN);
    lv_obj_set_style_border_width(Page->progress_bar, 0, LV_PART_MAIN);
    lv_obj_set_style_margin_all(Page->progress_bar, 0, LV_PART_MAIN);
    lv_obj_set_style_bg_color(Page->progress_bar, lv_color_hex3(0x000), LV_PART_MAIN);
    lv_obj_set_style_bg_opa(Page->progress_bar, LV_OPA_COVER, LV_PART_MAIN);
    lv_obj_set_style_radius(Page->progress_bar, 5, LV_PART_MAIN);

    // 指示器（已完成/填充部分）
    lv_obj_set_style_bg_color(Page->progress_bar, lv_color_hex3(0xFFF), LV_PART_INDICATOR);
    lv_obj_set_style_bg_opa(Page->progress_bar, LV_OPA_COVER, LV_PART_INDICATOR);
    lv_obj_set_style_radius(Page->progress_bar, 5, LV_PART_INDICATOR);

    // 关闭进度条自身的滚动标志
    lv_obj_clear_flag(Page->progress_bar, LV_OBJ_FLAG_SCROLLABLE);
}

// 切换播放状态的函数
void SetMusicPlayState(MusicPage* Page, bool is_playing) {
    printf("SetMusicPlayState is_playing: %d\n", is_playing);

    if (Page == NULL || Page->play_button == NULL) {
        printf("SetMusicPlayState: Page or play_button is NULL\n");
        return;
    }

	lv_obj_t* img = lv_obj_get_child(Page->play_button, 0); // 直接用第一个子对象
    uint32_t cnt = lv_obj_get_child_cnt(Page->play_button);
    if (!img) {
        img = lv_img_create(Page->play_button);
        lv_obj_center(img);
    }
    lv_img_set_src(img, is_playing ? &pause : &play);
    lv_obj_invalidate(img);
}

// 播放按钮点击事件回调
static void play_button_click_callback(lv_event_t* e) {
    lv_event_code_t code = lv_event_get_code(e);
    lv_obj_t* obj = lv_event_get_target(e);
    printf("play_button callback invoked. event code=%d target=%p\n", (int)code, obj);

    MusicPage* Page = (MusicPage*)lv_event_get_user_data(e);
    printf("Play button clicked, state: %s\n", Page->play_state == MUSIC_STATE_PLAYING ? "PLAYING" : "PAUSED");

    if (Page == NULL) {
        printf("play_button callback: Page is NULL\n");
        return;
    }

    // 切换播放状态
    if (Page->play_state == MUSIC_STATE_PAUSED) {
        // 从暂停切换到播放
        Page->play_state = MUSIC_STATE_PLAYING;
        SetMusicPlayState(Page, true);
        // play_music(); // TODO
    }
    else {
        // 从播放切换到暂停
        Page->play_state = MUSIC_STATE_PAUSED;
        SetMusicPlayState(Page, false);
        // pause_music(); // TODO
    }
}

void CreateCtrlBtnsTheme2(MusicPage* Page) {
    if (Page == NULL || Page->Handle == NULL) return;

    // 歌词、歌曲背景图
    Page->album_rect = lv_obj_create(Page->Handle);
    lv_obj_set_size(Page->album_rect, LV_PCT(62), LV_PCT(70));
    lv_obj_align(Page->album_rect, LV_ALIGN_TOP_LEFT, 0, 0);
    lv_obj_set_style_margin_all(Page->album_rect, 0, 0);
    lv_obj_set_style_border_width(Page->album_rect, 1, 0);
    lv_obj_set_style_border_color(Page->album_rect, lv_color_hex3(0x000), 0);
    lv_obj_set_style_pad_all(Page->album_rect, 0, 0);
    lv_obj_set_style_radius(Page->album_rect, 0, 0);
    lv_obj_set_style_bg_color(Page->album_rect, lv_color_hex(0x7FFFD4), 0);

    // 歌词名
    Page->music_name_rect = lv_obj_create(Page->Handle);
    lv_obj_set_size(Page->music_name_rect, LV_PCT(36), LV_PCT(18));
    lv_obj_align(Page->music_name_rect, LV_ALIGN_TOP_RIGHT, 0, 0);
    lv_obj_set_style_margin_all(Page->music_name_rect, 0, 0);
    lv_obj_set_style_border_width(Page->music_name_rect, 1, 0);
    lv_obj_set_style_border_color(Page->music_name_rect, lv_color_hex3(0x000), 0);
    lv_obj_set_style_pad_all(Page->music_name_rect, 0, 0);
    lv_obj_set_style_radius(Page->music_name_rect, 0, 0);
    lv_obj_set_style_bg_color(Page->music_name_rect, lv_color_hex(0xFFEBCD), 0);

    // 歌手名
    Page->singer_name_rect = lv_obj_create(Page->Handle);
    lv_obj_set_size(Page->singer_name_rect, LV_PCT(36), LV_PCT(18));
    lv_obj_align(Page->singer_name_rect, LV_ALIGN_TOP_RIGHT, 0, LV_PCT(20));
    lv_obj_set_style_margin_all(Page->singer_name_rect, 0, 0);
    lv_obj_set_style_border_width(Page->singer_name_rect, 1, 0);
    lv_obj_set_style_border_color(Page->singer_name_rect, lv_color_hex3(0x000), 0);
    lv_obj_set_style_pad_all(Page->singer_name_rect, 0, 0);
    lv_obj_set_style_radius(Page->singer_name_rect, 0, 0);
    lv_obj_set_style_bg_color(Page->singer_name_rect, lv_color_hex(0x9932CC), 0);

    // 用户头像
    Page->user_rect = lv_obj_create(Page->Handle);
    lv_obj_set_size(Page->user_rect, LV_PCT(36), LV_PCT(30));
    lv_obj_align(Page->user_rect, LV_ALIGN_TOP_RIGHT, 0, LV_PCT(40));
    lv_obj_set_style_margin_all(Page->user_rect, 0, 0);
    lv_obj_set_style_border_width(Page->user_rect, 1, 0);
    lv_obj_set_style_border_color(Page->user_rect, lv_color_hex3(0x000), 0);
    lv_obj_set_style_pad_all(Page->user_rect, 0, 0);
    lv_obj_set_style_radius(Page->user_rect, 0, 0);
    lv_obj_set_style_bg_color(Page->user_rect, lv_color_hex(0xFFD700), 0);

    // 按钮控件
    Page->play_buttons_widgets = lv_obj_create(Page->Handle);
    //lv_obj_set_pos(Page->play_buttons_widgets, 0, 340);
    lv_obj_set_size(Page->play_buttons_widgets, LV_PCT(100), 60);
    lv_obj_align(Page->play_buttons_widgets, LV_ALIGN_TOP_LEFT, 0, 340);
    lv_obj_set_style_margin_all(Page->play_buttons_widgets, 0, 0);
    lv_obj_set_style_border_width(Page->play_buttons_widgets, 1, 0);
    lv_obj_set_style_border_color(Page->play_buttons_widgets, lv_color_hex3(0x000), 0);
    lv_obj_set_style_pad_all(Page->play_buttons_widgets, 0, 0);
    lv_obj_set_style_radius(Page->play_buttons_widgets, 0, 0);
    lv_obj_set_style_bg_color(Page->play_buttons_widgets, lv_color_hex3(0xFFF), 0);

    // button：play/pause
    Page->play_button = lv_button_create(Page->play_buttons_widgets);
    lv_obj_set_pos(Page->play_button, 0, 0);
    lv_obj_set_size(Page->play_button, 40, 40);
    lv_obj_align(Page->play_button, LV_ALIGN_CENTER, 0, 0);
    lv_obj_set_style_radius(Page->play_button, LV_RADIUS_CIRCLE, 0);
    lv_obj_set_style_bg_color(Page->play_button, lv_color_hex(0xADD8E6), 0);

    // label：play/pause
    Page->play_label = lv_label_create(Page->play_buttons_widgets);
    lv_label_set_text_static(Page->play_label, "PLAY");
    lv_obj_align(Page->play_label, LV_ALIGN_CENTER, 45, 0);
    lv_obj_set_style_text_font(Page->play_label, lv_font_get_default(), 0);
    lv_obj_set_style_text_color(Page->play_label, lv_color_hex3(0xF00), 0);

    // button：上一首
    Page->prev_button = lv_button_create(Page->play_buttons_widgets);
    lv_obj_set_pos(Page->prev_button, 0, 0);
    lv_obj_set_size(Page->prev_button, 40, 40);
    lv_obj_align(Page->prev_button, LV_ALIGN_LEFT_MID, 8, 0);
    lv_obj_set_style_radius(Page->prev_button, LV_RADIUS_CIRCLE, 0);
    lv_obj_set_style_bg_color(Page->prev_button, lv_color_hex(0xADD8E6), 0);
    
    // label：上一首
    Page->prev_label = lv_label_create(Page->play_buttons_widgets);
    lv_label_set_text_static(Page->prev_label, "PREV");
    lv_obj_align(Page->prev_label, LV_ALIGN_LEFT_MID, 55, 0);
    lv_obj_set_style_text_font(Page->prev_label, lv_font_get_default(), 0);
    lv_obj_set_style_text_color(Page->prev_label, lv_color_hex3(0xF00), 0);

    // button：下一首
    Page->next_button = lv_button_create(Page->play_buttons_widgets);
    lv_obj_set_pos(Page->next_button, 0, 0);
    lv_obj_set_size(Page->next_button, 40, 40);
    lv_obj_align(Page->next_button, LV_ALIGN_RIGHT_MID, -8, 0);
    lv_obj_set_style_radius(Page->next_button, LV_RADIUS_CIRCLE, 0);
    lv_obj_set_style_bg_color(Page->next_button, lv_color_hex(0xADD8E6), 0);

    // label：下一首
    Page->next_label = lv_label_create(Page->play_buttons_widgets);
    lv_label_set_text_static(Page->next_label, "NEXT");
    lv_obj_align(Page->next_label, LV_ALIGN_RIGHT_MID, -55, 0);
    lv_obj_set_style_text_font(Page->next_label, lv_font_get_default(), 0);
    lv_obj_set_style_text_color(Page->next_label, lv_color_hex3(0xF00), 0);

    lv_obj_clear_flag(Page->play_buttons_widgets, LV_OBJ_FLAG_SCROLLABLE);
}
