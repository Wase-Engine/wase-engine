#include <rendering/vertex_buffer_layout.h>

#include <debugging/log.h>

namespace wase::rendering
{
	std::vector<VertexBufferElement> VertexBufferLayout::getElements() const
	{
		return m_Elements;
	}

	unsigned int VertexBufferLayout::getStride() const
	{
		return m_Stride;
	}

	void VertexBufferLayout::pushFloat(const unsigned int count)
	{
		VertexBufferElement e{ GL_FLOAT, count, GL_FALSE };

		m_Elements.push_back(e);
		m_Stride += count * VertexBufferElement::getSizeOfType(GL_FLOAT);
	}

	void VertexBufferLayout::pushUInt(const unsigned int count)
	{
		VertexBufferElement e{ GL_UNSIGNED_INT, count, GL_FALSE };

		m_Elements.push_back(e);
		m_Stride += count * VertexBufferElement::getSizeOfType(GL_UNSIGNED_INT);
	}

	void VertexBufferLayout::pushUChar(const unsigned int count)
	{
		VertexBufferElement e{ GL_UNSIGNED_BYTE, count, GL_TRUE };

		m_Elements.push_back(e);
		m_Stride += count * VertexBufferElement::getSizeOfType(GL_UNSIGNED_BYTE);
	}

	unsigned int VertexBufferElement::getSizeOfType(unsigned int type)
	{
		switch (type)
		{
		case GL_FLOAT: return sizeof(float);
		case GL_UNSIGNED_INT: return sizeof(unsigned int);
		case GL_UNSIGNED_BYTE: return sizeof(unsigned char);
		}

		WASE_CORE_WARN("Passed an invalid type to VertexBufferElement::getSizeOfType");

		return 0;
	}
}