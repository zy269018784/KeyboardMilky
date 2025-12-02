#include "TimeSettingPage.h"
#include "../SettingsPage.h"
#include "Widgets/Widget.h"
#include "Application.h"
#include "SystemSettings/SystemSettings.h"
#include "API/API.h"
void CreateSettingsClockPage(SettingsPage* Page)
{
    Page->PageClock.Handle = CreateBase(Page->Handle, 0, 0, LV_PCT(100), LV_PCT(100), lv_color_hex3(0x0F0));

    int y;
    

    y = 50;
    Page->PageClock.LabelAutoGetTime = CreateLabel(Page->PageClock.Handle, 6, y, 200, 20, "Resync Time", lv_color_hex3(0xFF0));
    Page->PageClock.SwitchAutoGetTime = CreateSwitch(Page->PageClock.Handle, 200, y, 200, 20, lv_color_hex3(0xFF0));

    y = 100;
    Page->PageClock.LabelHideTime = CreateLabel(Page->PageClock.Handle, 6, y, 200, 20, "Hide Time", lv_color_hex3(0xFF0));
    Page->PageClock.SwitchHideTime = CreateSwitch(Page->PageClock.Handle, 200, y, 200, 20, lv_color_hex3(0xFF0));


    y = 200;
    Page->PageClock.LabeHideDate = CreateLabel(Page->PageClock.Handle, 6, y, 200, 20, "Hide Date", lv_color_hex3(0xFF0));
    Page->PageClock.SwitchHideDate = CreateSwitch(Page->PageClock.Handle, 200, y, 200, 20, lv_color_hex3(0xFF0));


    ResetTimeSettingPage(&Page->PageClock);
}



