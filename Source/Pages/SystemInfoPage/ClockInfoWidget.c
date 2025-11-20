#include "ClockInfoWidget.h"
#include "Widgets/Widget.h"
void CreateClockInfoWidget(ClockInfoWidget* Widget, lv_obj_t* Parent, int x, int y, int w, int h)
{
	Widget->Handle = CreateBase(Parent, x, y, w, h, lv_color_hex3(0x000));


	static lv_style_t style_label;
	lv_style_init(&style_label);
	lv_style_set_text_color(&style_label, lv_color_hex3(0xFFF));  // 

	Widget->Temp1 = CreateLabel(Widget->Handle, 0, 0, 50, h / 2, "42C", lv_color_hex3(0xF00));
	lv_obj_add_style(Widget->Temp1, &style_label, 0);

	Widget->Temp2 = CreateLabel(Widget->Handle, 60, 0, 150, h / 2, "Temperature", lv_color_hex3(0xF00));
	lv_obj_add_style(Widget->Temp2, &style_label, 0);

	Widget->Progress1 = CreateBase(Widget->Handle, 0, h / 2, w, h / 2,  lv_color_hex3(0x00F));
	Widget->Progress2 = CreateBase(Widget->Handle, 0, h / 2, w / 2, h / 2, lv_color_hex3(0xFFF));
}