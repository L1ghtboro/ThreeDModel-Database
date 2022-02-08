#pragma once

class MouseTracker {
public:

	virtual bool MouseLeftUp(int CursorX, int CursorY) = 0;
	virtual bool MouseLeftDown(int CursorX, int CursorY) = 0;
	virtual bool MouseMovement(int CursorX, int CursorY) = 0;
};