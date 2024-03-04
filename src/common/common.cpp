
#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <regex>
#include <map>
#include "common.hpp"
#include "config/config.hpp"

namespace ManageInput
{
    /// @brief Open the file INPUT_DIRECTORY + fileName + EXTENSION and extract each line of it, appending it to input vector
    /// @param[in] fileName Name of the file to be opened  
    /// @param[out] output Vector that will have all the lines of the file as a String
    /// @return True = everything work well, False = Something went wrong
    bool openAndProcessFile(const std::string &fileName, std::vector<std::string> &output)
    {
        std::string fileNameWithPathAndExtension = baseDir + fileName + extension;
        
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
        std::string fileName = nameOfDay;
        if(!fileName.empty())
        {
            fileName.pop_back();
        }
        else 
        {
            return nullptr;
        }

        if(nameOfDay.compare("day1a") == 0)
        {
            return new Day1a(fileName);
        }
        if(nameOfDay.compare("day1b") == 0)
        {
            return new Day1b(fileName);
        }
        if(nameOfDay.compare("day2a") == 0)
        {
            return new Day2a(fileName, 12, 13, 14);
        }
        if(nameOfDay.compare("day2b") == 0)
        {
            return new Day2b(fileName);
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
                                       std::vector<std::vector<Information<std::string>>> &output, 
                                       const char *filter)                                    
    {
        std::map<std::string, std::string> table;
        
        extractInformationFromString(input,
                                    output,
                                    filter,
                                    table);    
    }

    /// @brief Apply the filter to each individual line and if it discover a match verify if there is any conversion table.
    ///        If table exist process information based on it. Otherwise append the discovered information
    /// @param[in] input Input vector with all individual strings
    /// @param[out] output Output 2d array with all the detected results on a specific line 
    /// @param[in] filter Filter that will be applied in order to detect the desired patterns
    /// @param[in] conversionTable Table containing the "key", "value" translation. 
    void extractInformationFromString( const std::vector<std::string> &input, 
                                       std::vector<std::vector<Information<std::string> > > &output, 
                                       const char *filter,
                                       std::map<std::string, std::string> &conversionTable)                                       
    {
        std::regex regexFilter(filter);

        const unsigned int conversionTableSize = conversionTable.size();

        for(auto element: input)
        {
            std::vector<Information<std::string>> line;
            std::smatch match;
            Information<std::string> info;
            unsigned int pos = 0;
            while (std::regex_search(element, match, regexFilter)) 
            {
                info.length = match.length();
                info.startPos = match.position() + pos; 

                if(conversionTableSize && conversionTable.count(match.str()) > 0)
                {
                    info.info = conversionTable[match.str()];
                }
                else 
                {
                    info.info = match.str();

                }   

                line.push_back(info);
                element = match.suffix();  
                pos += match.position() + info.length;            
            }
            output.push_back(line);
        } 
    }


    /// @brief Apply the filter to each individual line and if it discover a match verify if there is any conversion table.
    ///        If table exist process information based on it. Otherwise append the discovered information
    /// @param[in] input Input vector with all individual strings
    /// @param[out] output Output 2d array with all the detected results on a specific line 
    /// @param[in] filter Filter that will be applied in order to detect the desired patterns
    /// @param[in] conversionTable Table containing the "key", "value" translation. 
    /// @param[in] overlapSearch Verify if items can overlap  
    void extractInformationFromString( const std::vector<std::string> &input, 
                                       std::vector<std::vector<Information<std::string> > > &output, 
                                       const char *filter,
                                       std::map<std::string, std::string> &conversionTable,
                                       const bool overlapSearch)
    {
        if(!overlapSearch)
        {
            extractInformationFromString(input,
                                    output,
                                    filter,
                                    conversionTable); 
            return; 
        }

        std::regex regexFilter(filter);

        const unsigned int conversionTableSize = conversionTable.size();

        for(auto element: input)
        {
            std::vector<Information<std::string>> line;
            std::smatch match;
            Information<std::string> info;
            unsigned int pos = 0;
            while (std::regex_search(element, match, regexFilter)) 
            {
                info.length = match.length();
                info.startPos = match.position() + pos; 

                if(conversionTableSize && conversionTable.count(match.str()) > 0)
                {
                    info.info = conversionTable[match.str()];
                }
                else 
                {
                    info.info = match.str();
                }   

                line.push_back(info);

                if(match.length() > 1)
                {
                    element = element.erase(0, match.position() + match.length() - 1);
                    pos = info.startPos + info.length -1;
                } 
                else 
                {
                    element = match.suffix();
                    pos = info.startPos + 1;
                }                
            }
            output.push_back(line);
        } 
    }

} // namespace ProcessInput  

    



