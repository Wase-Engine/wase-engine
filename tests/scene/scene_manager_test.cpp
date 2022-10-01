#include <memory>

#include <gtest/gtest.h>

#include <scene/scene.h>
#include <scene/scene_manager.h>

using namespace wase::scene;

struct TestScene : public Scene {};

TEST(SceneManagerTest, HasScene)
{
	SceneManager sceneManager;
	TestScene scene;
	
	EXPECT_FALSE(sceneManager.hasScene("test"));

	sceneManager.addScene("test", std::make_shared<TestScene>(scene));

	EXPECT_TRUE(sceneManager.hasScene("test"));
}