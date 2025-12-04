#include "DockBar.h"
#include "Application.h"
#include "Widgets/Widget.h"
#include "Util/Image.h"

void DockBarTheme2MusicButtonState(DockBarTheme2 *Bar, int State);
void DockBarTheme2HomePageButtonState(DockBarTheme2 *Bar, int State);
void DockBarTheme2ClockButtonState(DockBarTheme2 *Bar, int State);
void DockBarTheme2SystemInfoButtonState(DockBarTheme2 *Bar, int State);
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
  //  Bar->IConHomePage = CreateBase(Bar->ButtonHomePage, 0, 0, 30, 30, lv_color_make(255, 0, 232));

    Bar->IConHomePage = CreateImage(Bar->ButtonHomePage, 0, 0, 30, 30, lv_color_make(255, 0, 232));
    lv_obj_set_style_radius(Bar->IConHomePage, 10, 0);
    lv_image_set_scale_x(Bar->IConHomePage, 256 * (30.f / theme.header.w));
    lv_image_set_scale_y(Bar->IConHomePage, 256 * (30.f / theme.header.h));
    lv_image_set_src(Bar->IConHomePage, &theme);

    Bar->LabelHomePage = CreateLabel(Bar->ButtonHomePage, 30, 4,  60, 30, "Home", lv_color_make(8, 184, 232));

    Bar->ButtonMusic = CreateButton(DockBarHandle, 100, 0, 100, 30, lv_color_make(8, 184, 232));
    Bar->IConHomeMusic = CreateImage(Bar->ButtonMusic, 0, 0, 30, 30, lv_color_make(255, 0, 232));
    lv_obj_set_style_radius(Bar->IConHomeMusic, 10, 0);
    lv_image_set_scale_x(Bar->IConHomeMusic, 256 * (30.f / theme.header.w));
    lv_image_set_scale_y(Bar->IConHomeMusic, 256 * (30.f / theme.header.h));
    lv_image_set_src(Bar->IConHomeMusic, &theme);
    Bar->LabelMusic = CreateLabel(Bar->ButtonMusic,  30, 4,  60, 30, "Playing", lv_color_make(8, 184, 232));

    Bar->ButtonClock = CreateButton(DockBarHandle, 205, 0, 80, LV_PCT(100), lv_color_make(8, 184, 232));
    Bar->IConHomeClock = CreateImage(Bar->ButtonClock, 0, 0, 30, 30, lv_color_make(255, 0, 232));
    lv_obj_set_style_radius(Bar->IConHomeClock, 10, 0);
    lv_image_set_scale_x(Bar->IConHomeClock, 256 * (30.f / theme.header.w));
    lv_image_set_scale_y(Bar->IConHomeClock, 256 * (30.f / theme.header.h));
    lv_image_set_src(Bar->IConHomeClock, &theme);
    Bar->LabelClock = CreateLabel(Bar->ButtonClock,  30, 4,  50, 30, "24:00", lv_color_make(8, 184, 232));


    Bar->ButtonSystemInfo = CreateButton(DockBarHandle, 300, 0, 80, LV_PCT(100), lv_color_make(8, 184, 232));
    Bar->IConSystemInfo = CreateImage(Bar->ButtonSystemInfo, 0, 0, 30, 30, lv_color_make(255, 0, 232));
    lv_obj_set_style_radius(Bar->IConSystemInfo, 10, 0);
    lv_image_set_scale_x(Bar->IConSystemInfo, 256 * (30.f / theme.header.w));
    lv_image_set_scale_y(Bar->IConSystemInfo, 256 * (30.f / theme.header.h));
    lv_image_set_src(Bar->IConSystemInfo, &theme);
    Bar->LabelSystemInfo = CreateLabel(Bar->ButtonSystemInfo,  30, 4,  70, 30, "System", lv_color_make(8, 184, 232));

    Bar->ButtonSetting = CreateButton(DockBarHandle, 420, 0, 30, LV_PCT(100), lv_color_make(8, 184, 232));
    Bar->IConSetting = CreateImage(Bar->ButtonSetting, 0, 0, 30, 30, lv_color_make(255, 0, 232));
    lv_obj_set_style_radius(Bar->IConSetting, 10, 0);
    lv_image_set_scale_x(Bar->IConSetting, 256 * (30.f / theme.header.w));
    lv_image_set_scale_y(Bar->IConSetting, 256 * (30.f / theme.header.h));
    lv_image_set_src(Bar->IConSetting, &theme);

    Bar->ButtonCaps = CreateButton(DockBarHandle, 460, 0, 30, LV_PCT(100), lv_color_make(8, 184, 232));
    Bar->IconCaps = CreateImage(Bar->ButtonCaps, 0, 0, 30, 30, lv_color_make(255, 0, 232));
    lv_obj_set_style_radius(Bar->IconCaps, 10, 0);
    lv_image_set_scale_x(Bar->IconCaps, 256 * (30.f / theme.header.w));
    lv_image_set_scale_y(Bar->IconCaps, 256 * (30.f / theme.header.h));
    lv_image_set_src(Bar->IconCaps, &theme);

    Bar->ButtonVolumeMutex = CreateButton(DockBarHandle, 420, 0, 30, LV_PCT(100), lv_color_make(8, 184, 232));
    Bar->IconVolumeMutex = CreateImage(Bar->ButtonVolumeMutex, 0, 0, 30, 30, lv_color_make(255, 0, 232));
    lv_obj_set_style_radius(Bar->IconVolumeMutex, 10, 0);
    lv_image_set_scale_x(Bar->IconVolumeMutex, 256 * (30.f / theme.header.w));
    lv_image_set_scale_y(Bar->IconVolumeMutex, 256 * (30.f / theme.header.h));
    lv_image_set_src(Bar->IconVolumeMutex, &theme);

    Bar->ButtonHomePageText = "Home";
    Bar->ButtonMusicText = "Music";
    Bar->ButtonClockText = "Clock";
    Bar->ButtonSystemInfoText = "System";
    Bar->ButtonSettingText = "Setting";

    int padding = 5;

    Bar->ButtonHomePageSize.x       = 90;
    Bar->ButtonHomePageSize.y       = 30;
    Bar->ButtonMusicSize.x          = 90;
    Bar->ButtonMusicSize.y          = 30;
    Bar->ButtonClockSize.x          = 80;
    Bar->ButtonClockSize.y          = 30;
    Bar->ButtonSystemInfoSize.x     = 90;
    Bar->ButtonSystemInfoSize.y     = 30;
    Bar->ButtonSettingSize.x        = 30;
    Bar->ButtonSettingSize.y        = 30;
    Bar->ButtonCapsSize.x           = 30;
    Bar->ButtonCapsSize.y           = 30;
    Bar->ButtonVolumeMutexSize.x    = 30;
    Bar->ButtonVolumeMutexSize.y    = 30;

    Bar->ButtonHomePagePos.x    = padding;
    Bar->ButtonMusicPos.x       = padding   +   Bar->ButtonHomePagePos.x    + Bar->ButtonHomePageSize.x;
    Bar->ButtonClockPos.x       = padding   +   Bar->ButtonMusicPos.x       + Bar->ButtonMusicSize.x;
    Bar->ButtonSystemInfoPos.x  = padding   +   Bar->ButtonClockPos.x       + Bar->ButtonClockSize.x;
    Bar->ButtonSettingPos.x     = padding   +   Bar->ButtonSystemInfoPos.x  + Bar->ButtonSystemInfoSize.x;
    Bar->ButtonCapsPos.x        = padding   +   Bar->ButtonSettingPos.x     + Bar->ButtonSettingSize.x;
    Bar->ButtonVolumeMutexPos.x = padding   +   Bar->ButtonCapsPos.x        + Bar->ButtonCapsSize.x;

    Bar->ButtonHomePagePos.y    = padding;
    Bar->ButtonMusicPos.y       = padding;
    Bar->ButtonClockPos.y       = padding;
    Bar->ButtonSystemInfoPos.y  = padding;
    Bar->ButtonSettingPos.y     = padding;
    Bar->ButtonCapsPos.y        = padding;
    Bar->ButtonVolumeMutexPos.y = padding;


    DockBarTheme2HomePageButtonState(Bar, 1);
    DockBarTheme2MusicButtonState(Bar, 1);
    DockBarTheme2SystemInfoButtonState(Bar, 1);
    DockBarTheme2ClockButtonState(Bar, 0);
}

