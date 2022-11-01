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

    bool fileExist(const char* path) {
        return fs::is_regular_file(fs::path(path));
    }

    bool folderExist(const char* path) {
        return fs::is_directory(fs::path(path));
    }

    std::vector<std::string> getFiles(const char* path) {
        std::vector<std::string> files;

        if (!folderExist(path)) {
            WASE_CORE_WARN("Folder doesn't exist");

            return files;
        }

        for (auto const& dir_entry: fs::directory_iterator{fs::path(path)}) {
            if (dir_entry.is_regular_file())
                files.push_back(dir_entry.path().filename().u8string());
        }

        return files;
    }

    std::vector<std::string> getFolders(const char* path) {
        std::vector<std::string> folders;

        if (!folderExist(path)) {
            WASE_CORE_WARN("Folder doesn't exist");

            return folders;
        }

        for (auto const& dir_entry : fs::directory_iterator{fs::path(path)}) {
            if (dir_entry.is_directory())
                folders.push_back(dir_entry.path().filename().u8string());
        }

        return folders;
    }

}