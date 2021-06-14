#pragma once

#include "../../core/renderer.h"
#include "../../core/utils/log_utils.h"
#include "../../core/managers/resource_manager.h"
#include "../component.h"
#include "transform.h"

#include <SDL.h>
#include <SDL_image.h>
#include <memory>
#include <string>

class SpriteRenderer : public Component
{
private:
	Transform* transform;
	SDL_Texture* texture;
	SDL_Rect rect {};
	int sizeX, sizeY;

public:
	SpriteRenderer(const std::string& name, const int sizeX, const int sizeY)
	{
		this->sizeX = sizeX;
		this->sizeY = sizeY;

		texture = ResourceManager::getTexture(name);
	}

	void start()
	{
		transform = owner->getComponent<Transform>();
	}

	void update(float dt)
	{
		rect.x = (int)transform->x;
		rect.y = (int)transform->y;
		rect.w = (int)(sizeX * transform->scaleX);
		rect.h = (int)(sizeY * transform->scaleY);
	}

	void render()
	{
		SDL_RenderCopy(Renderer::getRenderer(), texture, NULL, &rect);
	}
};