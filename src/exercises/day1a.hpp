#ifndef DAY1A_HPP
#define DAY1A_HPP

#include <string>
#include <vector>
#include "IDay.hpp"

class Day1a: public IDay 
{
    public: 
        explicit Day1a(const std::string &fileName);
        void init() override;
        unsigned int execute() override;

        //TODO: Add guards to insert this methods only in test environment
        const std::vector<std::string>& getInput();
        void setInput(const std::vector<std::string>& newInput);

    private:
        const std::string fileName;
        std::vector<std::string> input;
};

#endif