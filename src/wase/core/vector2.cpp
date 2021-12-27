#include "vector2.h"

Vector2::Vector2()
{
}

Vector2::Vector2(const float t_X, const float t_Y) : x(t_X), y(t_Y)
{
}

Vector2 Vector2::operator+=(const Vector2& other)
{
	x += other.x;
	y += other.y;

	return *this;
}

Vector2 Vector2::operator+(const Vector2& other)
{
	Vector2 v;

	v.x = x + other.x;
	v.y = y + other.y;

	return v;
}

Vector2 Vector2::operator-=(const Vector2& other)
{
	x -= other.x;
	y -= other.y;

	return *this;
}

Vector2 Vector2::operator-(const Vector2& other)
{
	Vector2 v;

	v.x = x - other.x;
	v.y = y - other.y;

	return v;
}

float Vector2::magnitude() const
{
	return (float)sqrt(pow(x, 2) + pow(y, 2));
}

float Vector2::dot(Vector2 lhs, Vector2 rhs)
{
	return (float)(lhs.x * rhs.x) + (lhs.y * rhs.y);
}