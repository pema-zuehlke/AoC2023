#ifndef DAY1A_HPP
#define DAY1A_HPP

#include <string>
#include <vector>
#include "day.hpp"

class Day1a: public Day 
{
    public: 
        explicit Day1a(const std::string &fileName);
        void init() override;
        unsigned int execute()override;
    
    private:
        const std::string fileName;
        std::vector<std::string> input;       

};

#endif