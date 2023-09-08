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
		void unbind() const;

	private:
		unsigned int m_Id;
		unsigned int m_TextureUnit;
	};
}