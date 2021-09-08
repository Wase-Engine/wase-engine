#include "vector3.h"

#include <cmath>

Vector3 Vector3::operator+=(const Vector3& other)
{
	x += other.x;
	y += other.y;
	z += other.z;

	return *this;
}

Vector3 Vector3::operator+(const Vector3& other)
{
	Vector3 v;

	v.x = x + other.x;
	v.y = y + other.y;
	v.z = z + other.z;

	return v;
}

Vector3 Vector3::operator-=(const Vector3& other)
{
	x -= other.x;
	y -= other.y;
	z -= other.z;

	return *this;
}

Vector3 Vector3::operator-(const Vector3& other)
{
	Vector3 v;

	v.x = x - other.x;
	v.y = y - other.y;
	v.z = z - other.z;
	
	return v;
}

float Vector3::magnitude()
{
	return (float)sqrt(pow(x, 2) + pow(y, 2) + pow(z, 2));
}

float Vector3::dot(Vector3 lhs, Vector3 rhs)
{
	return (float)(lhs.x * rhs.x) + (lhs.y * rhs.y) + (lhs.z * rhs.z);
}

Vector3 Vector3::cross(Vector3 lhs, Vector3 rhs)
{
	Vector3 v;

	v.x = (lhs.y * rhs.z) - (lhs.z * rhs.y);
	v.y = (lhs.z * rhs.x) - (lhs.x * rhs.z);
	v.z = (lhs.x * rhs.y) - (lhs.y * rhs.x);

	return v;
}