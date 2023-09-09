#include <GL/glew.h>

#include <rendering/vbo.h>

namespace wase::rendering
{
	VBO::VBO()
	{
		glGenBuffers(1, &m_ID);
	}

	void VBO::bind() const
	{
		glBindBuffer(GL_ARRAY_BUFFER, m_ID);
	}

	void VBO::unbind()
	{
		glBindBuffer(GL_ARRAY_BUFFER, 0);
	}

	void VBO::setData(const void* data, const unsigned int size) const
	{
		glBufferData(GL_ARRAY_BUFFER, size, data, GL_STATIC_DRAW);
	}
}