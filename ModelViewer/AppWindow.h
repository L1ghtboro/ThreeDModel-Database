#pragma once

#include <Windows.h>
#include "AppUI.h"
#include "ModelViewerCube.h"
#include "ModelViewerRect.h"

class AppWindow {
private:
	HWND WindowObject;
	HDC DrawNewInstance;
	HGLRC RenderGLContext;
	RECT ClientRect;

	int Width;
	int Height;

	float RotateX = 0.f;
	float RotateY = 0.f;
	float RotateZ = 0.f;

protected:
	HGLRC ModelViewerContextCreate(HDC NewHdc);
	bool ModelViewerContextDestroy();
	void ModelViewerStatementInitialize();

public:
	AppWindow();
	AppWindow(HINSTANCE SendHInst, int WWidth, int WHeight);
	~AppWindow();

	bool InitWindow(HINSTANCE SendHInst, int WWidth, int WHeight);

	void MakeRenderThreeD();
	void MakeRendeUI();
	void MakeRender();

	void Resize(int WWidth, int WHeight);
	void SetVisible(bool isVisible);
	void DestroyAppWindow();

	bool MouseLeftDown(int CursorX, int CursorY);
	bool MouseLeftUp(int CursorX, int CursorY);
	bool MouseMovement(int CursorX, int CursorY);
};