#pragma once

#include "collider.h"

#include "../../../core/renderer.h"
#include "../../../core/vector2.h"
#include "../../../core/draw.h"
#include "../../../ecs/components/transform.h"

#include <SDL.h>

namespace wase
{
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

		bool isHovering() const;
		bool onMouseEnter() override;
		bool onMouseExit() override;

	private:
		Vector2 position;
		Vector2 mousePosition;
		Rectangle* rectangle = nullptr;

	private:
		void checkMouseHover();
	};
}