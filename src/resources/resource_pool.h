#pragma once

#include <unordered_map>
#include <vector>
#include <string>

#include <resources/image.h>
#include <resources/resource.h>

namespace wase::resources
{
	class ResourcePool
	{
	public:
		/**
		 * Initialize the ResourcePool with a list of resources to load
		 * 
		 * @param resources The list of resources to load
		 */
		void initialize(const std::vector<Resource>& resources);

		/**
		 * Load an image
		 * 
		 * @param name: the reference name of the image
		 * @param path: the path to the image
		 */
		void loadImage(const std::string& name, const std::string& path);

		/**
		 * Get an image
		 *
		 * @param name: the reference name of the image
		 * @return the image
		 */
		Image* getImage(const std::string& name);

		/**
		 * Returns the amount of resources loaded
		 * 
		 * @return the amount of resources loaded
		 */
		unsigned int count() const;

	private:
		std::unordered_map<std::string, Image> m_Images;

		unsigned int m_Count = 0;
	};
}