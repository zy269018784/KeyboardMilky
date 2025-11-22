#include "ThemePage.h"
#include "Widgets/Widget.h"
#include "Util/Image.h"
/*
    https://lvgl.io/tools/imageconverter
    https://blog.csdn.net/m0_74676415/article/details/144867497
*/ 


void CreateThemePage(ThemePage* Page, lv_obj_t* Parent, const char* Title, int X, int Y, int W, int H, void* Pixels)
{
    //Page->Parent = Parent;
    /*---------------------------------------------------------------------*/
    Page->Handle = CreateBase(Parent, X, Y, W, H, lv_color_hex3(0x000));

    Page->ImageTheme = CreateImage(Page->Handle, 0, 0, W, W, lv_color_hex3(0x0fF));
    lv_obj_set_style_radius(Page->ImageTheme, 20, 0);
    //lv_obj_set_style_bg_opa(Page->ImageTheme, LV_OPA_COVER, 0);  


    lv_image_set_scale_x(Page->ImageTheme, 256 * (1.f * W / theme.header.w));
    lv_image_set_scale_y(Page->ImageTheme, 256 * (1.f * W / theme.header.h));
    lv_image_set_src(Page->ImageTheme, &ikutaerika);
    
    //lv_obj_set_width(Page->ImageTheme, LV_SIZE_CONTENT);
    //lv_obj_set_height(Page->ImageTheme, LV_SIZE_CONTENT);
   // lv_obj_center(Page->ImageTheme);
   // lv_image_set_src(Page->ImageTheme, "G:/Project/KeyboardMilky_build/09.bin");
    //lv_image_set_src(Page->ImageTheme, "09.bin");

    //lv_image_set_scale_x(Page->ImageTheme, 2);
    //lv_image_set_scale_y(Page->ImageTheme, 0.5);
 
    Page->ButtonApply = CreateButton(Page->ImageTheme, W / 2 - 50, W - 40, 100, 20, lv_color_hex3(0xFFF));
    lv_obj_set_style_radius(Page->ButtonApply, 10, 0);

    Page->LabelApply = CreateLabel(Page->ButtonApply, 0, 0, LV_PCT(100), LV_PCT(100), "Apply", lv_color_hex3(0xF0F));
    lv_obj_set_style_text_align(Page->ButtonApply, LV_TEXT_ALIGN_CENTER, 0);  
    lv_obj_set_style_text_color(Page->ButtonApply, lv_color_hex3(0x000), 0);

    Page->LabelThemeTitle = CreateLabel(Page->Handle, 0, H - 20 - 6, LV_PCT(100), 20, Title, lv_color_hex3(0x000));
    lv_obj_set_style_radius(Page->LabelThemeTitle, 10, 0);
    lv_obj_set_style_text_color(Page->LabelThemeTitle, lv_color_hex3(0xFFF), 0);
    lv_obj_set_style_text_align(Page->LabelThemeTitle, LV_TEXT_ALIGN_CENTER, 0);
    lv_obj_set_style_bg_color(Page->LabelThemeTitle, lv_color_hex3(0x000), 0);
    lv_obj_set_style_bg_opa(Page->LabelThemeTitle, LV_OPA_COVER, 0);
}

