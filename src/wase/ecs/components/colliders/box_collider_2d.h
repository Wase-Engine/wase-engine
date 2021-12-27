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
		BoxCollider2D(const int t_Width, const int t_Height);

		void update(float dt) override;
		void render() override;

		bool isHovering() const;
		bool onMouseEnter() override;
		bool onMouseExit() override;

	private:
		Vector2 m_Position;
		Vector2 m_MousePosition;
		Rectangle* m_Rectangle = nullptr;

	private:
		void checkMouseHover();
	};
}