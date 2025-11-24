#include "ClockPage.h"
#include "Widgets/Widget.h"

void ClockTimeUpState(ClockPage* Page)
{
    lv_obj_add_flag(Page->Handle, LV_OBJ_FLAG_HIDDEN);
    lv_obj_clear_flag(Page->TimeUpPageHandle, LV_OBJ_FLAG_HIDDEN);
}

void ClockDefaultState(ClockPage* Page)
{
    lv_obj_add_flag(Page->TimeUpPageHandle, LV_OBJ_FLAG_HIDDEN);
    lv_obj_clear_flag(Page->Handle, LV_OBJ_FLAG_HIDDEN);
    /*
        隐藏开始按钮
        显示停止按钮
    */
    lv_obj_add_flag(Page->start_button, LV_OBJ_FLAG_HIDDEN);
    lv_obj_clear_flag(Page->stop_button, LV_OBJ_FLAG_HIDDEN);
}

void ClockStartState(ClockPage* Page)
{
    lv_obj_add_flag(Page->TimeUpPageHandle, LV_OBJ_FLAG_HIDDEN);
    lv_obj_clear_flag(Page->Handle, LV_OBJ_FLAG_HIDDEN);
    /*
        隐藏停止按钮
        显示开始按钮
    */
    lv_obj_add_flag(Page->stop_button, LV_OBJ_FLAG_HIDDEN);
    lv_obj_clear_flag(Page->start_button, LV_OBJ_FLAG_HIDDEN);
}
