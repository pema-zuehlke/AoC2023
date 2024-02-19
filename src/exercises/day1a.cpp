
#include <iostream>
#include <string>
#include "../common/common.hpp"
#include "day1a.hpp"

Day1a::Day1a(const std::string &fileName):
    fileName{fileName}
{
}

/// @brief Process the input file and store in the most convenient way to be processed on execute
void Day1a::init()
{
    ManageInput::openAndProcessFile(fileName, input);
}

/// @brief Run the day exercise algorithm 
/// @return Return an integer with the exercise result
unsigned int Day1a::execute()
{
    unsigned int result = 0;
    std::vector<std::vector<ProcessInput::Information<std::string>>> output;

    ProcessInput::extractInformationFromString(input,
                                                output,
                                                ProcessInput::c_extractDigit);
    
    for(auto line:output)
    {
        result += (std::stoi(line[0].info))*10 + std::stoi(line[line.size()-1].info);
    }

    return result;
}

const std::vector<std::string>& Day1a::getInput()
{
    return input;
}
void Day1a::setInput(const std::vector<std::string>& newInput)
{


}