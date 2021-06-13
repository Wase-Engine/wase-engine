#include "box_collider_2d.h"

#include "../../../core/input.h"

BoxCollider2D::BoxCollider2D(const int width, const int height)
{
	this->width = width;
	this->height = height;
}

void BoxCollider2D::update(float dt)
{
	this->x = transform->x;
	this->y = transform->y;

	mouseX = input::getMousePos().x;
	mouseY = input::getMousePos().y;

	rectToDraw = { (int)x + (int)offsetX, (int)y + (int)offsetY, (int)width, (int)height };

	checkMouseHover();
}

void BoxCollider2D::render()
{
	if (showCollider)
	{
		Draw::rectangle(rectToDraw, 0, 255, 0, 255, false);
	}
}

bool BoxCollider2D::onMouseEnter()
{
	if (entered)
		return false;

	if (mouseHover)
		entered = true;

	return mouseHover;
}

bool BoxCollider2D::onMouseExit()
{
	if (exited)
		return false;

	if (!mouseHover)
		exited = true;

	return !mouseHover;
}

void BoxCollider2D::checkMouseHover()
{
	if (!(mouseX < transform->x + width && mouseX > transform->x))
	{
		entered = false;
		mouseHover = false;
		return;
	}

	if (!(mouseY < transform->y + height && mouseY > transform->y))
	{
		entered = false;
		mouseHover = false;
		return;
	}

	mouseHover = true;
	exited = false;
}
