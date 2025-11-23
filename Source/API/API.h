#pragma once

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
#ifdef __cplusplus
}
#endif