#pragma once

#include "../../core/renderer.h"
#include "../../core/utils/log_utils.h"
#include "../component.h"
#include "transform.h"

#include <string>
#include <SDL.h>
#include <SDL_image.h>

class SpriteRenderer : public Component
{
private:
	Transform* transform;
	SDL_Texture* texture;
	SDL_Rect rect;
	const char* path;

public:
	int sizeX, sizeY;

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

	void init() override
	{
		transform = owner->getComponent<Transform>();
	}

	void events() override
	{

	}

	void update() override
	{
		rect.x = transform->x;
		rect.y = transform->y;
		rect.w = sizeX;
		rect.h = sizeY;
	}

	void render() override
	{
		SDL_RenderCopy(Renderer::getRenderer(), texture, NULL, &rect);
	}
};