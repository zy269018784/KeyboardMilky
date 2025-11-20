#include "Pages/ClockPage/ClockPage.h"
#include "Widgets/Widget.h"
void CreateTheme3ClockPage(ClockPage* Page, lv_obj_t* Parent, Theme* Theme)
{
    /*---------------------------------------------------------------------*/
    Page->Parent = Parent;
    /*---------------------------------------------------------------------*/
    Page->Handle = CreateBase(Parent, 0, 0, LV_PCT(100), LV_PCT(100), lv_color_hex3(0xF00));
    /*---------------------------------------------------------------------*/
    /*
        开始按钮
    */
    Page->start_button = CreateButton(Page->Handle, 420, 0, 50, 50, lv_color_hex3(0xF0F));
    lv_obj_set_style_radius(Page->start_button, 25, 0);
    /*---------------------------------------------------------------------*/
    /*
        结束按钮
    */
    Page->stop_button = CreateButton(Page->Handle, 420, 10, 50, 50, lv_color_hex3(0xF00));
    lv_obj_set_style_radius(Page->stop_button, 25, 0);
    lv_obj_add_flag(Page->stop_button, LV_OBJ_FLAG_HIDDEN);

    /*---------------------------------------------------------------------*/
    /*
        设置时间按钮标签
    */
    Page->setting_time_button_label = CreateLabel(Page->Handle, 10, 400, 200, 50, "25:00", lv_color_hex3(0xF00));
    lv_obj_set_style_text_align(Page->setting_time_button_label, LV_TEXT_ALIGN_CENTER, 0);
    //lv_obj_center(Page->setting_time_button_label);
    /*---------------------------------------------------------------------*/

    CreateTheme3ClockPageTimeUp(Page, Parent, Theme);
}

void CreateTheme3ClockPageTimeUp(ClockPage* Page, lv_obj_t* Parent, Theme* Theme)
{
    Page->TimeUpPageHandle = CreateBase(Parent, 0, 0, LV_PCT(100), LV_PCT(100), lv_color_hex3(0xFF0));
    /*
        返回按钮
    */
    Page->back_button = CreateButton(Page->TimeUpPageHandle, 420, 10, 50, 50, lv_color_hex3(0x0F0));
    /*
        设置radius
    */
    lv_obj_set_style_radius(Page->back_button, 25, 0);
    /*
        设置时间按钮标签
    */
    Page->time_end_label = CreateLabel(Page->TimeUpPageHandle, 10, 190, LV_PCT(100), 50, "25:00", lv_color_hex3(0xFFF));
    //lv_obj_set_style_text_font(Page->time_end_label, &lv_font_montserrat_14, 0);
    lv_obj_set_style_text_align(Page->time_end_label, LV_TEXT_ALIGN_CENTER, 0);
    //lv_obj_center(Page->time_end_label);

    Page->time_up_label = CreateLabel(Page->TimeUpPageHandle, 10, 240, LV_PCT(100), 50, "Time UP", lv_color_hex3(0xFFF));
    lv_obj_set_style_text_align(Page->time_up_label, LV_TEXT_ALIGN_CENTER, 0);;
    /*---------------------------------------------------------------------*/
}
