#include <string>
#include <algorithm>

#include <gtest/gtest.h>

#include <io/reading.h>

using namespace wase::io;

TEST(IOReadingTest, ReadFile)
{
	std::string	file1 = readFile("assets/io/reading_tests/test_file1.txt");
	std::string	file2 = readFile("assets/io/reading_tests/test_file2.txt");
	std::string	fileDoesntExist = readFile("assets/io/reading_tests/file_doesnt_exist.txt");

	EXPECT_EQ(file1, "Hello, World!");
	EXPECT_EQ(file2, "Second test file!\nGreetings!");
	EXPECT_EQ(fileDoesntExist, "");
}

TEST(IOReadingTest, FileExist)
{
	EXPECT_TRUE(fileExist("assets/io/reading_tests/test_file1.txt"));
	EXPECT_FALSE(fileExist("assets/io/reading_tests/file_doesnt_exist.txt"));
}

TEST(IOReadingTest, FolderExist)
{
	EXPECT_TRUE(folderExist("assets/io/reading_tests"));
	EXPECT_FALSE(folderExist("assets/io/reading_tests/folder_doesnt_exist"));
}

TEST(IOReadingTest, GetFiles)
{
	std::vector<std::string> files = getFiles("assets/io/reading_tests");

	std::sort(files.begin(), files.end());

	EXPECT_EQ(files.size(), 2);
	EXPECT_EQ(files[0], "test_file1.txt");
	EXPECT_EQ(files[1], "test_file2.txt");
}

TEST(IOReadingTest, GetFolders)
{
	std::vector<std::string> folders = getFolders("assets/io/reading_tests");

	EXPECT_EQ(folders.size(), 1);
	EXPECT_EQ(folders[0], "subfolder");
}