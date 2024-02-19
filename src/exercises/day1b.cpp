
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
    std::map<std::string, std::string> table;
      
    table["zero"] = "0";
    table["one"] = "1";
    table["two"] = "2";
    table["three"] = "3";
    table["four"] = "4";
    table["five"] = "5";
    table["six"] = "6";
    table["seven"] = "7";
    table["eight"] = "8";
    table["nine"] = "9";    
     
    ProcessInput::extractInformationFromString( input, 
                                       output, 
                                       ProcessInput::c_extractDigitAndDigitInText,
                                       table,
                                       true);
    
    for(auto line:output)
    {
        result += (std::stoi(line[0].info))*10 + std::stoi(line[line.size()-1].info);
    }
    
    return result;
}