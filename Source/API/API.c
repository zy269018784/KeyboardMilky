#include "../Application.h"
#include <stdio.h>


static char* BufferTemp;
static char* BufferCPUFreq;
static char* BufferCPUUsage;
static char* BufferUploadSpeed;
static char* BufferDownSpeed;

void InitBuffer()
{
    BufferTemp          = (char*)malloc(128);
    BufferCPUFreq       = (char*)malloc(128);
    BufferCPUUsage      = (char*)malloc(128);
    BufferUploadSpeed   = (char*)malloc(128);
    BufferDownSpeed     = (char*)malloc(128);
}

void FreeBuffer()
{
    free(BufferTemp);
    free(BufferCPUFreq);
    free(BufferCPUUsage);
    free(BufferUploadSpeed);
    free(BufferDownSpeed);
}

void SetTemp(int v)
{
    if (0 <= v && v < 10000)
    {
        snprintf(BufferTemp, 4, "%d\0", v);
        lv_label_set_text_static(App->PageSystemInfo.TempInfo.Temp1, BufferTemp);
    }
}

void SetMemoryUsage(int v)
{
    float p = 1.0f * v / 100;
    int n = p * 14;
    if (0 <= v && v <= 100)
    {   
        for (int i = 0; i < 14; i++)
            lv_obj_set_style_bg_color(App->PageSystemInfo.MemoryInfo.Progress[i], lv_color_hex(0x3F3F3F), 0);

        for (int i = 0; i < n; i++)
            lv_obj_set_style_bg_color(App->PageSystemInfo.MemoryInfo.Progress[i], lv_color_hex3(0xFFF), 0);
    }
}

void SetCPUFreq(int v)
{
    if (0 <= v && v < 100000)
    {
        snprintf(BufferCPUFreq, 10, "%d MHz\0", v);
        lv_label_set_text_static(App->PageSystemInfo.ClockInfo.Temp1, BufferCPUFreq);
    }
}

void SetCPUUsage(int v)
{
    if (0 <= v && v < 100000)
    {
        snprintf(BufferCPUUsage, 10, "%d MHz\0", v);
        //lv_label_set_text_static(App->PageSystemInfo.ClockInfo.Temp1, BufferCPUUsage);
    }
}

void SetUploadSpeed(int v)
{
    if (0 <= v && v < 100000)
    {
        snprintf(BufferUploadSpeed, 10, "%d KB/s\0", v);
        lv_label_set_text_static(App->PageSystemInfo.NetworkInfo.Widget[5], BufferUploadSpeed);
    }
}

void SetDownloadSpeed(int v)
{
    if (0 <= v && v < 100000)
    {
        snprintf(BufferDownSpeed, 10, "%d KB/s\0", v);
        lv_label_set_text_static(App->PageSystemInfo.NetworkInfo.Widget[6], BufferDownSpeed);
    }
}