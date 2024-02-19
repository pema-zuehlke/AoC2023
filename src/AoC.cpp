#include <iostream>

#include "common/common.hpp"
#include "exercises/day.hpp"

using namespace std;
constexpr int PARAMETERS_NEEDED = 1;

int main(int argc, char *argv[])
{   
    
    std::string nameOfDay;
    if(argc != PARAMETERS_NEEDED + 1)
    {
        //do not have the correct parameters
        log("Parameters not properly selected (expected:" << PARAMETERS_NEEDED << " received:" << (argc-1) << ") assume day1a");
        
        nameOfDay = "day1a";
    }
    else
    {
        nameOfDay = std::string(argv[1]);
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