
#include <iostream>
#include <string>
#include "../common/common.hpp"
#include "day2b.hpp"

Day2b::Day2b(const std::string &fileName):
    fileName{fileName}
{
}

/// @brief Process the input file and store in the most convenient way to be processed on execute
void Day2b::init()
{
    ManageInput::openAndProcessFile(fileName, input);
}

/// @brief Verify if the value for the specific color is bigger than the stored value. If it is, replace it
/// @param[in] value New value to be analyzed 
/// @param[in] colour Respective colour 
void Day2b::validateInput(const unsigned int &value, const std::string &colour)
{
    unsigned int* ptr; 
    if(colour == "r")
    {
        ptr = &maxR;
    }
    if(colour == "g")
    {
        ptr = &maxG;
    }
    if(colour == "b")
    {
        ptr = &maxB;
    }

    if(value > *ptr)
    {
        *ptr = value;
    }
}

/// @brief Add value to the correspondent colour total value 
/// @param value Value to be added
/// @param colour Select the desired colour 
/// @param roundR Total Red
/// @param roundG Total Green
/// @param roundB Total Blue
void Day2b::addValue(unsigned int value, 
                    const std::string &colour, 
                    unsigned int &roundR, 
                    unsigned int &roundG, 
                    unsigned int &roundB)
{
    if(colour == "r")
    {
        roundR += value;
    }
    if(colour == "g")
    {
        roundG += value;
    }
    if(colour == "b")
    {
        roundB += value;
    }

}

/// @brief Run the day exercise algorithm 
/// @return Return an integer with the exercise result
unsigned int Day2b::execute()
{
    std::vector<std::vector<ProcessInput::Information<std::string>>> output;
    std::map<std::string, std::string> table;
    const char regexExpr[] = {R"((\d+)|(blue)|(red)|(green)|(;))"};
    unsigned int result = 0;
    
    table["red"] = "r";
    table["green"] = "g";
    table["blue"] = "b";

    ProcessInput::extractInformationFromString(input,
                                                output,
                                                regexExpr,
                                                table,
                                                false);
    
    for(auto line: output)
    {
        maxR = 0;
        maxG = 0;
        maxB = 0;

        unsigned int roundR = 0;
        unsigned int roundG = 0;
        unsigned int roundB = 0;

        for(unsigned int i = 1; i < line.size()-1; i+=2)
        {
            if(line[i].info == ";")
            {
                i--;

                validateInput( roundR, "r");
                validateInput( roundG, "g");
                validateInput( roundB, "b");
                roundR = 0;
                roundG = 0;
                roundB = 0;   
                continue;            
            }
            else
            {
                addValue(std::stoi(line[i].info), line[i+1].info, roundR, roundG, roundB);
            }
            
            
        }
        validateInput( roundR, "r");
        validateInput( roundG, "g");
        validateInput( roundB, "b");
        result += maxR * maxG * maxB;
    }

    return result;
}