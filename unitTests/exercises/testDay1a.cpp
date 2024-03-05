#include <iostream>
#include <gtest/gtest.h>
#include "src/exercises/daysIncluded.hpp"

class Day1Test : public testing::Test 
{
	public:
	Day1Test(){
		//std::cout << "create fixture" << std::endl;

		dayTest = new Day1a("test");
	}
	~Day1Test()
	{
		delete dayTest;
		//std::cout << "delete fixture" << std::endl;
	}

	void SetUp()
	{
		const std::vector<std::string> input = 
		{
			"1abc2",
			"pqr3stu8vwx",
			"a1b2c3d4e5f",
			"treb7uchet"
		}; 
		dayTest->setInput(input);
	}
	void TearDown(){}
	
	Day1a* dayTest;
};

TEST_F(Day1Test, basicTest)
{   
	ASSERT_EQ(dayTest->execute(), 142);
}

TEST_F(Day1Test, noValue)
{   
	const std::vector<std::string> input = 
		{
			"abc",
			"pqrstuvwx",
			"abcdef",
			"trebuchet"
		}; 
	dayTest->setInput(input);

	ASSERT_EQ(dayTest->execute(), 0);
}


TEST_F(Day1Test, allDigits)
{   
	const std::vector<std::string> input = 
		{
			"111",
			"222",
			"333"
		}; 
	dayTest->setInput(input);
	ASSERT_EQ(dayTest->execute(), 66);
}

TEST_F(Day1Test, onlyOneDigitPerLine)
{   
	const std::vector<std::string> input = 
		{
			"1abc",
			"pqrst2uvwx",
			"abcdef3"
		}; 
	dayTest->setInput(input);

	ASSERT_EQ(dayTest->execute(), 66);
}
