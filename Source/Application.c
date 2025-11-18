#include "Application.h"
#include "Widgets/Widget.h"
void ShowSettingPage(SettingsPage* Page, int PageNo);

void CreateButtonLayout(Application* App, lv_obj_t *Parent)
{
    App->RowLayout = lv_obj_create(Parent);

    int RowLayoutWidth = 30 * 5 + 7 * 4;
    lv_obj_set_pos(App->RowLayout, 10, 420);
    lv_obj_set_size(App->RowLayout, RowLayoutWidth, 38);
    lv_obj_set_style_bg_color(App->RowLayout, lv_color_hex3(0x000), 0);
    lv_obj_set_style_border_width(App->RowLayout, 0, 0);
    lv_obj_set_style_pad_all(App->RowLayout, 0, 0);
    lv_obj_clear_flag(App->RowLayout, LV_OBJ_FLAG_SCROLLABLE);

    App->ButtonHomePage = lv_button_create(App->RowLayout);
    lv_obj_set_pos(App->ButtonHomePage, 4 * 1 + 30 * 0, 4);
    lv_obj_set_size(App->ButtonHomePage, 30, 30);
    lv_obj_set_style_bg_color(App->ButtonHomePage, App->CurrentTheme.main_color, 0);
    lv_obj_clear_flag(App->ButtonHomePage, LV_OBJ_FLAG_SCROLLABLE);


    App->ButtonMusic = lv_button_create(App->RowLayout);
    lv_obj_set_pos(App->ButtonMusic, 4 * 2 + 30 * 1, 4);
    lv_obj_set_size(App->ButtonMusic, 30, 30);
    lv_obj_set_style_bg_color(App->ButtonMusic, App->CurrentTheme.sub_color, 0);
    lv_obj_clear_flag(App->ButtonMusic, LV_OBJ_FLAG_SCROLLABLE);

    App->ButtonClock = lv_button_create(App->RowLayout);
    lv_obj_set_pos(App->ButtonClock, 4 * 3 + 30 * 2, 4);
    lv_obj_set_size(App->ButtonClock, 30, 30);
    lv_obj_set_style_bg_color(App->ButtonClock, App->CurrentTheme.sub_color, 0);
    lv_obj_clear_flag(App->ButtonClock, LV_OBJ_FLAG_SCROLLABLE);

    App->ButtonSystemInfo = lv_button_create(App->RowLayout);
    lv_obj_set_pos(App->ButtonSystemInfo, 4 * 4 + 30 * 3, 4);
    lv_obj_set_size(App->ButtonSystemInfo, 30, 30);
    lv_obj_set_style_bg_color(App->ButtonSystemInfo, App->CurrentTheme.sub_color, 0);
    lv_obj_clear_flag(App->ButtonSystemInfo, LV_OBJ_FLAG_SCROLLABLE);

    App->ButtonSetting = lv_button_create(App->RowLayout);
    lv_obj_set_pos(App->ButtonSetting, 4 * 5 + 30 * 4, 4);
    lv_obj_set_size(App->ButtonSetting, 30, 30);
    lv_obj_set_style_bg_color(App->ButtonSetting, App->CurrentTheme.sub_color, 0);
    lv_obj_clear_flag(App->ButtonSetting, LV_OBJ_FLAG_SCROLLABLE);
}



struct Application* CreateApplication()
{
    struct Application* App = (struct Application*)malloc(sizeof(struct Application));
    lv_init();
    App->Display = lv_windows_create_display(
        L"Milkyway Keyboard",
        480,
        480,
        100,
        false,
        true);

    lv_obj_t* ActiveScreen = lv_screen_active();
    lv_obj_set_style_pad_all(ActiveScreen, 0, 0);
    lv_obj_set_style_border_width(ActiveScreen, 0, 0);
    lv_obj_set_style_margin_all(ActiveScreen, 0, 0);
    
    App->CurrentTheme.main_font_color = lv_color_hex3(0x00F);
    App->CurrentTheme.sub_font_color = lv_color_hex3(0x0F0);
    App->CurrentTheme.main_color = lv_color_hex3(0xF0F);
    App->CurrentTheme.sub_color = lv_color_hex3(0x0FF);
    App->CurrentTheme.focused_color = lv_color_hex3(0xFF0);

    CreateSystemInfoPage(&App->PageSystemInfo, ActiveScreen);
    CreateClockPage(&App->PageClock, ActiveScreen);
    CreateMusicPage(&App->PageMusic, ActiveScreen);
    CreateSettingsPage(&App->PageSettings, ActiveScreen);

    CreateButtonLayout(App, App->PageMusic.Handle);
    return App;
}

void ShowPage(struct Application* App, int PageIndex, int SubPageIndex)
{
    lv_obj_add_flag(App->PageSystemInfo.Handle, LV_OBJ_FLAG_HIDDEN);
    lv_obj_add_flag(App->PageClock.Handle, LV_OBJ_FLAG_HIDDEN);
    lv_obj_add_flag(App->PageMusic.Handle, LV_OBJ_FLAG_HIDDEN);
    lv_obj_add_flag(App->PageSettings.Handle, LV_OBJ_FLAG_HIDDEN);

    switch (PageIndex)
    {
    case HomePageNum:
        break;
    case MusicPageNum:
        lv_obj_clear_flag(App->PageMusic.Handle, LV_OBJ_FLAG_HIDDEN);
        lv_obj_set_parent(App->RowLayout, App->PageMusic.Handle);
        lv_obj_set_style_bg_color(App->ButtonMusic, App->CurrentTheme.main_font_color, 0);
        break;
    case ClockPageNum:
        lv_obj_clear_flag(App->PageClock.Handle, LV_OBJ_FLAG_HIDDEN);
        lv_obj_set_parent(App->RowLayout, App->PageClock.Handle);
        lv_obj_set_style_bg_color(App->ButtonClock, App->CurrentTheme.main_font_color, 0);
        if (0 == SubPageIndex)
        {
            lv_obj_add_flag(App->PageClock.TimeUpPageHandle, LV_OBJ_FLAG_HIDDEN);
            lv_obj_clear_flag(App->PageClock.Handle, LV_OBJ_FLAG_HIDDEN);
        }
        else
        {
            lv_obj_add_flag(App->PageClock.Handle, LV_OBJ_FLAG_HIDDEN);
            lv_obj_clear_flag(App->PageClock.TimeUpPageHandle, LV_OBJ_FLAG_HIDDEN);
        }
        break;
    case SystemInfoPageNum:
        lv_obj_clear_flag(App->PageSystemInfo.Handle, LV_OBJ_FLAG_HIDDEN);
        lv_obj_set_parent(App->RowLayout, App->PageSystemInfo.Handle);
        lv_obj_set_style_bg_color(App->ButtonSystemInfo, App->CurrentTheme.main_font_color, 0);
        break;
    case SettingPageNum:
        ShowSettingPage(&App->PageSettings, SubPageIndex);
        lv_obj_set_parent(App->RowLayout, App->PageSettings.Handle);
        lv_obj_set_style_bg_color(App->ButtonSetting, App->CurrentTheme.main_font_color, 0);
        break;
    }
}

void Run(Application* App)
{
    //ShowPage(App, SettingPageNum, THEME_PAGE_NUM);
    ShowPage(App, ClockPageNum, 1);


    while (1)
    {
        uint32_t time_till_next = lv_timer_handler();
        lv_delay_ms(time_till_next);
    }
}