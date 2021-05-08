#include "../core/engine.h"

#include "../core/scene_manager.h"
#include "scenes/example_scene.h"

int main()
{
	SceneManager::addScene("example", new ExampleScene());

	Engine::getInstance()->run("example");
}