#pragma once

namespace wase::math
{
	struct Vector2
	{
		float x = 0;
		float y = 0;

		Vector2();
		Vector2(const float x, const float y);

		bool operator==(const Vector2& other) const;
		Vector2 operator+(const Vector2& other) const;
		Vector2 operator-(const Vector2& other) const;
		Vector2 operator*(const float scalar) const;
		Vector2 operator/(const float scalar) const;

		/**
		 * @return vector(0, 1)
		 */
		static Vector2 up();

		/**
		 * @return vector(1, 0)
		 */
		static Vector2 right();
		
		/**
		 * @return vector(0, -1)
		 */
		static Vector2 down();

		/**
		 * @return vector(-1, 0)
		 */
		static Vector2 left();

		/**
		 * @return vector(1, 1)
		 */
		static Vector2 one();

		/**
		 * @return vector(0, 0)
		 */
		static Vector2 zero();

		/**
		 * Get the distance between 2 vectors
		 * 
		 * @param a: the first vector
		 * @param b: the second vector
		 * 
		 * @return the distance between the 2 vectors
		 */
		static float distance(Vector2 vector1, Vector2 vector2);

		/**
		 * Get the dot product of 2 vectors
		 *
		 * @param a: the first vector
		 * @param b: the second vector
		 *
		 * @return the dot product of the 2 vectors
		 */
		static float dot(Vector2 vector1, Vector2 vector2);
		
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
		Vector2 getNormalized() const;
	};
}