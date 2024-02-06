#ifndef DAY1B_HPP
#define DAY1B_HPP

#include <string>
#include <vector>
#include "day.hpp"

class Day1b: public Day 
{
    public: 
        explicit Day1b(const std::string &fileName);
        void init() override;
        unsigned int execute()override;
    
    private:
        const std::string fileName;
        std::vector<std::string> input;       

};

#endif