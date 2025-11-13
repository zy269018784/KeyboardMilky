#include "SettingsPage.h"
#include "LVGLDemo/Widgets/Widget.h"
#include "LVGLDemo/Pages/ThemePage.h"
#include <stdio.h>
void CreateSettingsHomePage(SettingsPage* Page);
void CreateSettingsWallpapperPage(SettingsPage* Page);
void CreateSettingsThemePage(SettingsPage* Page);
void CreateSettingsDockPage(SettingsPage* Page);
void CreateSettingsClockPage(SettingsPage* Page);
void CreateSettingsOtherPage(SettingsPage* Page);
void CreateSettingsUpdatePage(SettingsPage* Page);

void CreateSettingsPage(SettingsPage* Page, lv_obj_t* Parent)
{
    Page->Parent = Parent;
    Page->Handle  = CreateBase(Parent, 0, 0, LV_PCT(100), LV_PCT(100), lv_color_hex3(0xF00));
    CreateSettingsHomePage(Page);
    CreateSettingsWallpapperPage(Page);
    CreateSettingsThemePage(Page);
    CreateSettingsDockPage(Page);
    CreateSettingsClockPage(Page);
    CreateSettingsOtherPage(Page);
    CreateSettingsUpdatePage(Page);
}

void CreateSettingsHomePage(SettingsPage* Page)
{
    Page->PageHome.Handle = CreateBase(Page->Handle, 0, 0, LV_PCT(100), LV_PCT(100), lv_color_hex3(0x0F0));

    int32_t w = LV_PCT(100);
    Page->PageHome.ButtonWallpapper = CreateButton(Page->PageHome.Handle, 0, 0, w, 50, lv_color_hex3(0xF0F));
    Page->PageHome.LabelWallpapper = CreateLabel(Page->PageHome.ButtonWallpapper, 0, 0, w, 50, "Wallpapper", lv_color_hex3(0xF00));
    lv_obj_set_style_text_align(Page->PageHome.LabelWallpapper, LV_TEXT_ALIGN_CENTER, 0);
    Page->PageHome.ButtonTheme = CreateButton(Page->PageHome.Handle, 0, 50, w, 50, lv_color_hex3(0x00F));
    Page->PageHome.LabelTheme = CreateLabel(Page->PageHome.ButtonTheme, 0, 0, w, 50, "Theme", lv_color_hex3(0x00F));
    Page->PageHome.ButtonDock = CreateButton(Page->PageHome.Handle, 0, 100, w, 50, lv_color_hex3(0x00F));
    Page->PageHome.LabelDock = CreateLabel(Page->PageHome.ButtonDock, 0, 0, w, 50, "Dock", lv_color_hex3(0x00F));
    Page->PageHome.ButtonClock = CreateButton(Page->PageHome.Handle, 0, 150, w, 50, lv_color_hex3(0x00F));
    Page->PageHome.LabelClock = CreateLabel(Page->PageHome.ButtonClock, 0, 0, w, 50, "Clock", lv_color_hex3(0x00F));
    Page->PageHome.ButtonOther = CreateButton(Page->PageHome.Handle, 0, 200, w, 50, lv_color_hex3(0x00F));
    Page->PageHome.LabelOther = CreateLabel(Page->PageHome.ButtonOther, 0, 0, w, 50, "Other", lv_color_hex3(0x00F));
    Page->PageHome.ButtonUpdate = CreateButton(Page->PageHome.Handle, 0, 250, w, 50, lv_color_hex3(0x00F));
    Page->PageHome.LabelUpdate = CreateLabel(Page->PageHome.ButtonUpdate, 0, 0, w, 50, "Update", lv_color_hex3(0x00F));
}

void CreateSettingsWallpapperPage(SettingsPage* Page)
{
    Page->PageWallpapper.Handle = CreateBase(Page->Handle, 0, 0, LV_PCT(100), LV_PCT(100), lv_color_hex3(0x0F0));
    Page->PageWallpapper.Label = CreateLabel(Page->PageWallpapper.Handle, 0, 0, LV_PCT(100), 50, "PageWallpapper", lv_color_hex3(0xF00));
}

