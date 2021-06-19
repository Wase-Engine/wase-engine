#pragma once

#include "../../component.h"
#include "../transform.h"

class Collider : public Component
{
public:
	void start();
	virtual bool onMouseHold(const int button);
	virtual bool onMouseDown(const int button);
	virtual bool onMouseUp(const int button);
	virtual bool onMouseEnter() = 0;
	virtual bool onMouseExit() = 0;

protected:
	Transform* transform = nullptr;
	Transform* parentTransform = nullptr;

	bool mouseHover, entered, exited;

protected:
	Collider();
};