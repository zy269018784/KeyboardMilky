#pragma once
#include <lvgl/lvgl.h>
#include "Theme/Theme.h"
typedef struct {
    lv_obj_t * Handle;

    lv_obj_t* ButtonHomePage;
    lv_obj_t* ButtonMusic;
    lv_obj_t* ButtonClock;
    lv_obj_t* ButtonSystemInfo;
    lv_obj_t* ButtonSetting;
}DockBar;

typedef struct {
    lv_obj_t * Handle;

    lv_obj_t* ButtonHomePage;
    lv_obj_t* ButtonMusic;
    lv_obj_t* ButtonClock;
    lv_obj_t* ButtonSystemInfo;
    lv_obj_t* ButtonSetting;
}DockBarTheme2;

void CreateDockBarTheme1(DockBar *Bar, lv_obj_t *Parent, Theme *CurrentTheme);
void CreateDockBarTheme2(DockBarTheme2 *Bar, lv_obj_t *Parent, Theme *CurrentTheme);
void CreateDockBarTheme3(DockBar *Bar, lv_obj_t *Parent, Theme *CurrentTheme);