#include "sprite_renderer.h"

SpriteRenderer::SpriteRenderer(const std::string& name, const int sizeX, const int sizeY)
{
	this->sizeX = sizeX;
	this->sizeY = sizeY;

	texture = ResourceManager::getTexture(name);
}

void SpriteRenderer::start()
{
	transform = owner->getComponent<Transform>();
	camera = &transform->owner->entityManager->camera;
}

void SpriteRenderer::update(float dt)
{
	if (owner->parent && !parentTransform)
		parentTransform = owner->parent->getComponent<Transform>();

	if (parentTransform)
	{
		rect.x = (int)(transform->position.x + parentTransform->position.x - camera->position.x);
		rect.y = (int)(transform->position.y + parentTransform->position.y - camera->position.y);
	}
	else
	{
		rect.x = (int)(transform->position.x - camera->position.x);
		rect.y = (int)(transform->position.y - camera->position.y);
	}
	rect.w = (int)(sizeX * transform->scale.x);
	rect.h = (int)(sizeY * transform->scale.y);
}

void SpriteRenderer::render()
{
	SDL_SetTextureColorMod(texture, color.r, color.g, color.b);
	SDL_RenderCopy(Renderer::getRenderer(), texture, NULL, &rect);
}