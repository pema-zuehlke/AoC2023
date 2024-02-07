#include <iostream>

#include "common/common.hpp"
#include "exercises/day.hpp"

using namespace std;
constexpr int PARAMETERS_NEEDED = 1;

int main(int argc, char *argv[])
{   
    std::string nameOfDay = std::string(argv[1]);
    
    if(argc != PARAMETERS_NEEDED + 1)
    {
        //do not have the correct parameters
        log("Wrong number of parameters. expected:" << PARAMETERS_NEEDED << " received:" << (argc-1));
        return -1; 
    }

    Day* exercise = ManageInput::daySearch(nameOfDay);

    if(exercise == nullptr)
    {
        //day is not implemented
        log("Day passed as parameter (" << nameOfDay << ") still not implemented");
        return -2;
    }
    exercise->init();
    
    log("Return value is:" << exercise->execute());
    delete exercise;
    return 0;
}

