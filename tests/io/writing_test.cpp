#include <gtest/gtest.h>

#include <io/writing.h>
#include <io/reading.h>

using namespace wase::io;

TEST(IOWritingTest, Copy)
{
	EXPECT_EQ(fileExist("assets/io/writing_tests/subfolder/moving_file.txt"), false);

	copy("assets/io/writing_tests/moving_file.txt", "assets/io/writing_tests/subfolder/moving_file.txt");

	EXPECT_EQ(fileExist("assets/io/writing_tests/moving_file.txt"), true);

	wase::io::remove("assets/io/writing_tests/subfolder/moving_file.txt");
}

TEST(IOWritingTest, Remove)
{
	EXPECT_EQ(fileExist("assets/io/writing_tests/moving_file.txt"), true);

	wase::io::remove("assets/io/writing_tests/moving_file.txt");

	EXPECT_EQ(fileExist("assets/io/writing_tests/moving_file.txt"), false);

	createFile("assets/io/writing_tests/moving_file.txt");
}

TEST(IOWritingTest, CreateFileWithoutContent)
{
	EXPECT_EQ(fileExist("assets/io/writing_tests/new_file.txt"), false);

	createFile("assets/io/writing_tests/new_file.txt");

	EXPECT_EQ(fileExist("assets/io/writing_tests/new_file.txt"), true);

	wase::io::remove("assets/io/writing_tests/new_file.txt");
}

TEST(IOWritingTest, CreateFileWithContent)
{
	EXPECT_EQ(fileExist("assets/io/writing_tests/new_file.txt"), false);

	createFile("assets/io/writing_tests/new_file.txt", "Hello World!");

	EXPECT_EQ(fileExist("assets/io/writing_tests/new_file.txt"), true);
	EXPECT_EQ(readFile("assets/io/writing_tests/new_file.txt"), "Hello World!");

	wase::io::remove("assets/io/writing_tests/new_file.txt");
}

TEST(IOWritingTest, CreateFolder)
{
	EXPECT_EQ(folderExist("assets/io/writing_tests/new_folder"), false);

	createFolder("assets/io/writing_tests/new_folder");

	EXPECT_EQ(folderExist("assets/io/writing_tests/new_folder"), true);

	wase::io::remove("assets/io/writing_tests/new_folder");
}

TEST(IOWritingTest, Write)
{
	EXPECT_EQ(fileExist("assets/io/writing_tests/new_file.txt"), false);

	write("assets/io/writing_tests/new_file.txt", "Hello World!");

	EXPECT_EQ(fileExist("assets/io/writing_tests/new_file.txt"), true);
	EXPECT_EQ(readFile("assets/io/writing_tests/new_file.txt"), "Hello World!");

	wase::io::remove("assets/io/writing_tests/new_file.txt");
}