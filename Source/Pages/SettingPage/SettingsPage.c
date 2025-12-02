#include "SettingsPage.h"
#include "Widgets/Widget.h"
#include "Pages/SettingPage/ThemeSettingPage/ThemePage.h"

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

    int padding = 6;
    int H1 = 60 + 2 * 6;
    Page->ButtonReturnSzie.x = 60;
    Page->ButtonReturnSzie.y = 60;
    Page->LabelCurrentPageSize.x = 180;
    Page->LabelCurrentPageSize.y = 60;
    Page->ReturnRowPos.x = 0;
    Page->ReturnRowPos.y = padding;
    Page->ReturnRowSize.x = 480;
    Page->ReturnRowSize.y = 60;

    Page->ReturnRow  = CreateBase(Parent, 0, 0, LV_PCT(100), 50, lv_color_hex3(0xF00));
    Page->ButtonReturn = CreateButton(Page->ReturnRow,
    padding,
    0,
    Page->ButtonReturnSzie.x,
    Page->ButtonReturnSzie.y,
    lv_color_hex3(0xFF0));

    Page->LabelCurrentPage = CreateLabel(Page->ReturnRow,
        2 * padding + Page->ButtonReturnSzie.x,
        0,
        Page->LabelCurrentPageSize.x,
        Page->LabelCurrentPageSize.y,
        "Wallpapper", lv_color_hex3(0x0F0));

    Page->ButtonUSBDownload = CreateButton(Page->ReturnRow, 440, 0, 40, 40, lv_color_hex3(0xFF0));
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

Point2 GetThemePos(int LinearIndex, int w, int h, int padding)
{
    int row = LinearIndex / 2;
    int col = LinearIndex % 2;
    return (Point2) { padding + col * (w + padding), row* (h + padding) };
}


/*
    h1 + h2 = 480
    ------------------------------------------------------------
                padding
    h1 padding  button  padding label     
                padding
    ------------------------------------------------------------
                padding    
    h2  padding theme1   padding    theme2  padding
                padding
        padding theme1   padding    theme2  padding
    ------------------------------------------------------------
*/

//Point2 GetThemePos(int LinearIndex, int w, int h, int padding)
//{
//    int row = LinearIndex / 2;
//    int col = LinearIndex % 2;
//    return (Point2){ padding + col * (w + padding), row * (h + padding) };
//}
void ShowSettingPage(SettingsPage* Page, int PageNo)
{
    lv_obj_clear_flag(Page->Handle, LV_OBJ_FLAG_HIDDEN);

    lv_obj_add_flag(Page->PageHome.Handle, LV_OBJ_FLAG_HIDDEN);

    lv_obj_add_flag(Page->ReturnRow, LV_OBJ_FLAG_HIDDEN);

    lv_obj_add_flag(Page->PageWallpapper.Handle, LV_OBJ_FLAG_HIDDEN);
    lv_obj_add_flag(Page->PageWallpapper.ContentRow, LV_OBJ_FLAG_HIDDEN);

    lv_obj_add_flag(Page->PageTheme.Handle, LV_OBJ_FLAG_HIDDEN);
    lv_obj_add_flag(Page->PageTheme.ContentRow, LV_OBJ_FLAG_HIDDEN);

    lv_obj_add_flag(Page->PageDock.Handle, LV_OBJ_FLAG_HIDDEN);
    lv_obj_add_flag(Page->PageClock.Handle, LV_OBJ_FLAG_HIDDEN);
    lv_obj_add_flag(Page->PageOther.Handle, LV_OBJ_FLAG_HIDDEN);
    lv_obj_add_flag(Page->PageUpdate.Handle, LV_OBJ_FLAG_HIDDEN);

    /*
     *  主页隐藏返回行
     */
    lv_obj_clear_flag(Page->ReturnRow, LV_OBJ_FLAG_HIDDEN);
    switch (PageNo)
    {
        case SETTING_HOME_PAGE_NUM:
        lv_obj_add_flag(Page->ReturnRow, LV_OBJ_FLAG_HIDDEN);
        lv_obj_clear_flag(Page->PageHome.Handle, LV_OBJ_FLAG_HIDDEN);
        break;
    case THEME_PAGE_NUM:
        lv_obj_set_parent(Page->ReturnRow, Page->PageTheme.Handle);
        lv_label_set_text_static(Page->LabelCurrentPage, "Theme");
        lv_obj_clear_flag(Page->PageTheme.ContentRow, LV_OBJ_FLAG_HIDDEN);
        lv_obj_clear_flag(Page->PageTheme.Handle, LV_OBJ_FLAG_HIDDEN);
        break;
    case WALLPAPER_PAGE_NUM:
        lv_obj_set_parent(Page->ReturnRow, Page->PageWallpapper.Handle);
        lv_label_set_text_static(Page->LabelCurrentPage, "Wallpapper");
        lv_obj_clear_flag(Page->PageWallpapper.ContentRow, LV_OBJ_FLAG_HIDDEN);
        lv_obj_clear_flag(Page->PageWallpapper.Handle, LV_OBJ_FLAG_HIDDEN);
        break;
    case DOCK_PAGE_NUM:
        lv_obj_set_parent(Page->ReturnRow, Page->PageDock.Handle);
        lv_label_set_text_static(Page->LabelCurrentPage, "Dock");
        lv_obj_clear_flag(Page->PageDock.Handle, LV_OBJ_FLAG_HIDDEN);
        break;
    case CLOCK_PAGE_NUM:
        lv_obj_set_parent(Page->ReturnRow, Page->PageClock.Handle);
        lv_label_set_text_static(Page->LabelCurrentPage, "Clock");
        lv_obj_clear_flag(Page->PageClock.Handle, LV_OBJ_FLAG_HIDDEN);
        break;
    case OTHER_PAGE_NUM:
        lv_obj_set_parent(Page->ReturnRow, Page->PageOther.Handle);
        lv_label_set_text_static(Page->LabelCurrentPage, "Other");
        lv_obj_clear_flag(Page->PageOther.Handle, LV_OBJ_FLAG_HIDDEN);
        break;
    case UPDATE_PAGE_NUM:
        lv_obj_set_parent(Page->ReturnRow, Page->PageUpdate.Handle);
        lv_label_set_text_static(Page->LabelCurrentPage, "Upgrade");
        lv_obj_clear_flag(Page->PageUpdate.Handle, LV_OBJ_FLAG_HIDDEN);
        break;
    }
}