#include "ThemePage.h"
#include "LVGLDemo/Widgets/Widget.h"
void CreateThemePage(ThemePage* Page, lv_obj_t* Parent, const char* Title, int X, int Y, int W, int H, void* Pixels)
{
    Page->Parent = Parent;
    /*---------------------------------------------------------------------*/
    Page->Handle = CreateBase(Parent, X, Y, W, H, lv_color_hex3(0xFF0));
    Page->ImageTheme = CreateLabel(Page->Handle, 0, 0, LV_PCT(100), 50, "Theme1", lv_color_hex3(0xF00));

    return;
    Page->Handle = CreateBase(Parent, X, Y, W, H, lv_color_hex3(0xFFF));
    lv_obj_set_style_border_width(Page->Handle, 1, 0);       // 无边框
    lv_obj_set_style_radius(Page->Handle, 0, 0);             // 无圆角
    //return;
    /*---------------------------------------------------------------------*/

    //Page->ImageTheme = lv_image_create(Page->Handle);
    //lv_label_set_text_static(Page->ImageTheme, Title);
    //lv_obj_set_pos(Page->ImageTheme,  0, 100);
    //lv_obj_set_size(Page->ImageTheme, W, W);

    Page->LabelThemeTitle = lv_label_create(Page->Handle);
    lv_label_set_text_static(Page->LabelThemeTitle, Title);
    //lv_obj_set_style_text_color(Page->LabelThemeTitle, lv_color_hex(0xFF0000), 0);
    //lv_label_set_text_color(Page->LabelThemeTitle, lv_color_hex(0xFF0000));  // 红色
    lv_obj_set_pos(Page->LabelThemeTitle,  0, 0);
    lv_obj_set_size(Page->LabelThemeTitle, W, W - H);
}

