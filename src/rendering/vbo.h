#pragma once

namespace wase::rendering
{
	class VBO
	{
	public:
		VBO();

		/**
		 * Bind the VBO
		 */
		void bind() const;

		/**
		 * Unbind the VBO
		 */
		static void unbind();

		/**
		 * Set the data of the VBO
		 * 
		 * @param data: the data to set
		 * @param size: the size of the data
		 */
		void setData(const void* data, const unsigned int size) const;

	private:
		unsigned int m_ID;
	};
}