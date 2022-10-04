#pragma once

#include <string>

namespace wase::io
{
	/**
	 * Read the contents of a file
	 * 
	 * @param path: the path to the file
	 * @return the contents of the file as a std::string
	 */
	std::string readFile(const char* path);
}