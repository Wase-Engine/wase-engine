#pragma once

#include <glm/glm.hpp>

#include <math/vector3.h>

namespace wase::rendering
{
	class OrthographicCamera
	{
	public:
		OrthographicCamera(const float left, const float right, const float bottom, const float top);

		/**
		 * Get the position of the camera
		 * 
		 * @return the position of the camera
		 */
		const math::Vector3& getPosition() const;

		/**
		 * Set the position of the camera
		 * 
		 * @param position: the new position of the camera
		 */
		void setPosition(const math::Vector3& position);

		/**
		 * Get the rotation of the camera
		 * 
		 * @return the rotation of the camera
		 */
		const float getRotation() const;

		/**
		 * Set the rotation of the camera
		 * 
		 * @param rotation: the new rotation of the camera
		 */
		void setRotation(const float rotation);

		/**
		 * Get the projection matrix of the camera
		 * 
		 * @return the projection matrix of the camera
		 */
		const glm::mat4& getProjectionMatrix() const;

		/**
		 * Get the view matrix of the camera
		 * 
		 * @return the view matrix of the camera
		 */
		const glm::mat4& getViewMatrix() const;

		/**
		 * Get the view projection matrix of the camera
		 * 
		 * @return the view projection matrix of the camera
		 */
		const glm::mat4& getViewProjectionMatrix() const;

	private:
		/**
		 * Recalculate the view matrix of the camera
		 */
		void recalculateViewMatrix();

		glm::mat4 m_ProjectionMatrix;
		glm::mat4 m_ViewMatrix;
		glm::mat4 m_ViewProjectionMatrix;

		math::Vector3 m_Position;
		float m_Rotation = 0.0f;
	};
}