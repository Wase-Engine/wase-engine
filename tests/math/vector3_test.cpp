#include <cmath>

#include <gtest/gtest.h>
#include <glm/glm.hpp>

#include <math/vector3.h>

using namespace wase::math;

TEST(Vector3Test, Initialize)
{
	Vector3 vector(1.0f, 2.0f, 3.0f);

	EXPECT_EQ(vector.x, 1.0f);
	EXPECT_EQ(vector.y, 2.0f);
	EXPECT_EQ(vector.z, 3.0f);
}

TEST(Vector3Test, Equality)
{
	Vector3 vector1(1.0f, 2.0f, 3.0f);
	Vector3 vector2(1.0f, 2.0f, 3.0f);

	EXPECT_TRUE(vector1 == vector2);
}

TEST(Vector3Test, Addition)
{
	Vector3 vector1(1.0f, 2.0f, 3.0f);
	Vector3 vector2(3.0f, 4.0f, 1.0f);

	Vector3 result = vector1 + vector2;

	EXPECT_EQ(result.x, 4.0f);
	EXPECT_EQ(result.y, 6.0f);
	EXPECT_EQ(result.z, 4.0f);
}

TEST(Vector3Test, Subtraction)
{
	Vector3 vector1(1.0f, 2.0f, 3.0f);
	Vector3 vector2(3.0f, 4.0f, 1.0f);

	Vector3 result = vector1 - vector2;

	EXPECT_EQ(result.x, -2.0f);
	EXPECT_EQ(result.y, -2.0f);
	EXPECT_EQ(result.z, 2.0f);
}

TEST(Vector3Test, EqualityGLM)
{
	Vector3 vector1(1.0f, 2.0f, 3.0f);
	glm::vec3 vector2(1.0f, 2.0f, 3.0f);

	EXPECT_TRUE(vector1 == vector2);
}

TEST(Vector3Test, AdditionGLM)
{
	Vector3 vector1(1.0f, 2.0f, 3.0f);
	glm::vec3 vector2(3.0f, 4.0f, 1.0f);

	Vector3 result = vector1 + vector2;

	EXPECT_EQ(result.x, 4.0f);
	EXPECT_EQ(result.y, 6.0f);
	EXPECT_EQ(result.z, 4.0f);
}

TEST(Vector3Test, SubtractionGLM)
{
	Vector3 vector1(1.0f, 2.0f, 3.0f);
	glm::vec3 vector2(3.0f, 4.0f, 1.0f);

	Vector3 result = vector1 - vector2;

	EXPECT_EQ(result.x, -2.0f);
	EXPECT_EQ(result.y, -2.0f);
	EXPECT_EQ(result.z, 2.0f);
}

TEST(Vector3Test, ScalarMultiplication)
{
	Vector3 vector(1.0f, 2.0f, 3.0f);

	Vector3 result = vector * 2.0f;

	EXPECT_EQ(result.x, 2.0f);
	EXPECT_EQ(result.y, 4.0f);
	EXPECT_EQ(result.z, 6.0f);
}

TEST(Vector3Test, ScalarDivision)
{
	Vector3 vector(1.0f, 2.0f, 3.0f);

	Vector3 result = vector / 2.0f;

	EXPECT_EQ(result.x, 0.5f);
	EXPECT_EQ(result.y, 1.0f);
	EXPECT_EQ(result.z, 1.5f);
}

TEST(Vector3Test, Up)
{
	EXPECT_EQ(Vector3::up(), Vector3(0, 1, 0));
}

TEST(Vector3Test, Right)
{
	EXPECT_EQ(Vector3::right(), Vector3(1, 0, 0));
}

TEST(Vector3Test, Down)
{
	EXPECT_EQ(Vector3::down(), Vector3(0, -1, 0));
}

TEST(Vector3Test, Left)
{
	EXPECT_EQ(Vector3::left(), Vector3(-1, 0, 0));
}

TEST(Vector3Test, Forward)
{
	EXPECT_EQ(Vector3::forward(), Vector3(0, 0, 1));
}

TEST(Vector3Test, Back)
{
	EXPECT_EQ(Vector3::back(), Vector3(0, 0, -1));
}

TEST(Vector3Test, One)
{
	EXPECT_EQ(Vector3::one(), Vector3(1, 1, 1));
}

TEST(Vector3Test, Zero)
{
	EXPECT_EQ(Vector3::zero(), Vector3(0, 0, 0));
}

TEST(Vector3Test, GetMagnitude)
{
	Vector3 vector(1.0f, 2.0f, 3.0f);
	
	EXPECT_EQ(vector.getMagnitude(), std::sqrt(14.0f));
}

TEST(Vector3Test, GetSqrMagnitude)
{
	Vector3 vector(1.0f, 2.0f, 3.0f);

	EXPECT_EQ(vector.getSqrMagnitude(), 14.0);
}

TEST(Vector3Test, GetNormalized)
{
	Vector3 vector(1.0f, 2.0f, 3.0f);

	Vector3 result = vector.getNormalized();

	EXPECT_EQ(result.x, 1.0f / std::sqrt(14.0f));
	EXPECT_EQ(result.y, 2.0f / std::sqrt(14.0f));
	EXPECT_EQ(result.z, 3.0f / std::sqrt(14.0f));
}

TEST(Vector3Test, Distance)
{
	Vector3 vector1(1.0f, 2.0f, 3.0f);
	Vector3 vector2(3.0f, 4.0f, 5.0f);

	EXPECT_EQ(Vector3::distance(vector1, vector2), std::sqrt(12.0f));
}

TEST(Vector3Test, Dot)
{
	Vector3 vector1(1.0f, 2.0f, 3.0f);
	Vector3 vector2(3.0f, 4.0f, 5.0f);

	EXPECT_EQ(Vector3::dot(vector1, vector2), 26.0f);
}

TEST(Vector3Test, Cross)
{
	Vector3 vector1(1.0f, 2.0f, 3.0f);
	Vector3 vector2(3.0f, 4.0f, 5.0f);

	Vector3 test1 = Vector3::cross(vector1, vector2);

	EXPECT_EQ(Vector3::cross(vector1, vector2), Vector3(-2.0f, 4.0f, -2.0f));
}

TEST(Vector3Test, ConvertToGlmVec)
{
	Vector3 vector1(1.0f, 2.0f, 3.0f);
	glm::vec3 vector2(1.0f, 2.0f, 3.0f);

	EXPECT_EQ(vector1.toGlmVec3(), vector2);
}