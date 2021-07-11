#pragma once

#include "../component.h"
#include "../components/sprite_renderer.h"

#include <SDL.h>

class Animator : public Component
{
public:
	SDL_Rect rect{};

public:
	Animator(unsigned int frames, unsigned int speed);

	void start();
	void update(float dt);

private:
	SpriteRenderer* spriteRenderer = nullptr;
	int frames = 0, speed = 100, currentFrame = 0;
	float timer = 0;
};