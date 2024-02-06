
#include <iostream>
#include "../common/common.hpp"
#include "day1b.hpp"

Day1b::Day1b(const std::string &fileName):
    fileName{fileName}
{
}

/// @brief Process the input file and store in the most convenient way to be processed on execute
void Day1b::init()
{
    ManageInput::openAndProcessFile(fileName, input);
}

/// @brief Run the day exercise algorithm 
/// @return Return an integer with the exercise result
unsigned int Day1b::execute()
{
    unsigned int result = 0;
    std::vector<std::vector<ProcessInput::Information<std::string>>> output;
    std::map<std::string, std::string> table =  {  
                                                    {"0", "0"},
                                                    {"zero", "0"},
                                                    {"1", "1"},
                                                    {"one", "1"},
                                                    {"2", "2"},
                                                    {"two", "2"},
                                                    {"3", "3"},
                                                    {"three", "3"},
                                                    {"4", "4"},
                                                    {"four", "4"},
                                                    {"5", "5"},
                                                    {"five", "5"},
                                                    {"6", "6"},
                                                    {"six", "6"},
                                                    {"7", "7"},
                                                    {"seven", "7"},
                                                    {"8", "8"},
                                                    {"eight", "8"},
                                                    {"9", "9"},
                                                    {"nine", "9"}
                                                };

    ProcessInput::extractInformationFromString( input, 
                                       output, 
                                       ProcessInput::c_extractDigitAndDigitInText,
                                       table);
    
    for(auto line:output)
    {
        result += (std::stoi(line[0].info))*10 + std::stoi(line[line.size()-1].info);
    }
    
    return result;
}