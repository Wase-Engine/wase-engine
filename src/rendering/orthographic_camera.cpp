#include <glm/gtc/matrix_transform.hpp>

#include <rendering/orthographic_camera.h>

namespace wase::rendering
{
	OrthographicCamera::OrthographicCamera(const float left, const float right, const float bottom, const float top)
		: m_ProjectionMatrix(glm::ortho(left, right, bottom, top, -1.0f, 1.0f)), m_ViewMatrix(1.0f)
	{
		m_ViewProjectionMatrix = m_ProjectionMatrix * m_ViewMatrix;
	}

	const math::Vector3& OrthographicCamera::getPosition() const
	{
		return m_Position;
	}

	void OrthographicCamera::setPosition(const math::Vector3& position)
	{
		m_Position = position;
		recalculateViewMatrix();
	}

	const float OrthographicCamera::getRotation() const
	{
		return m_Rotation;
	}

	void OrthographicCamera::setRotation(const float rotation)
	{
		m_Rotation = rotation;
		recalculateViewMatrix();
	}
	
	const glm::mat4& OrthographicCamera::getProjectionMatrix() const
	{
		return m_ProjectionMatrix;
	}

	const glm::mat4& OrthographicCamera::getViewMatrix() const
	{
		return m_ViewMatrix;
	}

	const glm::mat4& OrthographicCamera::getViewProjectionMatrix() const
	{
		return m_ViewProjectionMatrix;
	}

	void OrthographicCamera::recalculateViewMatrix()
	{
		m_ViewMatrix = glm::translate(glm::mat4(1.0f), glm::vec3(m_Position.x, m_Position.y, m_Position.z)) *
			glm::rotate(glm::mat4(1.0f), m_Rotation, glm::vec3(0, 0, 1));
		
		m_ViewProjectionMatrix = m_ProjectionMatrix * m_ViewMatrix;
	}
}