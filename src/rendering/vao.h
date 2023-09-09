#pragma once

#include <rendering/vbo.h>
#include <rendering/vertex_buffer_layout.h>

namespace wase::rendering
{
	class VAO
	{
	public:
		VAO();

		/**
		 * Bind the VAO
		 */
		void bind() const;

		/**
		 * Unbind the VAO
		 */
		void unbind() const;

		/**
		 * Add a buffer to the VAO
		 *
		 * @param vbo: the VBO to add
		 * @param vbl: the layout of the VBO
		 */
		void addBuffer(const VBO* vbo, const VertexBufferLayout& vbl) const;

	private:
		unsigned int m_ID;
	};
}