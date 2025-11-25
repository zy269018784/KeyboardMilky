#include "OtherSettingPage.h"
#include "../SettingsPage.h"
#include "Widgets/Widget.h"
#include "API/API.h"
void CreateSettingsOtherPage(SettingsPage* Page)
{
    Page->PageOther.Handle = CreateBase(Page->Handle, 0, 0, LV_PCT(100), LV_PCT(100), lv_color_hex3(0x0F0));
 
    int y;
    y = 10;
    Page->PageOther.LabelAutoScreenOff = CreateLabel(Page->PageOther.Handle, 6, y, 200, 20, "Auto Screen Off", lv_color_hex3(0xFF0));
    Page->PageOther.SwitchAutoScreenOff = CreateSwitch(Page->PageOther.Handle, 200, y, 200, 20, lv_color_hex3(0xFF0));

    y = 60;
    Page->PageOther.LabelAutoScreenOffTime = CreateLabel(Page->PageOther.Handle, 6, y, 200, 20, "Screen Off Time", lv_color_hex3(0xFF0));
    Page->PageOther.DropdownAutoScreenOffTime = CreateDropDown(Page->PageOther.Handle, 200, y, 200, 20, lv_color_hex3(0xFF0));
    lv_dropdown_set_options(Page->PageOther.DropdownAutoScreenOffTime,
        "1 min\n"
        "2 min\n"
        "5 min\n"
        "10 min\n"
        "20 min\n"
        "30 min\n"
    );

    y = 110;
    Page->PageOther.LabelPogoPin    = CreateLabel(Page->PageOther.Handle, 6, y, 200, 20, "PogoPin ", lv_color_hex3(0xFF0));
    Page->PageOther.SwitchPogoPin   = CreateSwitch(Page->PageOther.Handle, 200, y, 200, 20, lv_color_hex3(0xFF0));

    y = 170;
    Page->PageOther.ButtonFactoryReset = CreateButton(Page->PageOther.Handle, 0 + 10, y, 200, 50, lv_color_hex3(0xF00));
    Page->PageOther.LabelFactoryReset = CreateLabel(Page->PageOther.ButtonFactoryReset, 0, 0, LV_PCT(100), LV_PCT(100), "FactoryReset", lv_color_hex3(0xF00));

    ResetOtherSettingPage(&Page->PageOther);
}
