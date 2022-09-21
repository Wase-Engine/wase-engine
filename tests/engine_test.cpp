#include <gtest/gtest.h>

#include <engine.h>

TEST(EngineTest, InitEngine)
{
	wase::Engine::get().initialize();
}

TEST(EngineTest, ShutdownEngine)
{
	wase::Engine::get().shutdown();
}