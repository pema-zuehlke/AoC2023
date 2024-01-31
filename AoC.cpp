#include <iostream>

#include "common/common.hpp"
#include "exercises/day.hpp"
#include "exercises/day1.hpp"


using namespace std;

int main(int argc, char *argv[])
{   
    Day* exercise = new Day1;
    
    exercise->init();
    exercise->execute();
    
    cin.get();
}