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
	if (mouseHover)
		return false;

	// Check if the mouse is in between the edges of the box
	if (!(mouseX < transform->x + width && mouseX > transform->x - width))
		return false;

	if (!(mouseY < transform->y + height && mouseY > transform->y - height))
		return false;

	mouseHover = true;

	return true;
}

bool BoxCollider2D::onMouseExit()
{
	if (!mouseHover)
		return false;

	// Check if the mouse is outside the box
	if (mouseX < transform->x + width &&
		mouseX > transform->x - width &&
		mouseY < transform->y + height &&
		mouseY > transform->y - height)
		return false;

	mouseHover = false;

	return true;
}