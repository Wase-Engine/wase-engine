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
		Animator(const unsigned int frames, const unsigned int speed);

		void start() override;
		void update(float dt) override;

	private:
		SpriteRenderer* spriteRenderer = nullptr;
		int frames = 0, speed = 100, currentFrame = 0;
		float timer = 0;
	};
}