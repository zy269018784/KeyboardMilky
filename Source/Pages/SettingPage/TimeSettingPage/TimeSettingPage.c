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
    Page->PageClock.LabelAutoGetTime = CreateLabel(Page->PageClock.Handle, 6, y, 200, 20, "Auto Get Time", lv_color_hex3(0xFF0));
    Page->PageClock.SwitchAutoGetTime = CreateSwitch(Page->PageClock.Handle, 200, y, 200, 20, lv_color_hex3(0xFF0));

    y = 100;
    Page->PageClock.LabelTimeZone = CreateLabel(Page->PageClock.Handle, 6, y, 200, 20, "Time Zone", lv_color_hex3(0xFF0));
    Page->PageClock.DropdownTimeZone = CreateDropDown(Page->PageClock.Handle, 200, y, 200, 20, lv_color_hex3(0xFF0));
    lv_dropdown_set_options(Page->PageClock.DropdownTimeZone,
        "UTC+01:00\n"
        "UTC+02:00\n"
        "UTC+03:00\n"
        "UTC+04:00\n"
        "UTC+05:00\n"
        "UTC+06:00\n"
        "UTC+07:00\n"
        "UTC+08:00\n"
        "UTC+09:00\n"
        "UTC+10:00\n"
        "UTC+11:00\n"
        "UTC+12:00\n"
        "UTC+13:00\n"
        "UTC+14:00\n"
        "UTC+15:00\n"
        "UTC+16:00\n"
        "UTC+17:00\n"
        "UTC+18:00\n"
        "UTC+19:00\n"
        "UTC+20:00\n"
        "UTC+21:00\n"
        "UTC+22:00\n"
        "UTC+23:00\n"
        "UTC+24:00\n"
    );

    y = 150;
    Page->PageClock.LabelDateTime   = CreateLabel(Page->PageClock.Handle,    6,   y, 100, 20, "Date Time", lv_color_hex3(0xFF0));
    Page->PageClock.DropdownYear    = CreateDropDown(Page->PageClock.Handle, 100, y, 50, 20, lv_color_hex3(0xFF0));
    Page->PageClock.DropdownMonth   = CreateDropDown(Page->PageClock.Handle, 160, y, 50, 20, lv_color_hex3(0xFF0));
    Page->PageClock.DropdownDay     = CreateDropDown(Page->PageClock.Handle, 220, y, 50, 20, lv_color_hex3(0xFF0));
    Page->PageClock.DropdownHour    = CreateDropDown(Page->PageClock.Handle, 280, y, 50, 20, lv_color_hex3(0xFF0));
    Page->PageClock.DropdownMinute  = CreateDropDown(Page->PageClock.Handle, 340, y, 50, 20, lv_color_hex3(0xFF0));
    Page->PageClock.DropdownSecond  = CreateDropDown(Page->PageClock.Handle, 400, y, 50, 20, lv_color_hex3(0xFF0));
    lv_dropdown_set_options(Page->PageClock.DropdownYear,
        "2025\n"
        "2024\n"
    );
    lv_dropdown_set_options(Page->PageClock.DropdownMonth,
        "12\n"
        "11\n"
        "10\n"
        "9\n"
        "8\n"
        "7\n"
        "6\n"
        "5\n"
    );
    lv_dropdown_set_options(Page->PageClock.DropdownDay,
        "1\n"
        "2\n"
        "3\n"
        "4\n"
        "5\n"
        "6\n"
        "7\n"
        "8\n"
        "9\n"
        "10\n"
    );
    lv_dropdown_set_options(Page->PageClock.DropdownHour,
        "1\n"
        "2\n"
        "3\n"
        "4\n"
        "5\n"
        "6\n"
        "7\n"
        "8\n"
        "9\n"
        "10\n"
    );
    lv_dropdown_set_options(Page->PageClock.DropdownMinute,
        "1\n"
        "2\n"
        "3\n"
        "4\n"
        "5\n"
        "6\n"
        "7\n"
        "8\n"
        "9\n"
        "10\n"
    );
    lv_dropdown_set_options(Page->PageClock.DropdownSecond,
        "1\n"
        "2\n"
        "3\n"
        "4\n"
        "5\n"
        "6\n"
        "7\n"
        "8\n"
        "9\n"
        "10\n"
    );

    y = 200;
    Page->PageClock.LabelHomePageShowTime = CreateLabel(Page->PageClock.Handle, 6, y, 200, 20, "Home Page Show Time", lv_color_hex3(0xFF0));
    Page->PageClock.SwitchHomePageShowTime = CreateSwitch(Page->PageClock.Handle, 200, y, 200, 20, lv_color_hex3(0xFF0));



    y = 250;
    Page->PageClock.LabelTimeFormat = CreateLabel(Page->PageClock.Handle, 6, y, 200, 20, "Time Format", lv_color_hex3(0xFF0));
    Page->PageClock.DropdownTimeFormat = CreateDropDown(Page->PageClock.Handle, 200, y, 200, 20, lv_color_hex3(0xFF0));
    lv_dropdown_set_options(Page->PageClock.DropdownTimeFormat,
        "12\n"
        "24\n"
    );

    y = 300;
    Page->PageClock.LabelDateFormat = CreateLabel(Page->PageClock.Handle, 6, y, 200, 20, "Date Format", lv_color_hex3(0xFF0));
    Page->PageClock.DropdownDateFormat = CreateDropDown(Page->PageClock.Handle, 200, y, 200, 20, lv_color_hex3(0xFF0));

    lv_dropdown_set_options(Page->PageClock.DropdownDateFormat, 
        "9 August 2025\n"
        "9 August\n"
        "9 Aug\n"
        "2025年8月9日\n"
        "2025.8.9\n"
        "8月9日\n"
    );

    y = 350;
    Page->PageClock.LabelTimePos = CreateLabel(Page->PageClock.Handle, 6, y, 200, 20, "Time Pos", lv_color_hex3(0xFF0));
    Page->PageClock.DropdownTimePos = CreateDropDown(Page->PageClock.Handle, 200, y, 200, 20, lv_color_hex3(0xFF0));

    lv_dropdown_set_options(Page->PageClock.DropdownTimePos,
        "Left\n"
        "Right\n"
    );

    ResetTimeSettingPage(&Page->PageClock);
}



