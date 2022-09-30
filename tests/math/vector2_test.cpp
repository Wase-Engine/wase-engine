#include <gtest/gtest.h>

#include <math/vector2.h>

TEST(Vector2Test, Initialize)
{
	wase::math::Vector2 vector(1.0f, 2.0f);

	EXPECT_EQ(vector.x, 1.0f);
	EXPECT_EQ(vector.y, 2.0f);
}