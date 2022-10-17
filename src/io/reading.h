#pragma once

#include <string>
#include <filesystem>
#include <vector>

namespace fs = std::filesystem;

namespace wase::io
{
	/**
	 * Read the contents of a file
	 *
	 * @param path: the path to the file
	 * @return the contents of the file as a std::string
	 */
	std::string readFile(const char* path);

    /**
     * Checks if a file exist
     *
     * @param path: the path to the potential file
     * @return true if file exist, false otherwise
     */
    bool fileExist(const char* path);

    /**
     * Checks if a folder exist
     *
     * @param path: path to the potential folder
     * @return true if file exist, false otherwise
     */
    bool folderExist(const char* path);

    /**
     * Returns the names and extension of the files at the given path
     *
     * @param path: path to the folder
     * @return std::vector<string> with the file names
     */
    std::vector<std::string> getFiles(const char* path);

    /**
     * Return the names of the folders at the given path
     *
     * @param path: path to the folder
     * @return std::vector<string> with the folder names
     */
    std::vector<std::string> getFolders(const char* path);
}