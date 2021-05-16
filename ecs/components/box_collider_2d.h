#pragma once

#include "../component.h"

#include "../../core/renderer.h"
#include "../../core/debug_draw.h"
#include "../../ecs/components/transform.h"

#include <SDL.h>

class BoxCollider2D : public Component
{
public:
	float width, height;
	float offsetX = 0, offsetY = 0;
	bool showCollider = false;

private:
	float x, y;

	SDL_Rect rectToDraw;
	Transform* transform;

public:
	BoxCollider2D(const float width, const float height)
	{
		this->width = width;
		this->height = height;
	}

	void init()
	{
		transform = owner->getComponent<Transform>();
	}

	void update(float dt)
	{
		this->x = owner->getComponent<Transform>()->x;
		this->y = owner->getComponent<Transform>()->y;

		rectToDraw = { (int)x + (int)offsetX, (int)y + (int)offsetY, (int)width, (int)height };
	}

	void render()
	{
		if (showCollider)
		{
			DebugDraw::rectangle(rectToDraw, 0, 255, 0, 255);
		}
	}
};