#include "OtherSettingPage.h"
#include "Application.h"
#include "../SettingsPage.h"
#include "Widgets/Widget.h"
#include "API/API.h"
void CreateSettingsOtherPage(SettingsPage* Page)
{

    lv_obj_t *obj = NULL;
    lv_color_t color = App->color1;
    Page->PageOther.Handle = CreateBase(Page->Handle, 0, 0, LV_PCT(100), LV_PCT(100), color);
 
    int y;
    y = Page->ReturnRowSize.y;

    Page->PageOther.LabelAutoScreenOff = CreateLabel(Page->PageOther.Handle, 6, y, 200, 20, "ScreenAlwaysOn", App->color1);
    lv_obj_add_style(Page->PageOther.LabelAutoScreenOff, &App->WhiteStyle, 0);

    Page->PageOther.SwitchAutoScreenOff = CreateSwitch(Page->PageOther.Handle, 200, y, 200, 20, App->color1);
    obj = Page->PageOther.SwitchAutoScreenOff;
    lv_obj_set_style_radius(obj, 10, 0);
    lv_obj_set_style_bg_color(obj, App->color1, LV_PART_MAIN);
    lv_obj_set_style_bg_color(obj, App->color1, LV_PART_INDICATOR);  // 灰色
    lv_obj_set_style_bg_color(obj, App->color1, LV_PART_INDICATOR | LV_STATE_CHECKED);  // 绿色
    lv_obj_set_style_bg_color(obj, App->color2, LV_PART_KNOB | LV_STATE_CHECKED);
    lv_obj_set_style_bg_color(obj, App->color3, LV_PART_KNOB);
    lv_obj_set_style_border_color(obj, App->color2, 0);
    lv_obj_set_style_border_width(obj, 2, 0);

    y += 40;
    Page->PageOther.LabelAutoScreenOffTime = CreateLabel(Page->PageOther.Handle, 6, y, 200, 20, "Screen Off Time", lv_color_hex3(0xFF0));
    lv_obj_add_style(Page->PageOther.LabelAutoScreenOffTime, &App->WhiteStyle, 0);
    Page->PageOther.DropdownAutoScreenOffTime = CreateDropDown(Page->PageOther.Handle, 200, y, 200, 20, lv_color_hex3(0xFF0));
    obj = Page->PageOther.DropdownAutoScreenOffTime;
    lv_obj_set_style_bg_color(obj, App->color2, LV_PART_MAIN);
    lv_dropdown_set_options(Page->PageOther.DropdownAutoScreenOffTime,
        "1 min\n"
        "2 min\n"
        "5 min\n"
        "10 min\n"
        "20 min\n"
        "30 min\n"
    );

    y += 40;
    Page->PageOther.LabelPogoPin    = CreateLabel(Page->PageOther.Handle, 6, y, 200, 40, "Change Theme Automatically", lv_color_hex3(0xFF0));
    lv_obj_add_style(Page->PageOther.LabelPogoPin, &App->WhiteStyle, 0);
    Page->PageOther.SwitchPogoPin   = CreateSwitch(Page->PageOther.Handle, 200, y, 200, 20, lv_color_hex3(0xFF0));
    obj = Page->PageOther.SwitchPogoPin;
    lv_obj_set_style_radius(obj, 10, 0);
    lv_obj_set_style_bg_color(obj, App->color1, LV_PART_MAIN);
    lv_obj_set_style_bg_color(obj, App->color1, LV_PART_INDICATOR);  // 灰色
    lv_obj_set_style_bg_color(obj, App->color1, LV_PART_INDICATOR | LV_STATE_CHECKED);  // 绿色
    lv_obj_set_style_bg_color(obj, App->color2, LV_PART_KNOB | LV_STATE_CHECKED);
    lv_obj_set_style_bg_color(obj, App->color3, LV_PART_KNOB);
    lv_obj_set_style_border_color(obj, App->color2, 0);
    lv_obj_set_style_border_width(obj, 2, 0);


    y = 480 - 50;
    Page->PageOther.ButtonFactoryReset = CreateButton(Page->PageOther.Handle, 180, y,        120, 50, App->color1);
    Page->PageOther.LabelFactoryReset = CreateLabel(Page->PageOther.ButtonFactoryReset, 0, 0, LV_PCT(100), LV_PCT(100), "FactoryReset", lv_color_hex3(0xF00));
    obj = Page->PageOther.LabelFactoryReset;
    lv_obj_add_style(obj, &App->WhiteStyle, 0);
    ResetOtherSettingPage(&Page->PageOther);
}
