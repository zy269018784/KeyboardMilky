#include "VolumeWidget.h"
#include "Widget.h"

void CreateVolumeWidget(VolumeWidget* Widget, lv_obj_t* Parent, int32_t x, int32_t y, int32_t w, int32_t h)
{
	Widget->Handle = CreateBase(Parent, x, y, w, h, lv_color_hex3(0x0FF));
	Widget->Volume = CreateBase(Widget->Handle, 10, 10, w - 20, (h - 20) / 2, lv_color_hex3(0x0F0));
}