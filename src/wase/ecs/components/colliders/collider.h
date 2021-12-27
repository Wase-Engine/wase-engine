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
		Transform* m_Transform = nullptr;
		Transform* m_ParentTransform = nullptr;

		bool m_MouseHover, m_Entered, m_Exited;

	protected:
		virtual ~Collider();
		Collider();
	};
}