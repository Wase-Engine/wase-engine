#include <gtest/gtest.h>

#include <debugging/log_manager.h>

TEST(LogManagerTest, Init)
{
	wase::debugging::LogManager::initialize();
}

TEST(LogManagerTest, Shutdown)
{
	wase::debugging::LogManager::shutdown();
}