#pragma once

namespace wase::rendering
{
	class IBO
	{
	public:
		IBO();

		/**
		 * Bind the index buffer
		 */
		void bind() const;

		/**
		 * Unbind the index buffer
		 */
		static void unbind();

		/**
		 * Set the data of the index buffer
		 *
		 * @param data: the data to set
		 * @param size: the size of the data
		 */
		void setData(const void* data, const unsigned int size);

	private:
		unsigned int m_ID;
	};
}