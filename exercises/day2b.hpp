#ifndef DAY2B_HPP
#define DAY2B_HPP

#include <string>
#include <vector>
#include "day.hpp"

class Day2b: public Day 
{
    public: 
        explicit Day2b(const std::string &fileName);
        void init() override;
        unsigned int execute()override;
    
    private:
        void validateInput(const unsigned int &value, const std::string &colour);
        void addValue(unsigned int value, 
                    const std::string &colour, 
                    unsigned int &roundR, 
                    unsigned int &roundG, 
                    unsigned int &roundB);
    private:
        const std::string fileName;
        std::vector<std::string> input;       

        unsigned int maxR;
        unsigned int maxG;
        unsigned int maxB;

};

#endif