#include <filesystem>

#include <io/writing.h>
#include <debugging/log.h>

namespace fs = std::filesystem;

namespace wase::io
{
	void copy(const char* source, const char* destination)
	{
		try
		{
			fs::copy(source, destination);
		}
		catch (const std::exception& exception)
		{
			WASE_CORE_WARN("Failed to copy file: {0}", exception.what());
		}
	}

	void remove(const char* path)
	{
		try
		{
			fs::remove_all(path);
		}
		catch (const std::exception& exception)
		{
			WASE_CORE_WARN("Failed to remove file: {0}", exception.what());
		}
	}

	void createFolder(const char* path)
	{
		try
		{
			fs::create_directory(path);
		}
		catch (const std::exception& exception)
		{
			WASE_CORE_WARN("Failed to create folder: {0}", exception.what());
		}
	}
}