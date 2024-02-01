#ifndef COMMON_HPP
#define COMMON_HPP

#define log(x)  std::cout << x << std::endl

#include <string>
#include <vector>
#include "../exercises/day.hpp"

namespace ManageInput
{
    bool openAndProcessFile(const std::string &fileLocation, std::vector<std::string> &input);

    void extractIntegerFromString(const std::vector<std::string> &input, std::vector<std::vector<unsigned int>> &output);
    void extractDigitFromString(const std::vector<std::string> &input, std::vector<std::vector<unsigned int>> &output);

    Day* daySearch(const std::string &nameOfDay);
}
#endif
