#include <gtest/gtest.h>

#include <time/time.h>

TEST(TimeTest, SetDeltaTime)
{
	wase::time::Time::setDeltaTime(0.5f);
	
	EXPECT_EQ(wase::time::Time::getDeltaTime(), 0.5f);
}

TEST(TimeTest, SetDeltaTimeSpike)
{
	wase::time::Time::setDeltaTime(0.5f);
	wase::time::Time::setDeltaTime(50.0f);

	EXPECT_EQ(wase::time::Time::getDeltaTime(), 0.5f);
}