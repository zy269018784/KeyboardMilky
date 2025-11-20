#include "ThemePage.h"
#include "Widgets/Widget.h"
void CreateThemePage(ThemePage* Page, lv_obj_t* Parent, const char* Title, int X, int Y, int W, int H, void* Pixels)
{
    Page->Parent = Parent;
    /*---------------------------------------------------------------------*/
    Page->Handle = CreateBase(Parent, X, Y, W, H, lv_color_hex3(0xFF0));

    Page->LabelThemeTitle = CreateLabel(Page->Handle, 0, H - 20, LV_PCT(100), 20, Title, lv_color_hex3(0xF00));
    lv_obj_set_style_text_align(Page->LabelThemeTitle, LV_TEXT_ALIGN_CENTER, 0);
    lv_obj_set_style_bg_color(Page->LabelThemeTitle, lv_color_hex(0x3498db), 0);
    lv_obj_set_style_bg_opa(Page->LabelThemeTitle, LV_OPA_COVER, 0);

    Page->ButtonApply = CreateButton(Page->Handle, 0, H - 40, LV_PCT(100), 20, lv_color_hex3(0xF00));
    Page->LabelApply = CreateLabel(Page->ButtonApply, 0, 0, LV_PCT(100), LV_PCT(100), "Apply", lv_color_hex3(0xF0F));
    lv_obj_set_style_text_align(Page->ButtonApply, LV_TEXT_ALIGN_CENTER, 0);
}

