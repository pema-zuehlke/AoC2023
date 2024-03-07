#include <iostream>
#include <gtest/gtest.h>
#include "src/common/common.hpp"
#include "src/common/ICommon.hpp"
#include "config/config.hpp"

TEST(CommonManageInputTest, happyCase)
{
    ManageInput manageInput;

    std::string filePath = getTestBaseFileDir() + "fourLines" + getFileExtension();
    std::vector<std::string> input;
    
    bool result = manageInput.openAndProcessFile(filePath, input);
    
    EXPECT_EQ(input.size(), 4);
    ASSERT_TRUE(result);
} 

TEST(CommonManageInputTest, emptyFile)
{
    ManageInput manageInput;

    std::string filePath = getTestBaseFileDir() + "emptyFile" + getFileExtension();
    std::vector<std::string> input;

    bool result = manageInput.openAndProcessFile(filePath, input);
    
    EXPECT_EQ(input.size(), 0);
    ASSERT_TRUE(result);
} 

TEST(CommonManageInputTest, nonExistingFile)
{
    ManageInput manageInput;

    std::string filePath = getTestBaseFileDir() + "nonExistenceFile" + getFileExtension();
    std::vector<std::string> input;
    
    bool result = manageInput.openAndProcessFile(filePath, input);
    
    ASSERT_FALSE(result);
} 

class ProcessInputTest : public testing::Test 
{
	public:
	ProcessInputTest()
    {
	}
	~ProcessInputTest()
	{
	}

	void SetUp()
	{
		input = 
		{
			"1abc2",
			"pqr33tu8vwx",
			"a1b2c3d4e5f",
			"treb7uchet",
            "oneeighttwone"
		}; 

        output.clear();
	}
	void TearDown(){}
	
    std::vector<std::vector<ProcessInput::Information<std::string>>> output;
    std::vector<std::string> input;
};


TEST_F(ProcessInputTest, happyCaseWithInputOutputDigitFilterParameter)
{
    ProcessInput::extractInformationFromString(input, output, ProcessInput::c_extractDigit);
    EXPECT_EQ(output[0].size(), 2);
    EXPECT_EQ(output[1].size(), 3);
    EXPECT_EQ(output[2].size(), 5);
    EXPECT_EQ(output[3].size(), 1);
    EXPECT_EQ(output[4].size(), 0);
}

TEST_F(ProcessInputTest, happyCaseWithInputOutputIntegerFilterParameter)
{
    ProcessInput::extractInformationFromString(input, output, ProcessInput::c_extractInteger);
    EXPECT_EQ(output[0].size(), 2);
    EXPECT_EQ(output[1].size(), 2);
    EXPECT_EQ(output[2].size(), 5);
    EXPECT_EQ(output[3].size(), 1);
    EXPECT_EQ(output[4].size(), 0);
}

TEST_F(ProcessInputTest, happyCaseWithInputOutputDigitAndDigitInTextFilterParameter)
{
    ProcessInput::extractInformationFromString(input, output, ProcessInput::c_extractDigitAndDigitInText);
    EXPECT_EQ(output[0].size(), 2);
    EXPECT_EQ(output[1].size(), 3);
    EXPECT_EQ(output[2].size(), 5);
    EXPECT_EQ(output[3].size(), 1);
    EXPECT_EQ(output[4].size(), 3);
}