void CreateSettingsThemePage(SettingsPage* Page)
{
    Page->PageTheme.Handle = CreateBase(Page->Handle, 0, 0, LV_PCT(100), LV_PCT(100), lv_color_hex3(0x0F0));
    Page->PageTheme.Label = CreateLabel(Page->PageTheme.Handle, 0, 0, LV_PCT(100), 50, "PageTheme", lv_color_hex3(0xF00));

    //return;
    CreateThemePage(&Page->PageTheme.Themes[0], Page->PageTheme.Handle, "theme1", 0,     0, 150, 200, NULL);
    return;
    CreateThemePage(&Page->PageTheme.Themes[1], Page->PageTheme.Handle, "theme2", 300,   0, 200, 400, NULL);
    CreateThemePage(&Page->PageTheme.Themes[2], Page->PageTheme.Handle, "theme3", 600,   0, 200, 400, NULL);
    CreateThemePage(&Page->PageTheme.Themes[3], Page->PageTheme.Handle, "theme4", 900,   0, 200, 400, NULL);
    CreateThemePage(&Page->PageTheme.Themes[4], Page->PageTheme.Handle, "theme5", 0,   500, 200, 400, NULL);
    CreateThemePage(&Page->PageTheme.Themes[5], Page->PageTheme.Handle, "theme6", 300, 500, 200, 400, NULL);
    CreateThemePage(&Page->PageTheme.Themes[6], Page->PageTheme.Handle, "theme7", 600, 500, 200, 400, NULL);
    CreateThemePage(&Page->PageTheme.Themes[7], Page->PageTheme.Handle, "theme8", 900, 500, 200, 400, NULL);
}

void CreateSettingsDockPage(SettingsPage* Page)
{
    Page->PageDock.Handle = CreateBase(Page->Handle, 0, 0, LV_PCT(100), LV_PCT(100), lv_color_hex3(0x0F0));
    Page->PageDock.Label = CreateLabel(Page->PageDock.Handle, 0, 0, LV_PCT(100), 50, "PageDock", lv_color_hex3(0xF00));
}

void CreateSettingsClockPage(SettingsPage* Page)
{
    Page->PageClock.Handle = CreateBase(Page->Handle, 0, 0, LV_PCT(100), LV_PCT(100), lv_color_hex3(0x0F0));
    Page->PageClock.Label = CreateLabel(Page->PageClock.Handle, 0, 0, LV_PCT(100), 50, "PageClock", lv_color_hex3(0xF00));
}

void CreateSettingsOtherPage(SettingsPage* Page)
{
    Page->PageOther.Handle = CreateBase(Page->Handle, 0, 0, LV_PCT(100), LV_PCT(100), lv_color_hex3(0x0F0));
    Page->PageOther.Label = CreateLabel(Page->PageOther.Handle, 0, 0, LV_PCT(100), 50, "PageOther", lv_color_hex3(0xF00));
}

void CreateSettingsUpdatePage(SettingsPage* Page)
{
    Page->PageUpdate.Handle = CreateBase(Page->Handle, 0, 0, LV_PCT(100), LV_PCT(100), lv_color_hex3(0x0F0));
    Page->PageUpdate.Label = CreateLabel(Page->PageUpdate.Handle, 0, 0, LV_PCT(100), 50, "PageUpdate", lv_color_hex3(0xF00));
}

void ShowSettingPage(SettingsPage* Page, int PageNo)
{
    lv_obj_clear_flag(Page->Handle, LV_OBJ_FLAG_HIDDEN);

    lv_obj_add_flag(Page->PageHome.Handle, LV_OBJ_FLAG_HIDDEN);
    lv_obj_add_flag(Page->PageWallpapper.Handle, LV_OBJ_FLAG_HIDDEN);
    lv_obj_add_flag(Page->PageTheme.Handle, LV_OBJ_FLAG_HIDDEN);
    lv_obj_add_flag(Page->PageDock.Handle, LV_OBJ_FLAG_HIDDEN);
    lv_obj_add_flag(Page->PageClock.Handle, LV_OBJ_FLAG_HIDDEN);
    lv_obj_add_flag(Page->PageOther.Handle, LV_OBJ_FLAG_HIDDEN);
    lv_obj_add_flag(Page->PageUpdate.Handle, LV_OBJ_FLAG_HIDDEN);

    switch (PageNo)
    {
    case SETTING_HOME_PAGE_NUM:
        lv_obj_clear_flag(Page->PageHome.Handle, LV_OBJ_FLAG_HIDDEN);
        break;
    case THEME_PAGE_NUM:
        lv_obj_clear_flag(Page->PageTheme.Handle, LV_OBJ_FLAG_HIDDEN);
        break;
    case WALLPAPER_PAGE_NUM:
        lv_obj_clear_flag(Page->PageWallpapper.Handle, LV_OBJ_FLAG_HIDDEN);
        break;
    case DOCK_PAGE_NUM:
        lv_obj_clear_flag(Page->PageDock.Handle, LV_OBJ_FLAG_HIDDEN);
        break;
    case CLOCK_PAGE_NUM:
        lv_obj_clear_flag(Page->PageClock.Handle, LV_OBJ_FLAG_HIDDEN);
        break;
    case OTHER_PAGE_NUM:
        lv_obj_clear_flag(Page->PageOther.Handle, LV_OBJ_FLAG_HIDDEN);
        break;
    case UPDATE_PAGE_NUM:
        lv_obj_clear_flag(Page->PageUpdate.Handle, LV_OBJ_FLAG_HIDDEN);
        break;
    }
}