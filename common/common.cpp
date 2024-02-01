
#include <iostream>
#include <string>
#include <fstream>
#include "common.hpp"
#include "../exercises/day.hpp"
#include "../exercises/day1.hpp"

#define INPUT_DIRECTORY "/home/pema/AoC2023/input/" 
//TODO: move to a different way of not having it hardcoded 
#define EXTENSION ".txt" 
//TODO: move to a different way of not having it hardcoded 

namespace ManageInput
{
    
    /// @brief Open the file INPUT_DIRECTORY + fileName + EXTENSION and extract each line of it, appending it to input vector
    /// @param[in] fileName Name of the file to be opened  
    /// @param[out] output Vector that will have all the lines of the file as a String
    /// @return True = everything work well, False = Something went wrong
    bool openAndProcessFile(const std::string &fileName, std::vector<std::string> &output)
    {
        std::string fileNameWithPathAndExtension = std::string(INPUT_DIRECTORY) + fileName + std::string(EXTENSION);
        
        std::ifstream file(fileNameWithPathAndExtension);
        //TODO: Verify if the file exist, otherwise create it

        if(!file.is_open())
        {
            log("unable to open file:" << fileNameWithPathAndExtension);
            return false;
        }

        std::string line;
        while (std::getline(file, line))
        {
            log(line);
            output.push_back(line);
        }

        file.close();

        return true;
    }

    /// @brief Receive the day of the exercise and try to instantiate the correct code to run
    /// @param[in] nameOfDay - String with the name of the day
    /// @return pointer to Day instance, nullptr in case of any error
    Day* daySearch(const std::string &nameOfDay)
    {
        if(nameOfDay.compare("day1") == 0)
        {
            return new Day1(nameOfDay);
        }

        return nullptr;
    }

} // namespace ManageInput

