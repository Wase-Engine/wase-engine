#include "box_collider_2d.h"

#include "../../../core/input.h"

namespace wase
{
	BoxCollider2D::BoxCollider2D(const int t_Width, const int t_Height) : width(t_Width), height(t_Height)
	{
	}

	void BoxCollider2D::update(float dt)
	{
		if (owner->parent && !m_ParentTransform)
			m_ParentTransform = owner->parent->getComponent<Transform>();

		m_Position.x = !m_ParentTransform ? m_Transform->position.x : m_Transform->position.x + m_ParentTransform->position.x;
		m_Position.y = !m_ParentTransform ? m_Transform->position.y : m_Transform->position.y + m_ParentTransform->position.y;

		// Get the mouse position
		m_MousePosition.x = input::getMousePos().x;
		m_MousePosition.y = input::getMousePos().y;

		// If the component should show the collider outline set the position for the rectangle
		if (showCollider && m_Rectangle)
		{
			m_Rectangle->rect.x = (int)(m_Position.x + offset.x);
			m_Rectangle->rect.y = (int)(m_Position.y + offset.y);
		}

		checkMouseHover();
	}

	void BoxCollider2D::render()
	{
		// Create the rectangle if it hasn't been created yet
		if (showCollider && !m_Rectangle)
		{
			m_Rectangle = Draw::rectangle({ (int)m_Position.x + (int)offset.x, (int)m_Position.y + (int)offset.y, (int)width, (int)height }, 0, 255, 0, 255, false);
		}
	}

	bool BoxCollider2D::isHovering() const
	{
		return m_MouseHover;
	}

	bool BoxCollider2D::onMouseEnter()
	{
		if (m_Entered)
			return false;

		if (m_MouseHover)
			m_Entered = true;

		if (m_MouseHover)
			m_Entered = true;

		return m_MouseHover;
	}

	bool BoxCollider2D::onMouseExit()
	{
		if (m_Exited)
			return false;

		if (!m_MouseHover)
			m_Exited = true;

		return !m_MouseHover;
	}

	void BoxCollider2D::checkMouseHover()
	{
		if (!(m_MousePosition.x < m_Position.x + width && m_MousePosition.x > m_Position.x))
		{
			m_Entered = false;
			m_MouseHover = false;
			return;
		}

		if (!(m_MousePosition.y < m_Position.y + height && m_MousePosition.y > m_Position.y))
		{
			m_Entered = false;
			m_MouseHover = false;
			return;
		}

		m_MouseHover = true;
		m_Exited = false;
	}
}