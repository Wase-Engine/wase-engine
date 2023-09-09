#include <GL/glew.h>

#include <rendering/vao.h>

namespace wase::rendering
{
	VAO::VAO()
	{
		glGenVertexArrays(1, &m_ID);
	}

	void VAO::bind() const
	{
		glBindVertexArray(m_ID);
	}

	void VAO::unbind() const
	{
		glBindVertexArray(0);
	}

	void VAO::addBuffer(const VBO* vbo, const VertexBufferLayout& vbl) const
	{
		vbo->bind();

		unsigned int offset = 0;

		for (unsigned int i = 0; i < vbl.getElements().size(); i++)
		{
			VertexBufferElement vbe = vbl.getElements()[i];

			glVertexAttribPointer(i, vbe.count, vbe.type, vbe.normalized, vbl.getStride(), (void*)static_cast<size_t>(offset));
			glEnableVertexAttribArray(i);

			offset += vbe.count * VertexBufferElement::getSizeOfType(vbe.type);
		}
	}
}