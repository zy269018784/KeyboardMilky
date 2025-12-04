#pragma once
#include <lvgl/lvgl.h>

typedef struct {
    lv_obj_t * Handle;

    lv_obj_t* ButtonHomePage;
    lv_obj_t* ButtonMusic;
    lv_obj_t* ButtonClock;
    lv_obj_t* ButtonSystemInfo;
    lv_obj_t* ButtonSetting;
}DockBar;

void CreateDockBarTheme1(DockBar *Bar, lv_obj_t *Parent);