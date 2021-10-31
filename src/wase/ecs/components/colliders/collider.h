#pragma once

#include "../../component.h"
#include "../transform.h"

namespace wase
{
	class Collider : public Component
	{
	public:
		void start() override;
		bool onMouseHold(const int button);
		bool onMouseDown(const int button);
		bool onMouseUp(const int button);
		virtual bool onMouseEnter() = 0;
		virtual bool onMouseExit() = 0;

	protected:
		Transform* transform = nullptr;
		Transform* parentTransform = nullptr;

		bool mouseHover, entered, exited;

	protected:
		virtual ~Collider();
		Collider();
	};
}