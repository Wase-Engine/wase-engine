#pragma once

#include "../../core/renderer.h"
#include "../../core/utils/log_utils.h"
#include "../../core/managers/resource_manager.h"
#include "../component.h"
#include "transform.h"
#include "../entity_manager.h"

#include <SDL.h>
#include <SDL_image.h>
#include <memory>
#include <string>

class SpriteRenderer : public Component
{
public:
	SDL_Color color = { 255, 255, 255 };

public:
	SpriteRenderer(const std::string& name, const int sizeX, const int sizeY);
	void start();
	void update(float dt);
	void render();

private:
	Transform* transform = nullptr;
	Transform* parentTransform = nullptr;
	SDL_Texture* texture = nullptr;
	Camera* camera = nullptr;
	SDL_Rect rect{};
	int sizeX, sizeY;
};