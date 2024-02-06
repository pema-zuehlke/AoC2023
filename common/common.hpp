#ifndef COMMON_HPP
#define COMMON_HPP

#define log(x)  (std::cout << x << std::endl)

#include <string>
#include <vector>
#include <regex>
#include "../exercises/day.hpp"

namespace ManageInput
{
    bool openAndProcessFile(const std::string &fileLocation, std::vector<std::string> &input);
    Day* daySearch(const std::string &nameOfDay);
}
namespace ProcessInput
{
    template <typename T>
    struct Information
    {
        unsigned int startPos;
        unsigned int length;
        T info;
    };

    constexpr const char c_extractInteger[] = {R"(\d+)"};
    constexpr const char c_extractDigit[] = {R"(\d)"};
    constexpr const char c_extractDigitAndDigitInText[] = {R"([\d]|(zero)|(one)|(two)|(three)|(four)|(five)|(six)|(seven)|(eight)|(nine))"};

    void extractInformationFromString( const std::vector<std::string> &input, 
                                       std::vector<std::vector<Information<std::string> > > &output, 
                                       const char *);

    void extractInformationFromString( const std::vector<std::string> &input, 
                                       std::vector<std::vector<Information<std::string> > > &output, 
                                       const char *filter,
                                       std::map<std::string, std::string> &conversionTable);
    
}
#endif
