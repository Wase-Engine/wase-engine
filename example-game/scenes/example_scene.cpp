#include "example_scene.h"

#include "../../core/renderer.h"
#include "../../core/input.h"
#include "../../core/utils/log_utils.h"
#include "../../ecs/entity.h"
#include "../../ecs/components/transform.h"
#include "../../ecs/components/sprite_renderer.h"
#include "../../ecs/components/audio_source.h"

#include <SDL.h>

// Entities
Entity* cube;

// Components
Transform* transform;
AudioSource* audioSource;

void ExampleScene::start()
{
	cube = entityManager.addEntity("Cube");
	cube->addComponent<SpriteRenderer>("cube", 32, 32);
	cube->addComponent<AudioSource>("hop", 35);
	
	transform = cube->getComponent<Transform>();
	audioSource = cube->getComponent<AudioSource>();

	log_utils::info("The example scene is now loaded.");
}

void ExampleScene::update(float dt)
{
	if (input::getKeyDown(SDLK_RIGHT))
	{
		transform->x += 25;
		audioSource->play();
	}

	if (input::getKeyDown(SDLK_LEFT))
	{
		transform->x -= 25;
		audioSource->play();
	}

	if (input::getKeyDown(SDLK_DOWN))
	{
		transform->y += 25;
		audioSource->play();
	}

	if (input::getKeyDown(SDLK_UP))
	{
		transform->y -= 25;
		audioSource->play();
	}
}