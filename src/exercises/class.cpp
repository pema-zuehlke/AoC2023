#include <iostream>
#include "class.hpp"


TestClass::TestClass()
{
    std::cout << "class created" << std::endl ;
}

TestClass::~TestClass()
{
    std::cout << "class destructed" << std::endl ;
}

int TestClass::sum(int a, int b)
{
    return a + b;
}