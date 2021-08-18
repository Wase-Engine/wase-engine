#include "animator.h"

namespace wase
{
	Animator::Animator(const unsigned int frames, const unsigned int speed)
	{
		this->frames = frames;
		this->speed = speed;
	}

	void Animator::start()
	{
		spriteRenderer = owner->getComponent<SpriteRenderer>();
	}

	void Animator::update(float dt)
	{
		rect.w = spriteRenderer->rect.w;
		rect.h = spriteRenderer->rect.h;

		timer += dt;

		if (timer > speed)
		{
			currentFrame += 1;
			if (currentFrame >= frames)
			{
				rect.x = 0;
				currentFrame = 0;
			}

			rect.x = rect.w * currentFrame;

			timer = 0;
		}
	}
}