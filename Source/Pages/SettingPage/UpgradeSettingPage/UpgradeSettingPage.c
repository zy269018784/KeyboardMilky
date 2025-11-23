#include "UpgradeSettingPage.h"
#include "../SettingsPage.h"
#include "Widgets/Widget.h"

void CreateSettingsUpdatePage(SettingsPage* Page)
{
    Page->PageUpdate.Handle = CreateBase(Page->Handle, 0, 0, LV_PCT(100), LV_PCT(100), lv_color_hex3(0x0F0));
    Page->PageUpdate.LabelCurrentVersion1 = CreateLabel(Page->PageUpdate.Handle, 0 + 10, 10, 200, 50, "Current Version", lv_color_hex3(0xF00));
    Page->PageUpdate.LabelCurrentVersion2 = CreateLabel(Page->PageUpdate.Handle, 200 + 10, 10, 200, 50, "v4.3.35", lv_color_hex3(0xF00));

    Page->PageUpdate.ButtonCheckNewVersion = CreateButton(Page->PageUpdate.Handle,   0 + 10, 60, 200, 50, lv_color_hex3(0xF00));
    Page->PageUpdate.LabelCheckNewVersion  = CreateLabel(Page->PageUpdate.ButtonCheckNewVersion, 0, 0, LV_PCT(100), LV_PCT(100), "Check New Version", lv_color_hex3(0xF00));
    Page->PageUpdate.LabelNewVersion       = CreateLabel(Page->PageUpdate.Handle, 200 + 10, 60, 200, 50, "v5.1.2", lv_color_hex3(0xF00));
}
