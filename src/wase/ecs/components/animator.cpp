#include "animator.h"

namespace wase
{
	Animator::Animator(const unsigned int t_Frames, const unsigned int t_Speed) : m_Frames(t_Frames), m_Speed(t_Speed)
	{
	}

	void Animator::start()
	{
		m_SpriteRenderer = owner->getComponent<SpriteRenderer>();
	}

	void Animator::update(float dt)
	{
		rect.w = m_SpriteRenderer->rect.w;
		rect.h = m_SpriteRenderer->rect.h;

		m_Timer += dt;

		if (m_Timer > m_Speed)
		{
			m_CurrentFrame += 1;
			if (m_CurrentFrame >= m_Frames)
			{
				rect.x = 0;
				m_CurrentFrame = 0;
			}

			rect.x = rect.w * m_CurrentFrame;

			m_Timer = 0;
		}
	}
}