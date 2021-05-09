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
public:
	int sizeX, sizeY;

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

	void init() override
	{
		transform = owner->getComponent<Transform>();
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

private:
	std::shared_ptr<Transform> transform;
	SDL_Texture* texture;
	SDL_Rect rect;
	const char* path;
};