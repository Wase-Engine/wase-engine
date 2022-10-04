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