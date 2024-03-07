#ifndef ICOMMON_HPP
#define ICOMMON_HPP

#include <string>
#include <vector>
#include "src/exercises/daysIncluded.hpp"

class ICommon
{
    public:
        virtual ~ICommon() = default;
        
};

class IManageInput
{
    public:
        virtual ~IManageInput() = default;
        virtual bool openAndProcessFile(const std::string &fileLocation, std::vector<std::string> &input) = 0;
        virtual IDay* daySearch(const std::string &nameOfDay) = 0;
};

#endif