void DockBarTheme2Update(DockBarTheme2 *Bar)
{
    int padding = 10;

    Bar->ButtonMusicPos.x       = Bar->ButtonHomePagePos.x          + Bar->ButtonHomePageSize.x     + padding;
    Bar->ButtonClockPos.x       = Bar->ButtonMusicPos.x             + Bar->ButtonMusicSize.x        + padding;
    Bar->ButtonSystemInfoPos.x  = Bar->ButtonClockPos.x             + Bar->ButtonClockSize.x        + padding;
    Bar->ButtonSettingPos.x     = Bar->ButtonSystemInfoPos.x        + Bar->ButtonSystemInfoSize.x   + padding;
    Bar->ButtonCapsPos.x        = Bar->ButtonSettingPos.x           + Bar->ButtonSettingSize.x      + padding;
    Bar->ButtonVolumeMutexPos.x = Bar->ButtonCapsPos.x              + Bar->ButtonCapsSize.x         + padding;

    lv_obj_set_pos(Bar->ButtonHomePage, Bar->ButtonHomePagePos.x, Bar->ButtonHomePagePos.y);
    lv_obj_set_size(Bar->ButtonHomePage, Bar->ButtonHomePageSize.x, Bar->ButtonHomePageSize.y);
    lv_label_set_text_static(Bar->LabelHomePage, Bar->ButtonHomePageText);

    lv_obj_set_pos(Bar->ButtonMusic, Bar->ButtonMusicPos.x, Bar->ButtonMusicPos.y);
    lv_obj_set_size(Bar->ButtonMusic, Bar->ButtonMusicSize.x, Bar->ButtonMusicSize.y);
    lv_label_set_text_static(Bar->LabelMusic, Bar->ButtonMusicText);

    lv_obj_set_pos(Bar->ButtonClock, Bar->ButtonClockPos.x, Bar->ButtonClockPos.y);
    lv_obj_set_size(Bar->ButtonClock, Bar->ButtonClockSize.x, Bar->ButtonClockSize.y);
    lv_label_set_text_static(Bar->LabelClock, Bar->ButtonClockText);

    lv_obj_set_pos(Bar->ButtonSystemInfo, Bar->ButtonSystemInfoPos.x, Bar->ButtonSystemInfoPos.y);
    lv_obj_set_size(Bar->ButtonSystemInfo, Bar->ButtonSystemInfoSize.x, Bar->ButtonSystemInfoSize.y);
    lv_label_set_text_static(Bar->LabelSystemInfo, Bar->ButtonSystemInfoText);

    lv_obj_set_pos(Bar->ButtonSetting, Bar->ButtonSettingPos.x, Bar->ButtonSettingPos.y);
    lv_obj_set_size(Bar->ButtonSetting, Bar->ButtonSettingSize.x, Bar->ButtonSettingSize.y);
    //lv_label_set_text_static(Bar->LabelSystemInfo, Bar->ButtonSystemInfoText);

    lv_obj_set_pos(Bar->ButtonCaps, Bar->ButtonCapsPos.x, Bar->ButtonCapsPos.y);
    lv_obj_set_size(Bar->ButtonCaps, Bar->ButtonCapsSize.x, Bar->ButtonCapsSize.y);

    lv_obj_set_pos(Bar->ButtonVolumeMutex, Bar->ButtonVolumeMutexPos.x, Bar->ButtonVolumeMutexPos.y);
    lv_obj_set_size(Bar->ButtonVolumeMutex, Bar->ButtonVolumeMutexSize.x, Bar->ButtonVolumeMutexSize.y);
}

