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

namespace wase
{
	class SpriteRenderer : public Component
	{
	public:
		SDL_Color color = { 255, 255, 255 };
		SDL_Rect rect{};

	public:
		SpriteRenderer(const std::string& name, const int sizeX, const int sizeY);
		void start() override;
		void update(float dt) override;
		void render() override;

	private:
		Transform* transform = nullptr;
		Transform* parentTransform = nullptr;
		SDL_Texture* texture = nullptr;
		Camera* camera = nullptr;
		int sizeX, sizeY;
	};
}