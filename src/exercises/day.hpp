#ifndef DAY_HPP
#define DAY_HPP

class Day
{
    public:
        virtual ~Day() = default;
        virtual void init() = 0;
        virtual unsigned int execute() = 0;
};

#endif