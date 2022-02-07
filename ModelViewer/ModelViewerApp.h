#pragma once

#include <Windows.h>

class AppWindow;

class ModelViewerApp {
private:
	AppWindow* CreateNewWindow;
	bool TerminateProcess;
	static ModelViewerApp* SetAppToOrigin;

	ModelViewerApp();
	~ModelViewerApp();

	void CreateAppNewWindow(int Width, int Height);
	bool MyRegisterClass(HINSTANCE hinst);

public:
	HINSTANCE NewHInst;

	static ModelViewerApp* CreateNewApp(HINSTANCE Hinst);
	static void DestroyApp();
	static ModelViewerApp* GetApp();

	int RunApp();
	void KillAppProcess();

	AppWindow* GetWindow() { return CreateNewWindow; }

};