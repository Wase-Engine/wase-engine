#pragma once

#include <string>

#include <resources/image.h>

namespace wase::rendering
{
	class Texture
	{
	public:
		Texture(resources::Image* image, const unsigned int textureUnit);

		void bind() const;
		static void unbind();

	private:
		unsigned int m_Id;
		unsigned int m_TextureUnit;
	};
}