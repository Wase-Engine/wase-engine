#pragma once

#include <filesystem>
#include <fstream>

#include <io/writing.h>
#include <debugging/log.h>

namespace fs = std::filesystem;

namespace wase::io
{
	template<typename T>
	void createFile(const char* path, const T& content)
	{
		try
		{
			std::ofstream newFile(path);
			newFile << content;
			newFile.close();
		}
		catch (const std::exception& exception)
		{
			WASE_CORE_WARN("Failed to create file: {0}", exception.what());
		}
	}

	template<typename T>
	void write(const char* path, const T& content)
	{
		try
		{
			std::ofstream file(path, std::ios::out | std::ios::trunc);
			if (file.is_open())
			{
				file << content;
				file.close();
			}
			else
			{
				throw std::exception("Unable to open the file.");
			}
		}
		catch (const std::exception& exception)
		{
			WASE_CORE_WARN("Failed to write to file: {0}", exception.what());
		}
	}
}