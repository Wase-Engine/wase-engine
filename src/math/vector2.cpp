#include <cmath>

#include <math/vector2.h>

namespace wase::math
{
	Vector2::Vector2(const float x, const float y)
		: x(x), y(y)
	{
		
	}
	
	bool Vector2::operator==(const Vector2& other) const
	{
		return x == other.x && y == other.y;
	}

	Vector2 Vector2::operator+(const Vector2& other) const
	{
		return Vector2(x + other.x, y + other.y);
	}

	Vector2 Vector2::operator-(const Vector2& other) const
	{
		return Vector2(x - other.x, y - other.y);
	}

	Vector2 Vector2::operator*(const float scalar) const
	{
		return Vector2(x * scalar, y * scalar);
	}

	Vector2 Vector2::operator/(const float scalar) const
	{
		return Vector2(x / scalar, y / scalar);
	}

	Vector2 Vector2::up()
	{
		return Vector2(0.0f, 1.0f);
	}

	Vector2 Vector2::right()
	{
		return Vector2(1.0f, 0.0f);
	}

	Vector2 Vector2::down()
	{
		return Vector2(0.0f, -1.0f);
	}

	Vector2 Vector2::left()
	{
		return Vector2(-1.0f, 0.0f);
	}

	Vector2 Vector2::one()
	{
		return Vector2(1.0f, 1.0f);
	}

	Vector2 Vector2::zero()
	{
		return Vector2(0.0f, 0.0f);
	}

	float Vector2::getMagnitude() const
	{
		return std::sqrt(x * x + y * y);
	}

	float Vector2::getSqrMagnitude() const
	{
		return x * x + y * y;
	}

	Vector2 Vector2::getNormalized() const
	{
		const float magnitude = getMagnitude();
		
		return Vector2(x / magnitude, y / magnitude);
	}

	float Vector2::distance(Vector2 vector1, Vector2 vector2)
	{
		return (vector2 - vector1).getMagnitude();
	}

	float Vector2::dot(Vector2 vector1, Vector2 vector2)
	{
		return vector1.x * vector2.x + vector1.y * vector2.y;
	}
}