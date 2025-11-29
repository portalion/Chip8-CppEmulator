#include "BaseApp.h"


BaseApp::BaseApp(int width, int height, const std::string& windowTitle )
	: window{ width, height, windowTitle },
	running{ true }
{
	InitImgui(window.GetWindowPointer());
	ImGui::StyleColorsDark();
	window.SetAppPointerData(this);

	HandleResize();
}

BaseApp::~BaseApp()
{
	ImGui_ImplOpenGL3_Shutdown();
	ImGui_ImplGlfw_Shutdown();
	ImGui::DestroyContext();
	glfwTerminate();
}


void BaseApp::Run()
{
	while (running && !window.ShouldClose())
	{
		ImGui_ImplOpenGL3_NewFrame();
		ImGui_ImplGlfw_NewFrame();
		ImGui::NewFrame();
#ifdef _DEBUG
		ImGui::ShowDemoWindow();
#endif 
		ProcessFrame();

		ImGui::Render();
		ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
		window.ProcessFrame();
	}
}

void BaseApp::HandleResize()
{
	width = window.GetWidth();
	height = window.GetHeight();
}
