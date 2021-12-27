#pragma once

#include "../../component.h"
#include "../transform.h"
#include "../../entity_manager.h"
#include "../../../core/size.h"

#include <SDL.h>
#include <string>

namespace wase
{
class Label : public Component
{
	public:
		Label(const char* t_Text, const char* t_Font, const SDL_Color& t_Color);
		void start() override;
		void update(float dt) override;
		void render() override;
		void setText(const std::string& text);
		void setFont(const char* font);
		void setColor(SDL_Color& color);
		Size getSize() const;

	private:
		Camera* m_Camera = nullptr;
		Transform* m_Transform = nullptr;
		Transform* m_ParentTransform = nullptr;

		std::string m_Text;
		const char* m_Font = nullptr;
		SDL_Rect m_Position;
		SDL_Color m_Color;
		SDL_Texture* m_Texture = nullptr;

	private:
		void updateText();
	};
}