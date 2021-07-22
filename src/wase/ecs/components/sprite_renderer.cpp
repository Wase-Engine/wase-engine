#include "sprite_renderer.h"

#include "animator.h"

namespace wase
{
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

		if (!owner->parent)
			parentTransform = nullptr;

		rect.x = parentTransform ? (int)(transform->position.x + parentTransform->position.x - camera->position.x) : (int)(transform->position.x - camera->position.x);
		rect.y = parentTransform ? (int)(transform->position.y + parentTransform->position.y - camera->position.y) : (int)(transform->position.y - camera->position.y);

		rect.w = (int)(sizeX);
		rect.h = (int)(sizeY);
	}

	void SpriteRenderer::render()
	{
		SDL_SetTextureColorMod(texture, color.r, color.g, color.b);

		if (owner->hasComponent<Animator>())
		{
			SDL_RenderCopy(Renderer::getRenderer(), texture, &owner->getComponent<Animator>()->rect, &rect);
		}
		else
		{
			SDL_RenderCopy(Renderer::getRenderer(), texture, NULL, &rect);
		}
	}
}