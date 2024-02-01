#ifndef COMMON_HPP
#define COMMON_HPP

#define log(x)  std::cout << x << std::endl

#include <string>
#include <vector>
#include "../exercises/day.hpp"

namespace ManageInput
{
    bool openAndProcessFile(const std::string &fileLocation, std::vector<std::string> &input);

    Day* daySearch(const std::string &nameOfDay);
}
#endif
