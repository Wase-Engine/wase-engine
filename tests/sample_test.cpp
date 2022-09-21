#include <gtest/gtest.h>

#include <sample.h>

TEST(SampleTest, SampleClass)
{
	Sample sample(10);
	
	EXPECT_EQ(sample.i, 10);
}