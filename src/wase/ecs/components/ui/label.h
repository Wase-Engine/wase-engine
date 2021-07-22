#pragma once

#include "../../component.h"
#include "../transform.h"
#include "../../entity_manager.h"

#include <SDL.h>
#include <string>

namespace wase
{
	struct Size
	{
		int w, h;
	};

	class Label : public Component
	{
	public:
		Label(const char* text, const char* font, const SDL_Color& color);
		void start() override;
		void update(float dt) override;
		void render() override;
		void setText(const std::string& text);
		void setFont(const char* font);
		void setColor(SDL_Color& color);
		Size getSize();

	private:
		Camera* camera = nullptr;
		Transform* transform = nullptr;
		Transform* parentTransform = nullptr;

		std::string text;
		const char* font = nullptr;
		SDL_Rect position;
		SDL_Color color;
		SDL_Texture* texture = nullptr;

	private:
		void updateText();
	};
}