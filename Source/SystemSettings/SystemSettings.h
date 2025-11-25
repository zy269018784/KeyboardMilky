#pragma once

typedef struct
{
	/*
		Clock设置
	*/
	bool AutoGetTime;
	bool HomePageShowTime;
	bool TimeFormat24;
	bool TimePosLeft;
	int  DateFormat;
	int  TimeZone;
	char Year[8];
	char Month[3];
	char Day[3];
	char Hour[3];
	char Minute[3];
	char Second[3];


	/*
		Dock设置
	*/
	bool ShowDock;
	bool AutoHideDock;

	/*
		其他设置
	*/
	bool AutoScreenOff;
	bool PogoPin;
	int ScreenOffTime;		// 单位分钟

}SystemSettings;