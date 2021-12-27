#pragma once

#include "../component.h"
#include "../components/sprite_renderer.h"

#include <SDL.h>

namespace wase
{
	class Animator : public Component
	{
	public:
		SDL_Rect rect{};

	public:
		Animator(const unsigned int t_Frames, const unsigned int t_Speed);

		void start() override;
		void update(float dt) override;

	private:
		SpriteRenderer* m_SpriteRenderer = nullptr;
		int m_Frames = 0, m_Speed = 100, m_CurrentFrame = 0;
		float m_Timer = 0;
	};
}