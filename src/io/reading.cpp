#include <fstream>
#include <sstream>

#include <io/reading.h>
#include <debugging/log.h>

namespace wase::io
{
	std::string readFile(const char* path)
	{
		std::string result;
		std::ifstream stream;

		stream.exceptions(std::ifstream::failbit | std::ifstream::badbit);

		try
		{
			std::stringstream fileContent;

			stream.open(path);
			fileContent << stream.rdbuf();
			stream.close();
			
			result = fileContent.str();
		}
		catch (const std::exception& exception)
		{
			WASE_CORE_WARN("Failed to read file: {0}", exception.what());
		}

		return result;
	}
}