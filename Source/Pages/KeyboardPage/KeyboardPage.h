#pragma once
#include <lvgl/lvgl.h>
#include "Point2.h"
typedef struct
{
	lv_obj_t* Handle;

	lv_obj_t* ButtonKey[9];
	lv_obj_t* LabelKey[9];

}KeyboardPage;

#ifdef __cplusplus
extern "C"
{
#endif
	void CreateKeyboardPage(KeyboardPage* Page, lv_obj_t* Parent);
#ifdef __cplusplus
}
#endif