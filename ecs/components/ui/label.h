#pragma once

#include "../../component.h"
#include "../transform.h"

#include <SDL.h>

class Label : public Component
{
public:
	Label(const char* text, const char* font, SDL_Color& color);
	void init();
	void update(float dt);
	void render();
	void setText(const char* text);
	void setFont(const char* font);
	void setColor(SDL_Color& color);

private:
	Transform* transform;

	const char* text;
	const char* font;
	SDL_Rect position;
	SDL_Color color;
	SDL_Texture* texture;

private:
	void updateText();
};