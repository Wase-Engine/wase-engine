#define STB_IMAGE_IMPLEMENTATION

#include <stb_image.h>

#include <resources/resource_pool.h>
#include <debugging/log.h>

namespace wase::resources
{
	void ResourcePool::loadImage(const std::string& name, const char* path)
	{
		int width, height, channels;
		unsigned char* data = stbi_load(path, &width, &height, &channels, 0);
		if (data == nullptr)
		{
			WASE_CORE_WARN("Failed to load image: {0}", name);
			return;
		}
		
		if (m_Images.count(name) > 0)
		{
			WASE_CORE_WARN("Image already loaded: {0}", name);
			return;
		}
		
		m_Images[name] = Image{ data, width, height, channels };
		m_Count++;
	}

	unsigned int ResourcePool::count() const
	{
		return m_Count;
	}

	const Image* ResourcePool::getImage(const std::string& name)
	{
		if (m_Images.count(name) == 0)
		{
			WASE_CORE_WARN("Image not found: {0}", name);
			return nullptr;
		}

		return &m_Images[name];
	}
}