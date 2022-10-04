#pragma once

#include <vector>

#include <GL/glew.h>

namespace wase::rendering
{
	struct VertexBufferElement
	{
		unsigned int type;
		unsigned int count;
		unsigned char normalized;

		/**
		 * Get the size of the type in bytes
		 *
		 * @param type: the type to get the size of
		 * @return the size of the type in bytes
		 */
		static unsigned int getSizeOfType(unsigned int type);
	};

	class VertexBufferLayout
	{
	public:
		/**
		 * Get the elements of the layout
		 *
		 * @return a vector of elements of the layout
		 */
		std::vector<VertexBufferElement> getElements() const;

		/**
		 * Get the stride of the layout
		 *
		 * @return the stride of the layout
		 */
		unsigned int getStride() const;

		template<typename T>
		void push(const unsigned int count) = delete;

		/**
		 * Push a float to the layout
		 *
		 * @param count: the number of floats to push
		 */
		template<>
		void push<float>(const unsigned int count)
		{
			VertexBufferElement e{ GL_FLOAT, count, GL_FALSE };

			m_Elements.push_back(e);
			m_Stride += count * VertexBufferElement::getSizeOfType(GL_FLOAT);
		}

		/**
		 * Push an unsigned int to the layout
		 *
		 * @param count: the number of unsigned integers to push
		 */
		template<>
		void push<unsigned int>(const unsigned int count)
		{
			VertexBufferElement e{ GL_UNSIGNED_INT, count, GL_FALSE };

			m_Elements.push_back(e);
			m_Stride += count * VertexBufferElement::getSizeOfType(GL_UNSIGNED_INT);
		}

		/**
		 * Push an unsigned char to the layout
		 *
		 * @param count: the number of unsigned chars to push
		 */
		template<>
		void push<unsigned char>(const unsigned int count)
		{
			VertexBufferElement e{ GL_UNSIGNED_BYTE, count, GL_TRUE };

			m_Elements.push_back(e);
			m_Stride += count * VertexBufferElement::getSizeOfType(GL_UNSIGNED_BYTE);
		}

	private:
		std::vector<VertexBufferElement> m_Elements;
		unsigned int m_Stride = 0;
	};
}