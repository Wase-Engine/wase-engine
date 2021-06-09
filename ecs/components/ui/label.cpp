#include "label.h"

#include "../../../core/managers/resource_manager.h"
#include "../../../core/renderer.h"

#include <SDL_ttf.h>

Label::Label(const char* text, const char* font, SDL_Color& color)
{
	this->text = text;
	this->font = font;
	this->color = color;
	updateText();
}

void Label::init()
{
	transform = owner->getComponent<Transform>();
}

void Label::update(float dt)
{
	position.x = (int)transform->x;
	position.y = (int)transform->y;
}

void Label::render()
{
	SDL_RenderCopy(Renderer::getRenderer(), texture, NULL, &position);
}

void Label::setText(const char* text)
{
	this->text = text;

	updateText();
}

void Label::setFont(const char* font)
{
	this->font = font;

	updateText();
}

void Label::setColor(SDL_Color& color)
{
	this->color = color;

	updateText();
}

void Label::updateText()
{
	SDL_Surface* surface = TTF_RenderText_Blended(ResourceManager::getFont(font), text, color);

	texture = SDL_CreateTextureFromSurface(Renderer::getRenderer(), surface);

	SDL_FreeSurface(surface);

	SDL_QueryTexture(texture, nullptr, nullptr, &position.w, &position.h);
}