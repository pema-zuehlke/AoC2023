
#include <iostream>
#include <string>
#include "../common/common.hpp"
#include "day2a.hpp"

Day2a::Day2a(const std::string &fileName, unsigned int expectedR, unsigned int expectedG, unsigned int expectedB):
    fileName{fileName},
    expectedR{expectedR},
    expectedG{expectedG},
    expectedB{expectedB}
{
}

/// @brief Process the input file and store in the most convenient way to be processed on execute
void Day2a::init()
{
    ManageInput::openAndProcessFile(fileName, input);
}

/// @brief Guarantee that the passed value is less than maximum allowed for this color
/// @param[in] value 
/// @param[in] color 
/// @return True = value is equal or lower, False = value is bigger   
bool Day2a::validateInput(const unsigned int &value, const std::string &color)
{
    unsigned int maxValue;
    if(color == "r")
    {
        maxValue = expectedR;
    }
    if(color == "g")
    {
        maxValue = expectedG;
    }
    if(color == "b")
    {
        maxValue = expectedB;
    }

    if(value <= maxValue)
    {
        return true;
    }
    return false;
}

/// @brief Run the day exercise algorithm 
/// @return Return an integer with the exercise result
unsigned int Day2a::execute()
{
    std::vector<std::vector<ProcessInput::Information<std::string>>> output;
    std::map<std::string, std::string> table;
    const char regexExpr[] = {R"((\d+)|(blue)|(red)|(green))"};
    unsigned int result = 0;
    

    table["red"] = "r";
    table["green"] = "g";
    table["blue"] = "b";
    

    ProcessInput::extractInformationFromString(input,
                                                output,
                                                regexExpr,
                                                table,
                                                false);
    
    unsigned int game = 0;

    for(auto line: output)
    {
        game = std::stoi(line[0].info);

        bool invalid = false; 
        for(unsigned int i = 1; i < line.size()-1; i+=2)
        {
            if( !validateInput( std::stoi(line[i].info), line[i+1].info))
            {
                invalid = true;
            }
        }
        if(!invalid)
        {
            result += game;
        }
    }

    return result;
}