#include "DockBar.h"
#include "Application.h"

void CreateDockBarTheme1(DockBar *Bar, lv_obj_t *Parent, Theme *CurrentTheme)
{
    lv_obj_t *DockBarHandle = lv_obj_create(Parent);

    Bar->Handle = DockBarHandle;

    int RowLayoutWidth = 30 * 5 + 7 * 4;
    lv_obj_set_pos(DockBarHandle, 10, 420);
    lv_obj_set_size(DockBarHandle, RowLayoutWidth, 38);
    lv_obj_set_style_bg_color(DockBarHandle, lv_color_hex3(0x000), 0);
    lv_obj_set_style_border_width(DockBarHandle, 0, 0);
    lv_obj_set_style_pad_all(DockBarHandle, 0, 0);
    lv_obj_clear_flag(DockBarHandle, LV_OBJ_FLAG_SCROLLABLE);

    Bar->ButtonHomePage = lv_button_create(DockBarHandle);
    lv_obj_set_pos(Bar->ButtonHomePage, 4 * 1 + 30 * 0, 4);
    lv_obj_set_size(Bar->ButtonHomePage, 30, 30);
    lv_obj_set_style_bg_color(Bar->ButtonHomePage, CurrentTheme->main_color, 0);
    lv_obj_clear_flag(Bar->ButtonHomePage, LV_OBJ_FLAG_SCROLLABLE);


    Bar->ButtonMusic = lv_button_create(DockBarHandle);
    lv_obj_set_pos(Bar->ButtonMusic, 4 * 2 + 30 * 1, 4);
    lv_obj_set_size(Bar->ButtonMusic, 30, 30);
    lv_obj_set_style_bg_color(Bar->ButtonMusic, CurrentTheme->sub_color, 0);
    lv_obj_clear_flag(Bar->ButtonMusic, LV_OBJ_FLAG_SCROLLABLE);

    Bar->ButtonClock = lv_button_create(DockBarHandle);
    lv_obj_set_pos(Bar->ButtonClock, 4 * 3 + 30 * 2, 4);
    lv_obj_set_size(Bar->ButtonClock, 30, 30);
    lv_obj_set_style_bg_color(Bar->ButtonClock, CurrentTheme->sub_color, 0);
    lv_obj_clear_flag(Bar->ButtonClock, LV_OBJ_FLAG_SCROLLABLE);

    Bar->ButtonSystemInfo = lv_button_create(DockBarHandle);
    lv_obj_set_pos(Bar->ButtonSystemInfo, 4 * 4 + 30 * 3, 4);
    lv_obj_set_size(Bar->ButtonSystemInfo, 30, 30);
    lv_obj_set_style_bg_color(Bar->ButtonSystemInfo, CurrentTheme->sub_color, 0);
    lv_obj_clear_flag(Bar->ButtonSystemInfo, LV_OBJ_FLAG_SCROLLABLE);

    Bar->ButtonSetting = lv_button_create(DockBarHandle);
    lv_obj_set_pos(Bar->ButtonSetting, 4 * 5 + 30 * 4, 4);
    lv_obj_set_size(Bar->ButtonSetting, 30, 30);
    lv_obj_set_style_bg_color(Bar->ButtonSetting, CurrentTheme->sub_color, 0);
    lv_obj_clear_flag(Bar->ButtonSetting, LV_OBJ_FLAG_SCROLLABLE);
}