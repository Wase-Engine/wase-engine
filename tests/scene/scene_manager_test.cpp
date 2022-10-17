#include <memory>

#include <gtest/gtest.h>

#include <system/configuration.h>
#include <scene/scene_manager.h>

using namespace wase::scene;

class TestScene : public Scene {};

TEST(SceneManagerTest, HasScene)
{
	SceneManager sceneManager;
	
	EXPECT_FALSE(sceneManager.hasScene("test"));

	std::unordered_map<std::string, std::shared_ptr<Scene>> scenes = 
	{
		{"test", std::make_shared<TestScene>()}
	};

	sceneManager.addScenes(scenes);

	EXPECT_TRUE(sceneManager.hasScene("test"));
}