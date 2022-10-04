#pragma once

#include <vector>
#include <type_traits>

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

		/**
		 * Push a float to the layout
		 *
		 * @param count: the number of floats to push
		 */
		void pushFloat(const unsigned int count);

		/**
		 * Push an unsigned int to the layout
		 *
		 * @param count: the number of unsigned integers to push
		 */
		void pushUInt(const unsigned int count);

		/**
		 * Push an unsigned char to the layout
		 *
		 * @param count: the number of unsigned chars to push
		 */
		void pushUChar(const unsigned int count);

	private:
		std::vector<VertexBufferElement> m_Elements;
		unsigned int m_Stride = 0;
	};
}