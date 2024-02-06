
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
    if(fileName.length() > 0 && input.size() == 0)
    {
        ManageInput::openAndProcessFile(fileName, input);
    } 
    else 
    {
        log("Day1b init: Parameters aren't correct");
    }
}

/// @brief Run the day exercise algorithm 
/// @return Return an integer with the exercise result
unsigned int Day1b::execute()
{
    unsigned int result = 0;
    std::vector<std::vector<ProcessInput::Information<std::string>>> output;
    std::map<std::string, std::string> table;
      
    table["0"] = "0";
    table["zero"] = "0";
    table["1"] = "1";
    table["one"] = "1";
    table["2"] = "2";
    table["two"] = "2";
    table["3"] = "3";
    table["three"] = "3";
    table["4"] = "4";
    table["four"] = "4";
    table["5"] = "5";
    table["five"] = "5";
    table["6"] = "6";
    table["six"] = "6";
    table["7"] = "7";
    table["seven"] = "7";
    table["8"] = "8";
    table["eight"] = "8";
    table["9"] = "9";
    table["nine"] = "9";    

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