void DockBarTheme2HomePageButtonState(DockBarTheme2 *Bar, int State)
{
    Bar->ButtonHomePageText = "";
    switch (State) {
        case 0:
            Bar->ButtonHomePageText = "";
            Bar->ButtonHomePageSize.x = 30;
            Bar->ButtonHomePageSize.y = 30;
            lv_obj_add_flag(Bar->LabelHomePage, LV_OBJ_FLAG_HIDDEN);
            break;
        case 1:
            Bar->ButtonHomePageText = "HOME";
            Bar->ButtonHomePageSize.x = 100;
            Bar->ButtonHomePageSize.y = 30;
            lv_obj_clear_flag(Bar->LabelHomePage, LV_OBJ_FLAG_HIDDEN);
            break;
    }
    DockBarTheme2Update(Bar);
}

void DockBarTheme2MusicButtonState(DockBarTheme2 *Bar, int State)
{
    switch (State) {
        case 0:
            Bar->ButtonMusicText = "";
            Bar->ButtonMusicSize.x = 30;
            Bar->ButtonMusicSize.y = 30;
            lv_obj_add_flag(Bar->LabelMusic, LV_OBJ_FLAG_HIDDEN);
            break;
        case 1:
            Bar->ButtonMusicText = "Music";
            Bar->ButtonMusicSize.x = 100;
            Bar->ButtonMusicSize.y = 30;
            lv_obj_clear_flag(Bar->LabelMusic, LV_OBJ_FLAG_HIDDEN);
            break;
        case 2:
            Bar->ButtonMusicText = "Playing";
            Bar->ButtonMusicSize.x = 100;
            Bar->ButtonMusicSize.y = 30;
            lv_obj_clear_flag(Bar->LabelMusic, LV_OBJ_FLAG_HIDDEN);
            break;
        default:
            Bar->ButtonMusicText = "";
            lv_obj_add_flag(Bar->LabelMusic, LV_OBJ_FLAG_HIDDEN);
            break;
    }
    DockBarTheme2Update(Bar);
}

