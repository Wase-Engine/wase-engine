#include "box_collider_2d.h"

#include "../../../core/input.h"

BoxCollider2D::BoxCollider2D(const int width, const int height)
{
	this->width = width;
	this->height = height;
}

void BoxCollider2D::update(float dt)
{
	if (owner->parent && !parentTransform)
		parentTransform = owner->parent->getComponent<Transform>();

	position.x = !parentTransform ? transform->position.x : transform->position.x + parentTransform->position.x;
	position.y = !parentTransform ? transform->position.y : transform->position.y + parentTransform->position.y;

	// Get the mouse position
	mousePosition.x = input::getMousePos().x;
	mousePosition.y = input::getMousePos().y;

	// If the component should show the collider outline set the position for the rectangle
	if (showCollider && rectangle)
	{
		rectangle->rect.x = (int)(position.x + offset.x);
		rectangle->rect.y = (int)(position.y + offset.y);
	}

	checkMouseHover();
}

void BoxCollider2D::render()
{
	// Create the rectangle if it hasn't been created yet
	if (showCollider && !rectangle)
	{
		rectangle = Draw::rectangle({ (int)position.x + (int)offset.x, (int)position.y + (int)offset.y, (int)width, (int)height }, 0, 255, 0, 255, false);
	}
}

bool BoxCollider2D::isHovering()
{
	return mouseHover;
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
	if (!(mousePosition.x < position.x + width && mousePosition.x > position.x))
	{
		entered = false;
		mouseHover = false;
		return;
	}

	if (!(mousePosition.y < position.y + height && mousePosition.y > position.y))
	{
		entered = false;
		mouseHover = false;
		return;
	}

	mouseHover = true;
	exited = false;
}
