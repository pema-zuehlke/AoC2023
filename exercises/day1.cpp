
#include <iostream>
#include "../common/common.hpp"
#include "day1.hpp"

Day1::Day1(const std::string &fileName):
    fileName{fileName}
{
}

/// @brief Process the input file and store in the most convenient way to be processed on execute
void Day1::init()
{
    ManageInput::openAndProcessFile(fileName, input);
}

/// @brief Run the day exercise algorithm 
/// @return Return an integer with the exercise result
unsigned int Day1::execute()
{
    unsigned int result = 0;
    std::vector<std::vector<unsigned int>> output;
    ManageInput::extractDigitFromString(input, output);
    
    for(auto line:output)
    {
        result += line[0]*10 + line[line.size()-1];
    }

    return result;
}