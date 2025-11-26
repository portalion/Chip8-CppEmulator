#pragma once
#include <string>
#include <unordered_set>
#include "Window.h"

class BaseApp
{
public:
	BaseApp(int width, int height);
	~BaseApp();

	void Run();
	virtual void HandleResize();
	virtual void ProcessFrame() = 0;
	
	Window window;
protected:
	bool running;
	int width;
	int height;
};