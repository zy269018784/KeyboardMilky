#include "SystemSettings.h"

void ResetSystemSettings(SystemSettings* SS)
{
	/*
		其他设置
	*/
	SS->AutoScreenOff = true;
	SS->PogoPin = true;
	/*
		Dock设置
	*/
	SS->ShowDock		= true;
	SS->AutoHideDock	= false;

	/*
		时间设置
	*/
	SS->AutoGetTime = true;	
	SS->HomePageShowTime = true;
	SS->TimeFormat24 = true;
	SS->TimePosLeft = false;
	SS->TimeZone	= 0;
	SS->DateFormat	= 0;
}
