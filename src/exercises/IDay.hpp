#ifndef IDAY_HPP
#define IDAY_HPP

class IDay
{
    public:
        virtual ~IDay() = default;
        virtual void init() = 0;
        virtual unsigned int execute() = 0;
};

#endif