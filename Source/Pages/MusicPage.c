#include "MusicPage.h"

void CreateMusicPage(MusicPage* Page, lv_obj_t* Parent)
{
    Page->Parent = Parent;
    /*---------------------------------------------------------------------*/
    Page->Handle = lv_obj_create(Parent);
    /*
        设置位置和尺寸
    */
    lv_obj_set_size(Page->Handle, LV_PCT(100), LV_PCT(100)); // 全屏
    /*
        设置盒子模型
    */
    lv_obj_set_style_pad_all(Page->Handle, 0, 0);
    lv_obj_set_style_border_width(Page->Handle, 0, 0);
    lv_obj_set_style_margin_all(Page->Handle, 0, 0);
    /*
          设置背景颜色
      */
    lv_obj_set_style_bg_color(Page->Handle, lv_color_hex3(0xFF0), 0);
    /*
        设置radius
    */
    lv_obj_set_style_radius(Page->Handle, 0, 0);
    /*
        关闭滚动条
    */
    lv_obj_clear_flag(Page->Handle, LV_OBJ_FLAG_SCROLLABLE);
    /*---------------------------------------------------------------------*/
    /*
        播放按钮
    */
    Page->play_button = lv_button_create(Page->Handle);
    /*
        设置位置和尺寸
    */
    lv_obj_set_pos(Page->play_button,   0,  0);
    lv_obj_set_size(Page->play_button, 50, 50);
    /*
        设置盒子模型
    */
    lv_obj_set_style_pad_all(Page->play_button, 0, 0);
    lv_obj_set_style_border_width(Page->play_button, 0, 0);
    lv_obj_set_style_margin_all(Page->play_button, 0, 0);
    /*
      设置背景颜色
    */
    lv_obj_set_style_bg_color(Page->play_button, lv_color_hex3(0x00F), 0);
    /*
        设置radius
    */
    lv_obj_set_style_radius(Page->play_button, 25, 0);
    /*
        关闭滚动条
    */
    lv_obj_clear_flag(Page->play_button, LV_OBJ_FLAG_SCROLLABLE);
    /*---------------------------------------------------------------------*/
    /*
        进度条
    */
    Page->progress_bar = lv_bar_create(Page->Handle);
    lv_bar_set_value(Page->progress_bar, 70, LV_ANIM_OFF);
    /*
        设置位置和尺寸
    */
    lv_obj_set_pos(Page->progress_bar, 0, 420);
    lv_obj_set_size(Page->progress_bar, LV_PCT(100), 10);
    /*
        设置盒子模型
    */
    lv_obj_set_style_pad_all(Page->progress_bar, 0, 0);
    lv_obj_set_style_border_width(Page->progress_bar, 0, 0);
    lv_obj_set_style_margin_all(Page->progress_bar, 0, 0);
    /*
      设置背景颜色
    */
    lv_obj_set_style_bg_color(Page->progress_bar, lv_color_hex3(0x00F), 0);
    /*
        设置radius
    */
    lv_obj_set_style_radius(Page->progress_bar, 5, 0);
    /*-
        关闭滚动条
    */
    lv_obj_clear_flag(Page->play_button, LV_OBJ_FLAG_SCROLLABLE);
    /*---------------------------------------------------------------------*/
    /*
        音乐名称标签
    */
    Page->music_name_label_pos  = (Point2){ 10, 420 - 60 };
    Page->music_name_label_size = (Point2){ LV_PCT(100), 50 };
    CreateMusicNameLabel(Page);
    CreateSingerNameLabel(Page);
    /*---------------------------------------------------------------------*/
}

void CreateMusicNameLabel(MusicPage* Page)
{
    Page->music_name_label = lv_label_create(Page->Handle);
    lv_label_set_text_static(Page->music_name_label, "Don't Be So Serious");
    /*
        设置文本居中
    */
    lv_obj_set_style_text_align(Page->music_name_label, LV_TEXT_ALIGN_LEFT, 0);
    /*
        设置位置和尺寸
    */
    lv_obj_set_pos(Page->music_name_label, 10, 420 - 60);
    lv_obj_set_size(Page->music_name_label, LV_PCT(100), 50);
    /*
        设置盒子模型
    */
    lv_obj_set_style_pad_all(Page->music_name_label, 0, 0);
    lv_obj_set_style_border_width(Page->music_name_label, 0, 0);
    lv_obj_set_style_margin_all(Page->music_name_label, 0, 0);
    /*
      设置背景颜色
    */
    lv_obj_set_style_bg_color(Page->music_name_label, lv_color_hex3(0xFFF), 0);
    /*
        设置radius
    */
    lv_obj_set_style_radius(Page->music_name_label, 0, 0);
    /*
        关闭滚动条
    */
    lv_obj_clear_flag(Page->music_name_label, LV_OBJ_FLAG_SCROLLABLE);
}

void CreateSingerNameLabel(MusicPage* Page)
{
    Page->singer_name_label = lv_label_create(Page->Handle);
    lv_label_set_text_static(Page->singer_name_label, "Low Roar");
    /*
        设置文本居中
    */
    lv_obj_set_style_text_align(Page->singer_name_label, LV_TEXT_ALIGN_LEFT, 0);
    /*
        设置位置和尺寸
    */
    lv_obj_set_pos(Page->singer_name_label, 10, 420 - 40);
    lv_obj_set_size(Page->singer_name_label, LV_PCT(100), 50);
    /*
        设置盒子模型
    */
    lv_obj_set_style_pad_all(Page->singer_name_label, 0, 0);
    lv_obj_set_style_border_width(Page->singer_name_label, 0, 0);
    lv_obj_set_style_margin_all(Page->singer_name_label, 0, 0);
    /*
      设置背景颜色
    */
    lv_obj_set_style_bg_color(Page->singer_name_label, lv_color_hex3(0xFFF), 0);
    /*
        设置radius
    */
    lv_obj_set_style_radius(Page->singer_name_label, 0, 0);
    /*
        关闭滚动条
    */
    lv_obj_clear_flag(Page->singer_name_label, LV_OBJ_FLAG_SCROLLABLE);
}