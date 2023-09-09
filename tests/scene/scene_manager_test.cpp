#include <memory>

#include <gtest/gtest.h>

#include <system/configuration.h>
#include <scene/scene_manager.h>
#include <scene/scene_context.h>
#include <resources/resource_pool.h>

using namespace wase::scene;
using namespace wase::system;
using namespace wase::resources;

class TestScene : public Scene {};

TEST(SceneManagerTest, HasScene)
{
	SceneManager sceneManager;
	
	EXPECT_FALSE(sceneManager.hasScene("test"));

	std::unordered_map<std::string, std::function<std::shared_ptr<wase::scene::Scene>()>> scenes =
	{
		{"test", []() { return std::make_unique<TestScene>(); }}
	};

	Configuration config;
	config.scenes = scenes;
	config.startScene = "test";
	
	std::shared_ptr<SceneContext> context = std::make_shared<SceneContext>();
	context->resourcePool = std::make_shared<ResourcePool>();

	sceneManager.initialize(config, context);

	EXPECT_TRUE(sceneManager.hasScene("test"));
}