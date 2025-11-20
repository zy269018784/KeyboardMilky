#include "NetworkInfoWidget.h"
#include "Widgets/Widget.h"
void CreateNetworkInfoWidget(NetworkInfoWidget* Widget, lv_obj_t* Parent, int x, int y, int w, int h)
{
	Widget->Handle = CreateBase(Parent, x, y, w, h, lv_color_hex3(0x000));


	static lv_style_t style_label;
	lv_style_init(&style_label);
	lv_style_set_text_color(&style_label, lv_color_hex3(0xFFF));  // 

	int Padding = 10;
	Widget->WidgetPos[0].x		=	Padding;
	Widget->WidgetPos[0].y		=	Padding;
	Widget->WidgetSize[0].x		=	w - 20;
	Widget->WidgetSize[0].y		=	20;

	Widget->WidgetPos[1].x		= Widget->WidgetPos[0].x;
	Widget->WidgetPos[1].y		= Widget->WidgetPos[0].y + Widget->WidgetSize[0].y;
	Widget->WidgetSize[1].x		= Widget->WidgetSize[0].x;
	Widget->WidgetSize[1].y		= Widget->WidgetSize[0].y;

	Widget->WidgetPos[2].x		= Widget->WidgetPos[0].x;
	Widget->WidgetPos[2].y		= Widget->WidgetPos[1].y + Widget->WidgetSize[1].y;
	Widget->WidgetSize[2].x		= Widget->WidgetSize[0].x;
	Widget->WidgetSize[2].y		= h - 2 * Padding - Widget->WidgetSize[0].y	- Widget->WidgetSize[1].y;

	Widget->WidgetPos[3].x		= 0;
	Widget->WidgetPos[3].y		= 0;
	Widget->WidgetSize[3].x		= Widget->WidgetSize[2].y / 2;
	Widget->WidgetSize[3].y		= Widget->WidgetSize[2].y / 2;

	Widget->WidgetPos[4].x		= Widget->WidgetPos[3].x;
	Widget->WidgetPos[4].y		= Widget->WidgetSize[3].y;
	Widget->WidgetSize[4].x		= Widget->WidgetSize[3].x;
	Widget->WidgetSize[4].y		= Widget->WidgetSize[3].y;

	Widget->WidgetPos[5].x		= Widget->WidgetPos[3].x + Widget->WidgetSize[3].x;
	Widget->WidgetPos[5].y		= 0;
	Widget->WidgetSize[5].x		= Widget->WidgetSize[2].x - Widget->WidgetSize[2].y / 2;
	Widget->WidgetSize[5].y		= Widget->WidgetSize[2].y / 2;

	Widget->WidgetPos[6].x		= Widget->WidgetPos[5].x;
	Widget->WidgetPos[6].y		= Widget->WidgetPos[5].y + Widget->WidgetSize[5].y;
	Widget->WidgetSize[6].x		= Widget->WidgetSize[5].x;
	Widget->WidgetSize[6].y		= Widget->WidgetSize[5].y;

	Widget->Widget[0] = CreateLabel(Widget->Handle, Widget->WidgetPos[0].x, Widget->WidgetPos[0].y, Widget->WidgetSize[0].x, Widget->WidgetSize[0].y, "Network", lv_color_hex3(0xF00));
	lv_obj_add_style(Widget->Widget[0], &style_label, 0);

	Widget->Widget[1] = CreateLabel(Widget->Handle, Widget->WidgetPos[1].x, Widget->WidgetPos[1].y, Widget->WidgetSize[1].x, Widget->WidgetSize[1].y, "UPLOAD & DOWNLOAD", lv_color_hex3(0xF00));
	lv_obj_add_style(Widget->Widget[1], &style_label, 0);

	Widget->Widget[2] = CreateBase(Parent, Widget->WidgetPos[2].x, Widget->WidgetPos[2].y, Widget->WidgetSize[2].x, Widget->WidgetSize[2].y, lv_color_hex3(0x000));
	lv_obj_set_style_border_width(Widget->Widget[2], 1, 0);
	lv_obj_set_style_border_color(Widget->Widget[2], lv_color_hex3(0xFFF), 0);

	Widget->Widget[3] = CreateBase(Widget->Widget[2], Widget->WidgetPos[3].x, Widget->WidgetPos[3].y, Widget->WidgetSize[3].x, Widget->WidgetSize[3].y, lv_color_hex3(0x00F));
	Widget->Widget[4] = CreateBase(Widget->Widget[2], Widget->WidgetPos[4].x, Widget->WidgetPos[4].y, Widget->WidgetSize[4].x, Widget->WidgetSize[4].y, lv_color_hex3(0x0F0));
	Widget->Widget[5] = CreateLabel(Widget->Widget[2], Widget->WidgetPos[5].x, Widget->WidgetPos[5].y, Widget->WidgetSize[5].x, Widget->WidgetSize[5].y, "80 KB/S", lv_color_hex3(0xF00));
	Widget->Widget[6] = CreateLabel(Widget->Widget[2], Widget->WidgetPos[6].x, Widget->WidgetPos[6].y, Widget->WidgetSize[6].x, Widget->WidgetSize[6].y, "102 KB/S", lv_color_hex3(0x0FF));


	lv_obj_add_style(Widget->Widget[5], &style_label, 0);
	lv_obj_add_style(Widget->Widget[6], &style_label, 0);

}