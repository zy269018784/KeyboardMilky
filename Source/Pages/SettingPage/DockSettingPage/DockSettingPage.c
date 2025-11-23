#include "DockSettingPage.h"
#include "../SettingsPage.h"
#include "Widgets/Widget.h"

void CreateSettingsDockPage(SettingsPage* Page)
{
    Page->PageDock.Handle = CreateBase(Page->Handle, 0, 0, LV_PCT(100), LV_PCT(100), lv_color_hex3(0x0F0));

    Page->PageDock.LabelShowDock = CreateLabel(Page->PageDock.Handle, 6, 100, 100, 20, "Show Dock", lv_color_hex3(0xFF0));
    Page->PageDock.SwitchShowDock = CreateSwitch(Page->PageDock.Handle, 200, 100, 200, 20, lv_color_hex3(0xFF0));
    Page->PageDock.LabelAutoHideDock = CreateLabel(Page->PageDock.Handle, 6, 140, 200, 20, "Auto Hide Dock", lv_color_hex3(0xFF0));
    Page->PageDock.SwitchAutoHideDock = CreateSwitch(Page->PageDock.Handle, 200, 140, 200, 20, lv_color_hex3(0xFF0));
}