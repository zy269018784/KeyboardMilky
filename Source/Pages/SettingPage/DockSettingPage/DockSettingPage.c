#include "DockSettingPage.h"
#include "../SettingsPage.h"
#include "Widgets/Widget.h"
#include "API/API.h"
#include "Application.h"
void CreateSettingsDockPage(SettingsPage* Page)
{
    lv_obj_t *obj = NULL;

    Page->PageDock.Handle = CreateBase(Page->Handle, 0, 0, LV_PCT(100), LV_PCT(100), App->color1);

    Page->PageDock.LabelShowDock = CreateLabel(Page->PageDock.Handle, 6, 100, 100, 20, "Enable Dock", lv_color_hex3(0xFF0));
    lv_obj_add_style(Page->PageDock.LabelShowDock, &App->WhiteStyle, 0);


    Page->PageDock.SwitchShowDock = CreateSwitch(Page->PageDock.Handle, 200, 100, 200, 20, lv_color_hex3(0xFF0));
    obj = Page->PageDock.SwitchShowDock ;
    lv_obj_set_style_radius(obj, 10, 0);
    lv_obj_set_style_bg_color(obj, App->color1, LV_PART_MAIN);
    lv_obj_set_style_bg_color(obj, App->color1, LV_PART_INDICATOR);  // 灰色
    lv_obj_set_style_bg_color(obj, App->color1, LV_PART_INDICATOR | LV_STATE_CHECKED);  // 绿色
    lv_obj_set_style_bg_color(obj, App->color2, LV_PART_KNOB | LV_STATE_CHECKED);
    lv_obj_set_style_bg_color(obj, App->color3, LV_PART_KNOB);
    lv_obj_set_style_border_color(obj, App->color2, 0);
    lv_obj_set_style_border_width(obj, 2, 0);

    Page->PageDock.LabelAutoHideDock = CreateLabel(Page->PageDock.Handle, 6, 140, 200, 20, "Auto Hide Dock", lv_color_hex3(0xFF0));
    lv_obj_add_style(Page->PageDock.LabelAutoHideDock , &App->WhiteStyle, 0);

    Page->PageDock.SwitchAutoHideDock = CreateSwitch(Page->PageDock.Handle, 200, 140, 200, 20, lv_color_hex3(0xFF0));
    obj = Page->PageDock.SwitchAutoHideDock;
    lv_obj_set_style_radius(obj, 10, 0);
    lv_obj_set_style_bg_color(obj, App->color1, LV_PART_MAIN);
    lv_obj_set_style_bg_color(obj, App->color1, LV_PART_INDICATOR);  // 灰色
    lv_obj_set_style_bg_color(obj, App->color1, LV_PART_INDICATOR | LV_STATE_CHECKED);  // 绿色
    lv_obj_set_style_bg_color(obj, App->color2, LV_PART_KNOB | LV_STATE_CHECKED);
    lv_obj_set_style_bg_color(obj, App->color3, LV_PART_KNOB);
    lv_obj_set_style_border_color(obj, App->color2, 0);
    lv_obj_set_style_border_width(obj, 2, 0);

    ResetDockSettingPage(&Page->PageDock);
}