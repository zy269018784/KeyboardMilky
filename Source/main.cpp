#include "Application.h"

int main(int argc, char** argv)
{
	//lv_init();
	//auto Display = lv_windows_create_display(
	//	L"Milkyway Keyboard",
	//	480,
	//	480,
	//	100,
	//	false,
	//	true);

	//lv_obj_t* ActiveScreen = lv_screen_active();
	//lv_obj_set_style_pad_all(ActiveScreen, 0, 0);
	//lv_obj_set_style_border_width(ActiveScreen, 0, 0);
	//lv_obj_set_style_margin_all(ActiveScreen, 0, 0);

	//auto Window = lv_win_create(ActiveScreen);
	//lv_obj_set_size(Window, 480, 480);
	//lv_win_add_title(Window, "A title");
	//while (1)
	//{
	//	uint32_t time_till_next = lv_timer_handler();
	//	lv_delay_ms(time_till_next);
	//}
	//return 0;
	struct Application* App = CreateApplication();
	Run(App);
	return 0;
}