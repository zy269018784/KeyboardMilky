#include "VolumeWidget.h"
#include "Widget.h"

void CreateVolumeWidget(VolumeWidget* Widget, lv_obj_t* Parent, int32_t x, int32_t y, int32_t w, int32_t h)
{
	Widget->Handle = CreateBase(Parent, x, y, w, h, lv_color_hex3(0x0FF));
}