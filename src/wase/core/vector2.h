#pragma once

struct Vector2
{
	float x = 0, y = 0;

	Vector2 operator+(const Vector2& other)
	{
		Vector2 v;

		v.x = x + other.x;
		v.y = y + other.y;

		return v;
	}

	Vector2 operator-(const Vector2& other)
	{
		Vector2 v;

		v.x = x - other.x;
		v.y = y - other.y;

		return v;
	}
};