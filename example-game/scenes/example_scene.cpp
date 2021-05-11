#include "example_scene.h"

#include "../../core/renderer.h"
#include "../../core/input.h"
#include "../../core/utils/log_utils.h"
#include "../../ecs/entity.h"
#include "../../ecs/components/transform.h"
#include "../../ecs/components/sprite_renderer.h"
#include "../../ecs/components/audio_source.h"

#include <SDL.h>
#include <memory>

// Entities
std::shared_ptr<Entity> cube;

// Components
std::shared_ptr<Transform> transform;

void ExampleScene::start()
{
	cube = entityManager.addEntity("Cube");
	cube->addComponent<SpriteRenderer>("example-game/assets/sprites/cube.png", 32, 32);
	
	transform = cube->getComponent<Transform>();

	log_utils::info("The example scene is now loaded.");
}

void ExampleScene::update(float dt)
{
	if (input::getKeyDown(SDLK_RIGHT))
	{
		transform->x += 25;
	}

	if (input::getKeyDown(SDLK_LEFT))
	{
		transform->x -= 25;
	}

	if (input::getKeyDown(SDLK_DOWN))
	{
		transform->y += 25;
	}

	if (input::getKeyDown(SDLK_UP))
	{
		transform->y -= 25;
	}
}

void ExampleScene::render()
{
	SDL_SetRenderDrawColor(Renderer::getRenderer(), 21, 21, 21, 255);
}