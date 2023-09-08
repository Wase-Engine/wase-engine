#include <gtest/gtest.h>

#include <resources/resource_pool.h>
#include <io/reading.h>

using namespace wase::resources;

TEST(ResourcePoolTest, LoadImage)
{
	ResourcePool pool;
	
	pool.loadImage("image", "assets/resources/image.png");
	pool.loadImage("image", "assets/resources/image.png");
	
	EXPECT_EQ(pool.count(), 1);
}

TEST(ResourcePoolTest, GetImage)
{
	ResourcePool pool;

	pool.loadImage("image", "assets/resources/image.png");

	EXPECT_NE(pool.getImage("image")->data, nullptr);
}