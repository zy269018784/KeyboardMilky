#include "DockBar.h"
#include "Application.h"
#include "Widgets/Widget.h"
void CreateDockBarTheme2(DockBarTheme2 *Bar, lv_obj_t *Parent, Theme *CurrentTheme)
{
    lv_obj_t *DockBarHandle = lv_obj_create(Parent);

    Bar->Handle = DockBarHandle;

    int RowLayoutWidth = 480 - 10 * 2;
    lv_obj_set_pos(DockBarHandle, 10, 420);
    lv_obj_set_size(DockBarHandle, RowLayoutWidth, 38);
    lv_obj_set_style_bg_color(DockBarHandle, lv_color_make(235, 235, 235), 0);
    lv_obj_set_style_border_width(DockBarHandle, 0, 0);
    lv_obj_set_style_pad_all(DockBarHandle, 0, 0);
    lv_obj_clear_flag(DockBarHandle, LV_OBJ_FLAG_SCROLLABLE);

    Bar->ButtonHomePage = CreateButton(DockBarHandle, 0, 0, 90, LV_PCT(100), lv_color_make(8, 184, 232));
    Bar->IConHomePage = CreateBase(Bar->ButtonHomePage, 0, 0, 30, 30, lv_color_make(255, 0, 232));
    Bar->LabelHomePage = CreateLabel(Bar->ButtonHomePage, 30, 4,  60, 30, "Home", lv_color_make(8, 184, 232));

    Bar->ButtonMusic = CreateButton(DockBarHandle, 100, 0, 100, LV_PCT(100), lv_color_make(8, 184, 232));
    Bar->IConHomeMusic = CreateBase(Bar->ButtonMusic, 0, 4,  30, 30, lv_color_make(255, 0, 232));
    Bar->LabelMusic = CreateLabel(Bar->ButtonMusic,  30, 4,  60, 30, "Playing", lv_color_make(8, 184, 232));

    Bar->ButtonClock = CreateButton(DockBarHandle, 205, 0, 80, LV_PCT(100), lv_color_make(8, 184, 232));
    Bar->IConHomeClock = CreateBase(Bar->ButtonClock, 0, 4,  30, 30, lv_color_make(255, 0, 232));
    Bar->LabelClock = CreateLabel(Bar->ButtonClock,  30, 4,  50, 30, "24:00", lv_color_make(8, 184, 232));


    Bar->ButtonSystemInfo = CreateButton(DockBarHandle, 300, 0, 30, LV_PCT(100), lv_color_make(8, 184, 232));

    Bar->ButtonSetting = CreateButton(DockBarHandle, 340, 0, 30, LV_PCT(100), lv_color_make(8, 184, 232));

    Bar->ButtonCaps = CreateButton(DockBarHandle, 380, 0, 30, LV_PCT(100), lv_color_make(8, 184, 232));

    Bar->ButtonVolumeMutex = CreateButton(DockBarHandle, 420, 0, 30, LV_PCT(100), lv_color_make(8, 184, 232));

}