#include "KeyboardPage.h"
#include "Widgets/Widget.h"
void CreateKeyboardPage(KeyboardPage* Page, lv_obj_t* Parent)
{
	Page->Handle = CreateBase(Parent, 0, 0, 480, 480, lv_color_hex3(0x00F));
	int w = 156, h = 156, padding = 3;
	Page->ButtonKey[0] = CreateButton(Page->Handle, 0 * (w + padding) + padding, 0 * (h + padding) + padding, w, h, lv_color_hex3(0x000));
	Page->ButtonKey[1] = CreateButton(Page->Handle, 1 * (w + padding) + padding, 0 * (h + padding) + padding, w, h, lv_color_hex3(0x000));
	Page->ButtonKey[2] = CreateButton(Page->Handle, 2 * (w + padding) + padding, 0 * (h + padding) + padding, w, h, lv_color_hex3(0x000));
	Page->ButtonKey[3] = CreateButton(Page->Handle, 0 * (w + padding) + padding, 1 * (h + padding) + padding, w, h, lv_color_hex3(0x000));
	Page->ButtonKey[4] = CreateButton(Page->Handle, 1 * (w + padding) + padding, 1 * (h + padding) + padding, w, h, lv_color_hex3(0x000));
	Page->ButtonKey[5] = CreateButton(Page->Handle, 2 * (w + padding) + padding, 1 * (h + padding) + padding, w, h, lv_color_hex3(0x000));
	Page->ButtonKey[6] = CreateButton(Page->Handle, 0 * (w + padding) + padding, 2 * (h + padding) + padding, w, h, lv_color_hex3(0x000));
	Page->ButtonKey[7] = CreateButton(Page->Handle, 1 * (w + padding) + padding, 2 * (h + padding) + padding, w, h, lv_color_hex3(0x000));
	Page->ButtonKey[8] = CreateButton(Page->Handle, 2 * (w + padding) + padding, 2 * (h + padding) + padding, w, h, lv_color_hex3(0x000));

	/*
		样式
	*/
	static lv_style_t style;
	lv_style_init(&style);
	lv_style_set_radius(&style, 5);

	/*Make a gradient*/
	lv_style_set_bg_opa(&style, LV_OPA_COVER);
	static lv_grad_dsc_t grad;
	grad.dir = LV_GRAD_DIR_VER;
	grad.stops_count = 2;
	grad.stops[0].color = lv_color_hex(0x171717);
	grad.stops[0].opa = LV_OPA_COVER;
	grad.stops[0].frac = 0;
	grad.stops[1].color = lv_color_hex(0x3d3d3d);
	grad.stops[1].opa = LV_OPA_COVER;
	grad.stops[1].frac = 192;

	lv_style_set_bg_grad(&style, &grad);

	Page->LabelKey[0] = CreateLabel(Page->ButtonKey[0], 0, 0, LV_PCT(100), LV_PCT(100), "Print", lv_color_hex3(0x0F0));
	lv_obj_set_style_bg_opa(Page->LabelKey[0], LV_OPA_COVER, 0);
	lv_obj_add_style(Page->LabelKey[0], &style, 0);

	Page->LabelKey[1] = CreateLabel(Page->ButtonKey[1], 0, 0, LV_PCT(100), LV_PCT(100), "Print", lv_color_hex3(0x0F0));
	lv_obj_set_style_bg_opa(Page->LabelKey[1], LV_OPA_COVER, 0);
	lv_obj_add_style(Page->LabelKey[1], &style, 0);

	Page->LabelKey[2] = CreateLabel(Page->ButtonKey[2], 0, 0, LV_PCT(100), LV_PCT(100), "Print", lv_color_hex3(0x0F0));
	lv_obj_set_style_bg_opa(Page->LabelKey[2], LV_OPA_COVER, 0);
	lv_obj_add_style(Page->LabelKey[2], &style, 0);

	Page->LabelKey[3] = CreateLabel(Page->ButtonKey[3], 0, 0, LV_PCT(100), LV_PCT(100), "Print", lv_color_hex3(0x0F0));
	lv_obj_set_style_bg_opa(Page->LabelKey[3], LV_OPA_COVER, 0);
	lv_obj_add_style(Page->LabelKey[3], &style, 0);

	Page->LabelKey[4] = CreateLabel(Page->ButtonKey[4], 0, 0, LV_PCT(100), LV_PCT(100), "Print", lv_color_hex3(0x0F0));
	lv_obj_set_style_bg_opa(Page->LabelKey[4], LV_OPA_COVER, 0);
	lv_obj_add_style(Page->LabelKey[4], &style, 0);

	Page->LabelKey[5] = CreateLabel(Page->ButtonKey[5], 0, 0, LV_PCT(100), LV_PCT(100), "Print", lv_color_hex3(0x0F0));
	lv_obj_set_style_bg_opa(Page->LabelKey[5], LV_OPA_COVER, 0);
	lv_obj_add_style(Page->LabelKey[5], &style, 0);

	Page->LabelKey[6] = CreateLabel(Page->ButtonKey[6], 0, 0, LV_PCT(100), LV_PCT(100), "Print", lv_color_hex3(0x0F0));
	lv_obj_set_style_bg_opa(Page->LabelKey[6], LV_OPA_COVER, 0);
	lv_obj_add_style(Page->LabelKey[6], &style, 0);

	Page->LabelKey[7] = CreateLabel(Page->ButtonKey[7], 0, 0, LV_PCT(100), LV_PCT(100), "Print", lv_color_hex3(0x0F0));
	lv_obj_set_style_bg_opa(Page->LabelKey[7], LV_OPA_COVER, 0);
	lv_obj_add_style(Page->LabelKey[7], &style, 0);

	Page->LabelKey[8] = CreateLabel(Page->ButtonKey[8], 0, 0, LV_PCT(100), LV_PCT(100), "Print", lv_color_hex3(0x0F0));
	lv_obj_set_style_bg_opa(Page->LabelKey[8], LV_OPA_COVER, 0);
	lv_obj_add_style(Page->LabelKey[8], &style, 0);
}