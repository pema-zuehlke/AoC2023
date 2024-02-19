#include <iostream>
#include <gtest/gtest.h>
#include "../src/exercises/day1a.hpp"
#include "../src/exercises/day.hpp"

class PrepareTest : public testing::Test 
{
	public:
	PrepareTest(){
		std::cout << "create fixture" << std::endl;

		dayTest = new Day1a("test");
	}
	~PrepareTest()
	{
		delete dayTest;
		std::cout << "delete fixture" << std::endl;
	}

	void SetUp(){}
	void TearDown(){}
	
	Day* dayTest;
};


TEST_F(PrepareTest, test1)
{   
	const std::vector<std::string> input = {"abc", "bcd", "cfd"}; 

    //dayTest->setInput(input);

	ASSERT_EQ(3,2);
}
