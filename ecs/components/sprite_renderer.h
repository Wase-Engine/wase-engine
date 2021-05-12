#pragma once

#include "../../core/renderer.h"
#include "../../core/utils/log_utils.h"
#include "../component.h"
#include "transform.h"

#include <SDL.h>
#include <SDL_image.h>
#include <memory>

class SpriteRenderer : public Component
{
private:
	Transform* transform;
	SDL_Texture* texture;
	SDL_Rect rect {};
	int sizeX, sizeY;
	const char* path;

public:
	SpriteRenderer(const char* path, const int sizeX, const int sizeY)
	{
		this->path = path;
		this->sizeX = sizeX;
		this->sizeY = sizeY;

		texture = IMG_LoadTexture(Renderer::getRenderer(), path);
		if (!texture)
		{
			log_utils::error(IMG_GetError());
			return;
		}
	}

	void init()
	{
		transform = owner->getComponent<Transform>();
	}

	void update(float dt)
	{
		rect.x = (int)transform->x;
		rect.y = (int)transform->y;
		rect.w = sizeX;
		rect.h = sizeY;
	}

	void render()
	{
		SDL_RenderCopy(Renderer::getRenderer(), texture, NULL, &rect);
	}
};