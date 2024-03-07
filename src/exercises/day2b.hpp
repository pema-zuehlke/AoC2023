#ifndef DAY2B_HPP
#define DAY2B_HPP

#include <string>
#include <vector>
#include "IDay.hpp"

class Day2b: public IDay 
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

        unsigned int maxR = 0;
        unsigned int maxG = 0;
        unsigned int maxB = 0;

};

#endif