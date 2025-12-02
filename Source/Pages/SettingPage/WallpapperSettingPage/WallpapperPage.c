#include "WallpapperPage.h"
#include "Widgets/Widget.h"
#include "Util/Image.h"
#include "../SettingsPage.h"

void CreateWallpapperPage(WallpapperPage* Page, lv_obj_t* Parent, int X, int Y, int W, int H, void* Pixels)
{
    /*---------------------------------------------------------------------*/
    Page->Handle = CreateBase(Parent, X, Y, W, H, lv_color_hex3(0xFF0));

    Page->ImageTheme = CreateImage(Page->Handle, 0, 0, W, W, lv_color_hex3(0x0fF));
    lv_obj_set_style_radius(Page->ImageTheme, 20, 0);
    lv_image_set_scale_x(Page->ImageTheme, 256 * (1.f * W / theme.header.w));
    lv_image_set_scale_y(Page->ImageTheme, 256 * (1.f * W / theme.header.h));
    lv_image_set_src(Page->ImageTheme, &theme);

    Page->ButtonApply = CreateButton(Page->ImageTheme, W / 2 - 50, W - 40, 100, 20, lv_color_hex3(0xFFF));
    lv_obj_set_style_radius(Page->ButtonApply, 10, 0);

    Page->LabelApply = CreateLabel(Page->ButtonApply, 0, 0, LV_PCT(100), LV_PCT(100), "Apply", lv_color_hex3(0xF0F));
    lv_obj_set_style_text_align(Page->ButtonApply, LV_TEXT_ALIGN_CENTER, 0);
    lv_obj_set_style_text_color(Page->ButtonApply, lv_color_hex3(0x000), 0);
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
#if 0
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
#endif
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
