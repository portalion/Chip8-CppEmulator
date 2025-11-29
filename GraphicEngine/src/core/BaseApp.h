#pragma once
#include <string>
#include <unordered_set>
#include "Window.h"

class BaseApp
{
public:
	BaseApp(int width, int height, const std::string& windowTitle);
	virtual ~BaseApp();

	void Run();
protected:
	bool running;
	int width;
	int height;

	Window window;

	virtual void HandleResize();
	virtual void ProcessFrame() = 0;

	friend Window;
};