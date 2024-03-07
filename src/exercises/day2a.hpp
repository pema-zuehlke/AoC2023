#ifndef DAY2A_HPP
#define DAY2A_HPP

#include <string>
#include <vector>
#include "IDay.hpp"

class Day2a: public IDay 
{
    public: 
        explicit Day2a(const std::string &fileName, unsigned int expectedR, unsigned int expectedG, unsigned int expectedB);
        void init() override;
        unsigned int execute()override;
    
    private:
        bool validateInput(const unsigned int &value, const std::string &color);
    private:
        const std::string fileName;
        std::vector<std::string> input;       

        unsigned int expectedR;
        unsigned int expectedG;
        unsigned int expectedB;

};

#endif