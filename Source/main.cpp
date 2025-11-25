#include "Application.h"
#include "API/API.h"
int main(int argc, char** argv)
{
	CreateApplication();
	InitBuffer();

	//SetTemp(123);
	//SetMemoryUsage(70);
	//SetCPUFreq(5522);
	//SetUploadSpeed(585);
	//SetDownloadSpeed(432);

	Run(App);
	FreeBuffer();
	return 0;
}