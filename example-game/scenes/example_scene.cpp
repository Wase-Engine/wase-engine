#include "example_scene.h"

#include "../../core/renderer.h"
#include "../../core/utils/log_utils.h"

#include <SDL.h>

void ExampleScene::start()
{
	log_utils::info("The example scene is now loaded.");
}

void ExampleScene::render()
{
	SDL_SetRenderDrawColor(Renderer::getRenderer(), 21, 21, 21, 255);
}