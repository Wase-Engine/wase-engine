#pragma once

#include <glm/glm.hpp>

namespace wase::math
{
	class Vector3
	{
	public:
		float x = 0;
		float y = 0;
		float z = 0;

		Vector3();
		Vector3(const float x, const float y, const float z);

		bool operator==(const Vector3& other) const;
		Vector3 operator+(const Vector3& other) const;
		Vector3 operator-(const Vector3& other) const;
		bool operator==(const glm::vec3& other) const;
		Vector3 operator+(const glm::vec3& other) const;
		Vector3 operator-(const glm::vec3& other) const;
		Vector3 operator*(const float scalar) const;
		Vector3 operator/(const float scalar) const;

		/**
		 * @return vector(0, 1, 0)
		 */
		static Vector3 up();

		/**
		 * @return vector(1, 0, 0)
		 */
		static Vector3 right();

		/**
		 * @return vector(0, -1, 0)
		 */
		static Vector3 down();

		/**
		 * @return vector(-1, 0, 0)
		 */
		static Vector3 left();

		/**
		 * @return vector(0, 0, 1)
		 */
		static Vector3 forward();

		/**
		 * @return vector(0, 0, -1)
		 */
		static Vector3 back();

		/**
		 * @return vector(1, 1, 1)
		 */
		static Vector3 one();

		/**
		 * @return vector(0, 0, 0)
		 */
		static Vector3 zero();

		/**
		 * Get the distance between 2 vectors
		 *
		 * @param a: the first vector
		 * @param b: the second vector
		 *
		 * @return the distance between the 2 vectors
		 */
		static float distance(Vector3 vector1, Vector3 vector2);

		/**
		 * Get the dot product of 2 vectors
		 *
		 * @param a: the first vector
		 * @param b: the second vector
		 *
		 * @return the dot product of the 2 vectors
		 */
		static float dot(Vector3 vector1, Vector3 vector2);

		/**
		 * Get the cross product of 2 vectors
		 *
		 * @param a: the first vector
		 * @param b: the second vector
		 *
		 * @return the cross product of the 2 vectors
		 */
		static Vector3 cross(Vector3 vector1, Vector3 vector2);

		/**
		 * Get the vector's magnitude
		 *
		 * @return the magnitude of the vector
		 */
		float getMagnitude() const;

		/**
		 * Get the vector's squared magnitude
		 *
		 * @return the squared magnitude of the vector
		 */
		float getSqrMagnitude() const;

		/**
		 * Get the normalized vector of this vector
		 *
		 * @return the normalized vector
		 */
		Vector3 getNormalized() const;

		/**
		 * Convert the vector to a glm vector
		 * 
		 * @return the glm vector
		 */
		glm::vec3 toGlmVec3() const;
	};
}