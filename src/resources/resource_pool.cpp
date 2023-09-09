#define STB_IMAGE_IMPLEMENTATION

#include <stb_image.h>
#include <GL/glew.h>

#include <resources/resource_pool.h>
#include <debugging/log.h>

namespace wase::resources
{
	void ResourcePool::loadImage(const std::string& name, const char* path)
	{
		if (m_Images.count(name) > 0)
		{
			WASE_CORE_WARN("Image already loaded: {0}", name);
			return;
		}
		
		stbi_set_flip_vertically_on_load(true);
		
		int width, height, channels;
		unsigned int format;
		unsigned char* data = stbi_load(path, &width, &height, &channels, 0);
		if (data)
		{
			if (channels == 1)
				format = GL_RED;
			else if (channels == 3)
				format = GL_RGB;
			else if (channels == 4)
				format = GL_RGBA;
			else
			{
				WASE_CORE_WARN("Failed to load texture: {0}", std::string(path));
				stbi_image_free(data);
				return;
			}
		}
		else
		{
			WASE_CORE_WARN("Failed to load image: {0}", name);
			return;
		}
		
		m_Images[name] = Image{ data, width, height, channels, format };
		m_Count++;
	}

	unsigned int ResourcePool::count() const
	{
		return m_Count;
	}

	Image* ResourcePool::getImage(const std::string& name)
	{
		if (m_Images.count(name) == 0)
		{
			WASE_CORE_WARN("Image not found: {0}", name);
			return nullptr;
		}

		return &m_Images[name];
	}
}