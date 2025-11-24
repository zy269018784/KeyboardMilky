#include "SystemInfoPage.h"
#include "Widgets/Widget.h"
void CreateSystemInfoPage(SystemInfoPage* Page, lv_obj_t* Parent)
{
    Page->Parent = Parent;
    /*---------------------------------------------------------------------*/
    Page->Handle = CreateBase(Parent, 0, 0, LV_PCT(100), LV_PCT(100), lv_color_hex3(0xF00));
    int Padding = 10;
    Page->Widget1_Width  = 480 - 2 * Padding;
    Page->Widget1_Height = 200;
    Page->Widget2_Width  = 280;
    Page->Widget2_Height = 200;
    Page->Widget3_Width  = Page->Widget1_Width - 10 - Page->Widget2_Width;
    Page->Widget3_Height = 200;

    Page->Widget1_X = Padding;
    Page->Widget1_Y = Padding;
    Page->Widget2_X = Padding;
    Page->Widget2_Y = Page->Widget1_Y + Page->Widget1_Height + Padding;
    Page->Widget3_X = Page->Widget2_X + Page->Widget2_Width  + Padding;
    Page->Widget3_Y = Page->Widget2_Y;

    Page->Widget1 = CreateBase(Page->Handle, Page->Widget1_X, Page->Widget1_Y, Page->Widget1_Width, Page->Widget1_Height, lv_color_hex3(0x000));
    Page->Widget2 = CreateBase(Page->Handle, Page->Widget2_X, Page->Widget3_Y, Page->Widget2_Width, Page->Widget2_Height, lv_color_hex3(0x000));
    Page->Widget3 = CreateBase(Page->Handle, Page->Widget3_X, Page->Widget3_Y, Page->Widget3_Width, Page->Widget3_Height, lv_color_hex3(0x000));
    CreateCPUInfoWidget(&Page->CPUInfo, Page->Widget1, 10, 0, 200, 200);

    CreateTempInfoWidget(&Page->TempInfo, Page->Widget1,   250, 10, 200, 60);
    CreateClockInfoWidget(&Page->ClockInfo, Page->Widget1, 250, 70, 200, 60);
    CreateNetworkInfoWidget(&Page->NetworkInfo, Page->Widget2, 0, 0,   Page->Widget2_Width, Page->Widget2_Height);
    CreateMemoryInfoWidget(&Page->MemoryInfo,   Page->Widget3, 0, 0,   Page->Widget3_Width, Page->Widget3_Height);
}
