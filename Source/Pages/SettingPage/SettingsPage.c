#include "SettingsPage.h"
#include "Widgets/Widget.h"
#include "Pages/SettingPage/ThemePage/ThemePage.h"
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

Point2 GetThemePos(int LinearIndex, int w, int h, int padding)
{
    int row = LinearIndex / 2;
    int col = LinearIndex % 2;
    return (Point2) { padding + col * (w + padding), row* (h + padding) };
}

void CreateSettingsWallpapperPage(SettingsPage* Page)
{
    int padding = 6;
    int H1 = 60 + 2 * 6;
    Point2 ButtonReturnSzie = { 60,   60 };
    Point2 LabelCurrentPageSize = { 180 , 60 };
    Point2 ReturnRowPos = { 0,    padding };
    Point2 ReturnRowSize = { 480,  60 };
    Point2 ContentRowPos = { 0,    ReturnRowPos.y + ReturnRowSize.y + padding };
    Point2 ContentRowSize = { 480,  480 - 3 * padding - ReturnRowSize.y };

    Page->PageWallpapper.Handle = CreateBase(Page->Handle, 0, 0, LV_PCT(100), LV_PCT(100), lv_color_hex3(0x0F0));
  //  Page->PageWallpapper.Label = CreateLabel(Page->PageWallpapper.Handle, 0, 0, LV_PCT(100), 50, "PageWallpapper", lv_color_hex3(0xF00));
    
    Page->PageWallpapper.ReturnRow = CreateBase(Page->Handle, ReturnRowPos.x, ReturnRowPos.y, ReturnRowSize.x, ReturnRowSize.y, lv_color_hex3(0x0F0));

    Page->PageWallpapper.ButtonReturn = CreateButton(Page->PageWallpapper.ReturnRow, 
        padding,
        0,
        ButtonReturnSzie.x,
        ButtonReturnSzie.y,
        lv_color_hex3(0xFF0));

    Page->PageWallpapper.LabelCurrentPage = CreateLabel(Page->PageWallpapper.ReturnRow, 
        2 * padding + ButtonReturnSzie.x,
        0,
        LabelCurrentPageSize.x,
        LabelCurrentPageSize.y,
        "Wallpapper", lv_color_hex3(0x0F0));

    Page->PageWallpapper.ButtonUSBDownload = CreateButton(Page->PageWallpapper.ReturnRow, 440, 0, 40, 40, lv_color_hex3(0xFF0));

    int w = (480 - 3 * padding) / 2, h = w;
    InitHead(&Page->PageWallpapper.WallpapperPageLists);
    for (int i = 0; i < 4; i++)
    {
        AddTail(&Page->PageWallpapper.WallpapperPageLists, &Page->PageWallpapper.Wallpappers[i].Node);
    }

    Page->PageWallpapper.ContentRow = CreateBase(Page->Handle, ContentRowPos.x, ContentRowPos.y, ContentRowSize.x, ContentRowSize.y, lv_color_hex3(0x0F0));
    ListNode* Node = Page->PageWallpapper.WallpapperPageLists.Head;
    for (int i = 0; i < Page->PageWallpapper.WallpapperPageLists.Count; i++)
    {
        WallpapperPage* TP = (WallpapperPage*)Node;
        Point2 Pos = GetThemePos(i, w, h, padding);
        CreateWallpapperPage(TP, Page->PageWallpapper.ContentRow, Pos.x, Pos.y, w, h, NULL);
        Node = Node->Next;
    }
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

void CreateSettingsThemePage(SettingsPage* Page)
{
    int padding = 6;
    int H1 = 60 + 2 * 6;
    Point2 ButtonReturnSzie     = { 60,   60 };
    Point2 LabelCurrentPageSize = { 180 , 60 };
    Point2 ReturnRowPos         = { 0,    padding };
    Point2 ReturnRowSize        = { 480,  60 };
    Point2 ContentRowPos        = { 0,    ReturnRowPos.y + ReturnRowSize.y + padding };
    Point2 ContentRowSize       = { 480,  480 - 3 * padding - ReturnRowSize .y};
    Page->PageTheme.Handle = CreateBase(Page->Handle, 0, 0, LV_PCT(100), LV_PCT(100), lv_color_hex3(0x0F0));
    
    /*
        H1
    */
    Page->PageTheme.ReturnRow = CreateBase(Page->Handle, ReturnRowPos.x, ReturnRowPos.y, LV_PCT(100), H1, lv_color_hex3(0x0F0));

    Page->PageTheme.ButtonReturn     = CreateButton(Page->PageTheme.ReturnRow, 
        padding,                    
        0,                       
        ButtonReturnSzie.x, 
        ButtonReturnSzie.y, 
        lv_color_hex3(0xFF0));

    Page->PageTheme.LabelCurrentPage = CreateLabel(Page->PageTheme.ReturnRow,  
        2 * padding + ButtonReturnSzie.x, 
        0, 
        LabelCurrentPageSize.x, 
        LabelCurrentPageSize.y, 
        "Theme", lv_color_hex3(0x0F0));
    //Page->PageTheme.ButtonUSBDownload = CreateButton(Page->PageTheme.ReturnRow, 440 - 6, 6, 40, 40, lv_color_hex3(0xFF0));
  
    /*
        H2
    */
    int w = (480 - 3 * padding) / 2, h = w + 2 * padding + 20; 
    InitHead(&Page->PageTheme.ThemePageLists);
    for (int i = 0; i < 4; i++)
    {
        AddTail(&Page->PageTheme.ThemePageLists, &Page->PageTheme.Themes[i].Node);
    }

    Page->PageTheme.ContentRow = CreateBase(Page->Handle, ContentRowPos.x, ContentRowPos.y, ContentRowSize.x, ContentRowSize.y, lv_color_hex3(0x0F0));
    ListNode* Node = Page->PageTheme.ThemePageLists.Head;
    for (int i = 0; i < Page->PageTheme.ThemePageLists.Count; i++)
    {
        ThemePage* TP = (ThemePage*)Node;
        printf("TP %p %p\n", TP, &TP->Node);
        Point2 ThemePos = GetThemePos(i, w, h, padding);
        CreateThemePage(TP, Page->PageTheme.ContentRow, "theme1", ThemePos.x, ThemePos.y, w, h, NULL);
        Node = Node->Next;
    }
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
    lv_obj_add_flag(Page->PageWallpapper.ReturnRow, LV_OBJ_FLAG_HIDDEN);
    lv_obj_add_flag(Page->PageWallpapper.ContentRow, LV_OBJ_FLAG_HIDDEN);

    lv_obj_add_flag(Page->PageTheme.Handle, LV_OBJ_FLAG_HIDDEN);
    lv_obj_add_flag(Page->PageTheme.ReturnRow, LV_OBJ_FLAG_HIDDEN);
    lv_obj_add_flag(Page->PageTheme.ContentRow, LV_OBJ_FLAG_HIDDEN);

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
        lv_obj_clear_flag(Page->PageTheme.ReturnRow, LV_OBJ_FLAG_HIDDEN);
        lv_obj_clear_flag(Page->PageTheme.ContentRow, LV_OBJ_FLAG_HIDDEN);
        lv_obj_clear_flag(Page->PageTheme.Handle, LV_OBJ_FLAG_HIDDEN);
        break;
    case WALLPAPER_PAGE_NUM:
        lv_obj_clear_flag(Page->PageWallpapper.ReturnRow, LV_OBJ_FLAG_HIDDEN);
        lv_obj_clear_flag(Page->PageWallpapper.ContentRow, LV_OBJ_FLAG_HIDDEN);
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