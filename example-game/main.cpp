#include "../core/engine.h"

#include "../core/scene_manager.h"
#include "scenes/example_scene.h"

#include <memory>

int main()
{
	SceneManager::addScene("example", std::make_shared<ExampleScene>());

	Engine::getInstance()->run("example");
}