#include "Application.h"
int main(int argc, char** argv)
{
	struct Application* App = CreateApplication();
	Run(App);
	return 0;
}