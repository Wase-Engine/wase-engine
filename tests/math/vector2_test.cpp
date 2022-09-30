#include <cmath>

#include <gtest/gtest.h>

#include <math/vector2.h>

using namespace wase::math;

TEST(Vector2Test, Initialize)
{
	Vector2 vector(1.0f, 2.0f);

	EXPECT_EQ(vector.x, 1.0f);
	EXPECT_EQ(vector.y, 2.0f);
}

TEST(Vector2Test, Equality)
{
	Vector2 vector1(1.0f, 2.0f);
	Vector2 vector2(1.0f, 2.0f);

	EXPECT_TRUE(vector1 == vector2);
}

TEST(Vector2Test, Addition)
{
	Vector2 vector1(1.0f, 2.0f);
	Vector2 vector2(3.0f, 4.0f);

	Vector2 result = vector1 + vector2;

	EXPECT_EQ(result.x, 4.0f);
	EXPECT_EQ(result.y, 6.0f);
}

TEST(Vector2Test, Subtraction)
{
	Vector2 vector1(1.0f, 2.0f);
	Vector2 vector2(3.0f, 4.0f);

	Vector2 result = vector1 - vector2;

	EXPECT_EQ(result.x, -2.0f);
	EXPECT_EQ(result.y, -2.0f);
}

TEST(Vector2Test, ScalarMultiplication)
{
	Vector2 vector(1.0f, 2.0f);

	Vector2 result = vector * 2.0f;

	EXPECT_EQ(result.x, 2.0f);
	EXPECT_EQ(result.y, 4.0f);
}

TEST(Vector2Test, ScalarDivision)
{
	Vector2 vector(1.0f, 2.0f);

	Vector2 result = vector / 2.0f;

	EXPECT_EQ(result.x, 0.5f);
	EXPECT_EQ(result.y, 1.0f);
}

TEST(Vector2Test, Up)
{
	EXPECT_EQ(Vector2::up(), Vector2(0, 1));
}

TEST(Vector2Test, Right)
{
	EXPECT_EQ(Vector2::right(), Vector2(1, 0));
}

TEST(Vector2Test, Down)
{
	EXPECT_EQ(Vector2::down(), Vector2(0, -1));
}

TEST(Vector2Test, Left)
{
	EXPECT_EQ(Vector2::left(), Vector2(-1, 0));
}

TEST(Vector2Test, One)
{
	EXPECT_EQ(Vector2::one(), Vector2(1, 1));
}

TEST(Vector2Test, Zero)
{
	EXPECT_EQ(Vector2::zero(), Vector2(0, 0));
}

TEST(Vector2Test, GetMagnitude)
{
	Vector2 vector(1.0f, 2.0f);
	
	EXPECT_EQ(vector.getMagnitude(), std::sqrt(5.0f));
}

TEST(Vector2Test, GetSqrMagnitude)
{
	Vector2 vector(1.0f, 2.0f);

	EXPECT_EQ(vector.getSqrMagnitude(), 5.0);
}

TEST(Vector2Test, GetNormalized)
{
	Vector2 vector(1.0f, 2.0f);

	Vector2 result = vector.getNormalized();

	EXPECT_EQ(result.x, 1.0f / std::sqrt(5.0f));
	EXPECT_EQ(result.y, 2.0f / std::sqrt(5.0f));
}

TEST(Vector2Test, Distance)
{
	Vector2 vector1(1.0f, 2.0f);
	Vector2 vector2(3.0f, 4.0f);

	EXPECT_EQ(Vector2::distance(vector1, vector2), std::sqrt(8.0f));
}

TEST(Vector2Test, Dot)
{
	Vector2 vector1(1.0f, 2.0f);
	Vector2 vector2(3.0f, 4.0f);

	EXPECT_EQ(Vector2::dot(vector1, vector2), 11.0f);
}