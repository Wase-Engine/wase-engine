#include <cmath>

#include <math/vector3.h>

namespace wase::math
{
	Vector3::Vector3()
	{

	}
	
	Vector3::Vector3(const float x, const float y, const float z)
		: x(x), y(y), z(z)
	{

	}

	bool Vector3::operator==(const Vector3& other) const
	{
		return x == other.x && y == other.y && z == other.z;
	}

	Vector3 Vector3::operator+(const Vector3& other) const
	{
		return Vector3(x + other.x, y + other.y, z + other.z);
	}

	Vector3 Vector3::operator-(const Vector3& other) const
	{
		return Vector3(x - other.x, y - other.y, z - other.z);
	}

	bool Vector3::operator==(const glm::vec3& other) const
	{
		return x == other.x && y == other.y && z == other.z;
	}

	Vector3 Vector3::operator+(const glm::vec3& other) const
	{
		return Vector3(x + other.x, y + other.y, z + other.z);
	}

	Vector3 Vector3::operator-(const glm::vec3& other) const
	{
		return Vector3(x - other.x, y - other.y, z - other.z);
	}

	Vector3 Vector3::operator*(const float scalar) const
	{
		return Vector3(x * scalar, y * scalar, z * scalar);
	}

	Vector3 Vector3::operator/(const float scalar) const
	{
		return Vector3(x / scalar, y / scalar, z / scalar);
	}

	Vector3 Vector3::up()
	{
		return Vector3(0.0f, 1.0f, 0.0f);
	}

	Vector3 Vector3::right()
	{
		return Vector3(1.0f, 0.0f, 0.0f);
	}

	Vector3 Vector3::down()
	{
		return Vector3(0.0f, -1.0f, 0.0f);
	}

	Vector3 Vector3::left()
	{
		return Vector3(-1.0f, 0.0f, 0.0f);
	}

	Vector3 Vector3::forward()
	{
		return Vector3(0.0f, 0.0f, 1.0f);
	}

	Vector3 Vector3::back()
	{
		return Vector3(0.0f, 0.0f, -1.0f);
	}

	Vector3 Vector3::one()
	{
		return Vector3(1.0f, 1.0f, 1.0f);
	}

	Vector3 Vector3::zero()
	{
		return Vector3(0.0f, 0.0f, 0.0f);
	}

	float Vector3::distance(Vector3 vector1, Vector3 vector2)
	{
		return (vector1 - vector2).getMagnitude();
	}

	float Vector3::dot(Vector3 vector1, Vector3 vector2)
	{
		return vector1.x * vector2.x + vector1.y * vector2.y + vector1.z * vector2.z;
	}

	Vector3 Vector3::cross(Vector3 vector1, Vector3 vector2)
	{
		return Vector3(
			vector1.y * vector2.z - vector1.z * vector2.y,
			vector1.z * vector2.x - vector1.x * vector2.z,
			vector1.x * vector2.y - vector1.y * vector2.x
		);
	}

	float Vector3::getMagnitude() const
	{
		return sqrt(x * x + y * y + z * z);
	}

	float Vector3::getSqrMagnitude() const
	{
		return x * x + y * y + z * z;
	}

	Vector3 Vector3::getNormalized() const
	{
		return *this / getMagnitude();
	}

	glm::vec3 Vector3::toGlmVec3() const
	{
		return glm::vec3(x, y, z);
	}
}