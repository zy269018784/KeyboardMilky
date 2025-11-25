#pragma once
#include "Pages/SettingPage/TimeSettingPage/TimeSettingPage.h"
#include "Pages/SettingPage/DockSettingPage/DockSettingPage.h"
#include "Pages/SettingPage/OtherSettingPage/OtherSettingPage.h"
#ifdef __cplusplus
extern "C"
{
#endif
	void InitBuffer();
	void FreeBuffer();
	void SetTemp(int v);
	void SetMemoryUsage(int v);
	void SetCPUFreq(int v);
	void SetUploadSpeed(int v);
	void SetDownloadSpeed(int v);

	void ResetTimeSettingPage(SettingsClockPage* Page);
	void ResetDockSettingPage(SettingsDockPage* Page);
	void ResetOtherSettingPage(SettingsOtherPage* Page);
#ifdef __cplusplus
}
#endif