#include "HomePage.h"
#include "Widgets/Widget.h"
void CreateHomePage(HomePage* Page, lv_obj_t* Parent)
{
    /*---------------------------------------------------------------------*/
    Page->Parent = Parent;
    /*---------------------------------------------------------------------*/
    Page->Handle = CreateBase(Parent, 0, 0, LV_PCT(100), LV_PCT(100), lv_color_hex3(0x0F0));

    Page->CapsLock   = CreateButton(Parent, 350, 420, 50, 50, lv_color_hex3(0xFF0));

    Page->ImageMuted = CreateButton(Parent, 420, 420, 50, 50, lv_color_hex3(0xFF0));

    CreateVolumeWidget(&Page->Volume, Page->Handle, 400, 50, 60, 200);

    Page->LabelTime     = CreateLabel(Page->Handle, 400, 10,  80, 30, "13:30", lv_color_hex3(0x0F0));;
    Page->LabelWeekDay  = CreateLabel(Page->Handle, 400, 40, 80, 30, "FRIDAY", lv_color_hex3(0x0F0));;
}

void ShowMuted(HomePage* Page)
{
    lv_obj_clear_flag(Page->ImageMuted, LV_OBJ_FLAG_HIDDEN);
}

void HideMuted(HomePage* Page)
{
    lv_obj_add_flag(Page->ImageMuted, LV_OBJ_FLAG_HIDDEN);
}