void DockBarTheme2ClockButtonState(DockBarTheme2 *Bar, int State)
{
    switch (State) {
        case 0:
            Bar->ButtonClockText = "";
            Bar->ButtonClockSize.x = 30;
            Bar->ButtonClockSize.y = 30;
            lv_obj_add_flag(Bar->LabelClock, LV_OBJ_FLAG_HIDDEN);
            break;
        case 1:
            Bar->ButtonClockText = "TIMER";
            Bar->ButtonClockSize.x = 100;
            Bar->ButtonClockSize.y = 30;
            lv_obj_clear_flag(Bar->LabelClock, LV_OBJ_FLAG_HIDDEN);
            break;
        default:
            Bar->ButtonClockText = "";
            lv_obj_add_flag(Bar->LabelClock, LV_OBJ_FLAG_HIDDEN);
            break;
    }
    DockBarTheme2Update(Bar);
}

void DockBarTheme2SystemInfoButtonState(DockBarTheme2 *Bar, int State)
{
    switch (State) {
        case 0:
            Bar->ButtonSystemInfoText = "";
            Bar->ButtonSystemInfoSize.x = 30;
            Bar->ButtonSystemInfoSize.y = 30;
            lv_obj_add_flag(Bar->LabelSystemInfo, LV_OBJ_FLAG_HIDDEN);
            break;
        case 1:
            Bar->ButtonSystemInfoText = "System";
            Bar->ButtonSystemInfoSize.x = 90;
            Bar->ButtonSystemInfoSize.y = 30;
            lv_obj_clear_flag(Bar->LabelSystemInfo, LV_OBJ_FLAG_HIDDEN);
            break;
        default:
            Bar->ButtonSystemInfoText = "";
            lv_obj_add_flag(Bar->LabelSystemInfo, LV_OBJ_FLAG_HIDDEN);
            break;
    }
    DockBarTheme2Update(Bar);
}