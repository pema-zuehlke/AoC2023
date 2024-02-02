
#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <regex>
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

namespace ProcessInput
{
    /// @brief Apply the filter to each individual line and if it discover a match append the result to the vector on that line
    /// @param input Input vector with all individual strings
    /// @param output Output 2d array with all the detected results on a specific line 
    /// @param filter Filter that will be applied to detect the pretended patterns
    void extractInformationFromString( const std::vector<std::string> &input, 
                                       std::vector<std::vector<unsigned int>> &output, 
                                       const std::regex &filter)                                    
    {
        for(auto element: input)
        {
            std::vector<unsigned int> line;
            std::smatch match;
            while (std::regex_search(element, match, filter)) 
            {
                line.push_back(std::stoi(match.str()));
                element = match.suffix();
            }
            output.push_back(line);
        }
        

    }

    /// @brief Generate a filter to extract single digits from each string on input, and append to output vector
    /// @param input Input vector with all the individual strings
    /// @param output 
    void extractIntegerFromString(const std::vector<std::string> &input, std::vector<std::vector<unsigned int>> &output)
    {
        std::regex filter(R"(\d+)");   // matches a sequence of digits
        extractInformationFromString(input, output, filter);
    }

    /// @brief Generate a filter to extract single digits from each string on input, and append to output vector
    /// @param[in] input Input vector with all the individual strings
    /// @param[out] output Output vector will be a 2d array containing the individual elements found in the second vector
    void extractDigitFromString(const std::vector<std::string> &input, std::vector<std::vector<unsigned int>> &output)
    {
        std::regex filter(R"(\d)");   // find single digits
        extractInformationFromString(input, output, filter);
    }

} // namespace ProcessInput  

    



