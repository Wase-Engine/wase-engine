#pragma once

namespace wase::io
{
	/**
	 * Copies a file from one location to another
	 * 
	 * @param source: the path to the file to copy
	 * @param destination: the destination path
	 */
	void copy(const char* source, const char* destination);

	/**
	 * Deletes a file
	 * 
	 * @param path: the path to the file to delete
	 */
	void remove(const char* path);

	/**
	 * Create a new file
	 * 
	 * @param path: the path to the file to 
	 */
	template<typename T = char>
	void createFile(const char* path, const T& content = NULL);

	/**
	 * Create a new folder
	 * 
	 * @param path: the path to the folder to create
	 */
	void createFolder(const char* path);

	/**
	 * Write data to a file
	 * 
	 * @param path: the path to the file to write to
	 * @param data: the data to write to the file
	 */
	template<typename T>
	void write(const char* path, const T& content);
}

#include <io/writing.inl>