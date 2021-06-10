#include "../core/engine.h"

#include "../core/managers/scene_manager.h"
#include "../core/managers/resource_manager.h"
#include "scenes/example_scene.h"

#include <memory>

int main(int argc, char* argv[])
{
	// Initialize SDL
	Engine::getInstance()->init("Example game", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 600, NULL);

	// Load resources
	ResourceManager::loadTexture("cube", "example-game/assets/sprites/cube.png");
	ResourceManager::loadAudio("hop", "example-game/assets/audio/hop.wav");

	// Load scenes
	SceneManager::addScene("example", std::make_shared<ExampleScene>());

	// Run the game
	Engine::getInstance()->run("example");

	return 0;
}