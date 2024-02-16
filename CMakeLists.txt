cmake_minimum_required(VERSION 3.0.0)
project(AoC2023 VERSION 0.1.0 LANGUAGES C CXX)

#include(CTest)
#enable_testing()

if(${BUILD_CONFIGURATION} STREQUAL "DEFAULT") 
#Create binary
    add_executable(AoC2023 AoC.cpp 
                common/common.cpp
                exercises/day1a.cpp
                exercises/day1b.cpp
                exercises/day2a.cpp
                exercises/day2b.cpp)
elseif(${BUILD_CONFIGURATION} STREQUAL "GTEST")
    message("Test config generated on CMakeList")
    
endif()


set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)


