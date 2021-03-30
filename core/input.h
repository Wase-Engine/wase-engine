#pragma once

#include "SDL.h"

namespace input 
{
	namespace events 
	{
		void keyDownEvent(int keyCode);
		void keyUpEvent(int keyCode);
		void mouseButtonDownEvent(int button);
		void mouseButtonUpEvent(int button);
	}

	bool keyPressed(int keyCode);
	bool keyDown(int keyCode);
	bool mouseButtonPressed(int button);
	bool mouseButtonDown(int button);
}