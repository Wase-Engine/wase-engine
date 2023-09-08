#include <GL/glew.h>

#include <rendering/texture.h>
#include <debugging/log.h>

namespace wase::rendering
{

	Texture::Texture(resources::Image* image, const unsigned int textureUnit)
	{
		if(!image)
		{
			WASE_CORE_WARN("Image is nullptr");
			return;
		}

		glGenTextures(1, &m_Id);
		glActiveTexture(GL_TEXTURE0 + m_TextureUnit);
		glBindTexture(GL_TEXTURE_2D, m_Id);

		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, image->width, image->height, 0, image->format, GL_UNSIGNED_BYTE, image->data);
		glGenerateMipmap(GL_TEXTURE_2D);
	}

	void Texture::bind() const
	{
		glActiveTexture(GL_TEXTURE0 + m_TextureUnit);
		glBindTexture(GL_TEXTURE_2D, m_Id);
	}

	void Texture::unbind() const
	{
		glActiveTexture(0);
		glBindTexture(GL_TEXTURE_2D, 0);
	}
}