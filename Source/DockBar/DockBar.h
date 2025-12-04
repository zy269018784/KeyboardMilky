#pragma once
#include <lvgl/lvgl.h>
#include "Theme/Theme.h"
#include "Point2.h"
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

    lv_obj_t* IConHomePage;
    lv_obj_t* ButtonHomePage;
    lv_obj_t* LabelHomePage;
    Point2 ButtonHomePagePos;
    Point2 ButtonHomePageSize;
    const char *ButtonHomePageText;

    lv_obj_t* IConHomeMusic;
    lv_obj_t* ButtonMusic;
    lv_obj_t* LabelMusic;
    Point2 ButtonMusicPos;
    Point2 ButtonMusicSize;
    const char *ButtonMusicText;

    lv_obj_t* IConHomeClock;
    lv_obj_t* ButtonClock;
    lv_obj_t* LabelClock;
    Point2 ButtonClockPos;
    Point2 ButtonClockSize;
    const char *ButtonClockText;

    lv_obj_t* IConSystemInfo;
    lv_obj_t* ButtonSystemInfo;
    lv_obj_t* LabelSystemInfo;
    Point2 ButtonSystemInfoPos;
    Point2 ButtonSystemInfoSize;
    const char *ButtonSystemInfoText;

    lv_obj_t* IConSetting;
    lv_obj_t* ButtonSetting;
    lv_obj_t* LabelButtonSetting;
    Point2 ButtonSettingPos;
    Point2 ButtonSettingSize;
    const char *ButtonSettingText;

    lv_obj_t* IconCaps;
    lv_obj_t* ButtonCaps;
    Point2 ButtonCapsPos;
    Point2 ButtonCapsSize;
    const char *ButtonCapsText;

    lv_obj_t* IconVolumeMutex;
    lv_obj_t* ButtonVolumeMutex;
    Point2 ButtonVolumeMutexPos;
    Point2 ButtonVolumeMutexSize;
    const char *ButtonVolumeMutexText;
}DockBarTheme2;

void CreateDockBarTheme1(DockBar *Bar, lv_obj_t *Parent, Theme *CurrentTheme);
void CreateDockBarTheme2(DockBarTheme2 *Bar, lv_obj_t *Parent, Theme *CurrentTheme);
void CreateDockBarTheme3(DockBar *Bar, lv_obj_t *Parent, Theme *CurrentTheme);