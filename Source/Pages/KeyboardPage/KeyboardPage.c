#include "KeyboardPage.h"
#include "Widgets/Widget.h"
void CreateKeyboardPage(KeyboardPage* Page, lv_obj_t* Parent)
{
	Page->Handle = CreateBase(Parent, 0, 0, 480, 480, lv_color_hex3(0x00F));
}