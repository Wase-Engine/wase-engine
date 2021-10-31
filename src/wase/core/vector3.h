#pragma once

struct Vector3
{
	float x = 0, y = 0, z = 0;

	Vector3();
	Vector3(const float x, const float y, const float z);

	Vector3 operator+=(const Vector3& other);
	Vector3 operator+(const Vector3& other);
	Vector3 operator-=(const Vector3& other);
	Vector3 operator-(const Vector3& other);

	float magnitude() const;
	static float dot(Vector3 lhs, Vector3 rhs);
	static Vector3 cross(Vector3 lhs, Vector3 rhs);
};