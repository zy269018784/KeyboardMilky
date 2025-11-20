#include "MemoryInfoWidget.h"
#include "Widgets/Widget.h"
void CreateMemoryInfoWidget(MemoryInfoWidget* Widget, lv_obj_t* Parent, int x, int y, int w, int h)
{
	Widget->Handle = CreateBase(Parent, x, y, w, h, lv_color_hex3(0x000));


	static lv_style_t style_label;
	lv_style_init(&style_label);
	lv_style_set_text_color(&style_label, lv_color_hex3(0xFFF));  // 

	Widget->Temp1 = CreateLabel(Widget->Handle, 10, 0, 50, 20, "50%", lv_color_hex3(0xF00));
	lv_obj_add_style(Widget->Temp1, &style_label, 0);

	Widget->Temp2 = CreateLabel(Widget->Handle, 10, 20, 150, 20, "Memory", lv_color_hex3(0xF00));
	lv_obj_add_style(Widget->Temp2, &style_label, 0);

	for (int i = 0; i < 14; i++)
		Widget->Progress[i] = CreateBase(Widget->Handle, 10, h - 10 - 10 * i, w - 20, 5, lv_color_hex3(0xFFF));
	for (int i = 7; i < 14; i++)
		lv_obj_set_style_bg_color(Widget->Progress[i], lv_color_hex(0x3F3F3F), 0);
}