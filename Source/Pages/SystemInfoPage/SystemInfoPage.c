#include "SystemInfoPage.h"
#include "Widgets/Widget.h"
void CreateSystemInfoPage(SystemInfoPage* Page, lv_obj_t* Parent)
{
    Page->Parent = Parent;
    /*---------------------------------------------------------------------*/
    Page->Handle = CreateBase(Parent, 0, 0, LV_PCT(100), LV_PCT(100), lv_color_hex3(0xF00));
    /*---------------------------------------------------------------------*/
    /*
        label
    */
    Page->CPUUsage      = CreateLabel(Page->Handle,  10, 10, 150, 50, "CPUUsage", lv_color_hex3(0x00F));
    Page->CPUUsage_2    = CreateLabel(Page->Handle, 200, 10, 150, 50, "78%", lv_color_hex3(0x00F));
    Page->CPUTemp       = CreateLabel(Page->Handle,  10, 60, 150, 50, "Temp", lv_color_hex3(0x00F));
    Page->CPUTemp_2     = CreateLabel(Page->Handle, 200, 60, 150, 50, "50", lv_color_hex3(0x00F));
    Page->CPUFreq       = CreateLabel(Page->Handle,  10, 110, 150, 50, "Freq", lv_color_hex3(0x00F));
    Page->CPUFreq_2     = CreateLabel(Page->Handle, 200, 110, 150, 50, "1GHz", lv_color_hex3(0x00F));
    Page->MemUsage      = CreateLabel(Page->Handle,  10, 160, 150, 50, "Mem Usage", lv_color_hex3(0x00F));
    Page->MemUsage_2    = CreateLabel(Page->Handle, 200, 160, 150, 50, "31%", lv_color_hex3(0x00F));
    Page->UpSpeed       = CreateLabel(Page->Handle,  10, 210, 150, 50, "UpSpeed", lv_color_hex3(0x00F));
    Page->UpSpeed_2     = CreateLabel(Page->Handle, 200, 210, 150, 50, "100MB", lv_color_hex3(0x00F));
    Page->DownSpeed     = CreateLabel(Page->Handle,  10,  260, 150, 50, "DownSpeed", lv_color_hex3(0x00F));
    Page->DownSpeed_2   = CreateLabel(Page->Handle, 200, 260, 150, 50, "200MB", lv_color_hex3(0x00F));
    /*---------------------------------------------------------------------*/
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

    Page->Widget1 = CreateBase(Page->Handle, Page->Widget1_X, Page->Widget1_Y,   Page->Widget1_Width, Page->Widget1_Height, lv_color_hex3(0x000));
    Page->Widget2 = CreateBase(Page->Handle, Page->Widget2_X, Page->Widget3_Y, Page->Widget2_Width, Page->Widget2_Height, lv_color_hex3(0x000));
    Page->Widget3 = CreateBase(Page->Handle, Page->Widget3_X, Page->Widget3_Y, Page->Widget3_Width, Page->Widget3_Height, lv_color_hex3(0x000));
    CreateCPUInfoWidget(&Page->CPUInfo, Page->Widget1, 10, 10, 60, 60);
    CreateTempInfoWidget(&Page->TempInfo, Page->Widget1,   250, 70, 200, 60);
    CreateClockInfoWidget(&Page->ClockInfo, Page->Widget1, 250, 10, 200, 60);
    CreateNetworkInfoWidget(&Page->NetworkInfo, Page->Widget2, 0, 0,   Page->Widget2_Width, Page->Widget2_Height);
    CreateMemoryInfoWidget(&Page->MemoryInfo,   Page->Widget3, 0, 0,   Page->Widget3_Width, Page->Widget3_Height);
}

