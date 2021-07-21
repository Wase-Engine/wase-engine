#pragma once

#include "collider.h"

#include "../../../core/renderer.h"
#include "../../../core/vector2.h"
#include "../../../core/draw.h"
#include "../../../ecs/components/transform.h"

#include <SDL.h>

class BoxCollider2D : public Collider
{
public:
	int width, height;
	Vector2 offset;
	bool showCollider = false;

public:
	BoxCollider2D(const int width, const int height);

	void update(float dt) override;
	void render() override;

	bool isHovering();
	bool onMouseEnter();
	bool onMouseExit();

private:
	Vector2 position;
	Vector2 mousePosition;
	Rectangle* rectangle = nullptr;

	SDL_Rect rectToDraw;

private:
	void checkMouseHover();
};