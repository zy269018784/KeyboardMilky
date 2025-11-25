#include "CPUInfoWidget.h"
#include "Widgets/Widget.h"
void CreateCPUInfoWidget(CPUInfoWidget* Widget, lv_obj_t* Parent, int x, int y, int w, int h)
{
	Widget->Handle = CreateBase(Parent, x, y, w, h, lv_color_hex3(0x0F0));

	static lv_style_t style_label;
	lv_style_init(&style_label);
	lv_style_set_text_color(&style_label, lv_color_hex3(0xFFF));  

	Widget->ArchProgress = CreateArc(Widget->Handle, 10, 10, h - 20, h - 20, lv_color_hex3(0xF00), 0, 360);
	lv_obj_remove_style(Widget->ArchProgress, NULL, LV_PART_KNOB);


	Widget->LabelCPU = CreateLabel(Widget->ArchProgress,   75, 70, 50, 20, "CPU", lv_color_hex3(0xF00));
	lv_obj_add_style(Widget->LabelCPU, &style_label, 0);

	Widget->LabelUsage = CreateLabel(Widget->ArchProgress, 75, 90, 50, 20, "80%", lv_color_hex3(0xF00));
	lv_obj_add_style(Widget->LabelUsage, &style_label, 0);
}