#include "ModelViewerApp.h"

ModelViewerApp::ModelViewerApp() {
	CreateNewWindow = NULL;
	TerminateProcess = false;
	NewHInst = 0;
}

ModelViewerApp::~ModelViewerApp() {
	if (CreateNewWindow)
		delete CreateNewWindow;
}

bool ModelViewerApp::MyRegisterClass(HINSTANCE hinst) {

}

ModelViewerApp* ModelViewerApp::CreateNewApp(HINSTANCE Hinst) {
	if (SetAppToOrigin) {
		SetAppToOrigin = new ModelViewerApp();
		SetAppToOrigin->NewHInst = Hinst;
		SetAppToOrigin->MyRegisterClass(Hinst);
		SetAppToOrigin->CreateAppNewWindow(1920, 1080);
	}
	return SetAppToOrigin;
}

void ModelViewerApp::DestroyApp() {
	if (SetAppToOrigin)
		delete SetAppToOrigin;
}

ModelViewerApp* ModelViewerApp::GetApp() {
	return SetAppToOrigin;
}

void ModelViewerApp::CreateAppNewWindow(int Width, int Height) {
	if (CreateNewWindow) {
		CreateNewWindow = new AppWindow();
}