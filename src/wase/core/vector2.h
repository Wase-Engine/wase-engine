#pragma once

#include <cmath>

struct Vector2
{
	float x = 0, y = 0;

	Vector2();
	Vector2(const float t_X, const float t_Y);

	Vector2 operator+=(const Vector2& other);
	Vector2 operator+(const Vector2& other);
	Vector2 operator-=(const Vector2& other);
	Vector2 operator-(const Vector2& other);

	float magnitude() const;
	static float dot(Vector2 lhs, Vector2 rhs);
};