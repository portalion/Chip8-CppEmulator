#pragma once
#include <string>
#include <unordered_set>
#include "Window.h"

enum class ClearMask
{
	ColorBufferBit = GL_COLOR_BUFFER_BIT,
	DepthBufferBit = GL_DEPTH_BUFFER_BIT
};

inline ClearMask operator|(ClearMask lhs, ClearMask rhs)
{
	return static_cast<ClearMask>(static_cast<unsigned int>(lhs) | static_cast<unsigned int>(rhs));
}

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

	void Clear(ClearMask toClear);

	virtual void HandleResize();
	virtual void ProcessFrame() = 0;

	friend Window;
};