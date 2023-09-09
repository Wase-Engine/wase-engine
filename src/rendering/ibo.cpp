#include <GL/glew.h>

#include <rendering/ibo.h>

namespace wase::rendering
{

	IBO::IBO()
	{
		glGenBuffers(1, &m_ID);
	}

	void IBO::bind() const
	{
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_ID);
	}

	void IBO::unbind()
	{
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
	}

	void IBO::setData(const void* data, const unsigned int size)
	{
		glBufferData(GL_ELEMENT_ARRAY_BUFFER, size, data, GL_STATIC_DRAW);
	}
}