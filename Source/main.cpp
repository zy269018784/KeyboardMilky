#include <iostream>
void LVGLDemos();
#include "Application.h"
int main(int argc, char** argv)
{
	LVGLDemos();
	return 0;

	struct Application* App = CreateApplication();
	Run(App);
	return 0;
}