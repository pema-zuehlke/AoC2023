#ifndef DAY1_HPP
#define DAY1_HPP

#include <string>
#include <vector>
#include "day.hpp"

class Day1: public Day 
{
    public: 
        Day1(const std::string &fileName);
        void init() override;
        unsigned int execute()override;
    
    private:
        const std::string fileName;
        std::vector<std::string> input;       

};

#endif