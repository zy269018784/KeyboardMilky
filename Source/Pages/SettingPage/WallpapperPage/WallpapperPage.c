#include "WallpapperPage.h"
#include "Widgets/Widget.h"
#include "Util/Image.h"
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

