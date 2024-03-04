cmake_minimum_required(VERSION 3.22)



if(${BUILD_CONFIGURATION} STREQUAL "DEFAULT") 
#Create binary
    message("==============================================")
    message("Generating configuration to generate Executable")
    message("==============================================")
 
    set(CPACK_PROJECT_NAME ${PROJECT_NAME})
    set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
    include(CPack)
    
    project(AoC2023 VERSION 0.1.0 LANGUAGES C CXX) 
    set(CMAKE_CXX_STANDARD 17)

    add_executable(${PROJECT_NAME}  src/AoC.cpp 
                src/common/common.cpp
                src/exercises/day1a.cpp
                src/exercises/day1b.cpp
                src/exercises/day2a.cpp
                src/exercises/day2b.cpp)
    
    target_include_directories(${PROJECT_NAME}  PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

    set(BASE_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/input)
    set(EXTENSION .txt)
    configure_file(config/config.hpp.in ${CMAKE_CURRENT_SOURCE_DIR}/config/config.hpp)

elseif(${BUILD_CONFIGURATION} STREQUAL "GTEST")
    message("==============================================")
    message("Generating configuration to run Tests")
    message("==============================================")
    
    project(AoC2023_GTest LANGUAGES CXX)
    set(CMAKE_CXX_STANDARD 14)

    include(FetchContent)
    FetchContent_Declare(
            googletest
            GIT_REPOSITORY https://github.com/google/googletest.git
            GIT_TAG        main 

    )
    FetchContent_MakeAvailable(googletest)

    set(CMAKE_THREAD_LIBS_INIT "-lpthread")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14 -g -Wall -pthread -ftest-coverage -fprofile-arcs")
    set(CMAKE_CXX_OUTPUT_EXTENSION_REPLACE ON)

    set(CMAKE_HAVE_THREADS_LIBRARY 1)
    set(CMAKE_USE_WIN32_THREADS_INIT 0)
    set(CMAKE_USE_PTHREADS_INIT 1)
    set(THREADS_PREFER_PTHREAD_FLAG ON)

    # Create OBJECT_DIR variable 
    set(OBJECT_DIR ${CMAKE_BINARY_DIR}/CMakeFiles/${PROJECT_NAME}.dir)

    add_executable(${PROJECT_NAME} 
                    src/exercises/day1a.cpp
                    src/exercises/day1b.cpp
                    src/exercises/day2a.cpp
                    src/exercises/day2b.cpp
                    src/common/common.cpp
                    unitTests/testDay1a.cpp
                    unitTests/testDay1b.cpp
                    unitTests/testDay2a.cpp
                    unitTests/testDay2b.cpp
                )
    target_link_libraries(${PROJECT_NAME} gtest_main gmock_main)

    target_include_directories(${PROJECT_NAME} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

    include(GoogleTest)
    gtest_discover_tests(${PROJECT_NAME})

    include_directories(../googletest/googletest/include)

    # Generate code coverage
    message("Generating Code coverage")
    message("==============================================")

    find_program(GCOV_PATH gcov REQUIRED)
    find_program(LCOV_PATH lcov REQUIRED)
    find_program(GENHTML_PATH genhtml REQUIRED)

    add_custom_target(gcov
        COMMAND mkdir -p gcoverage
        COMMAND ${CMAKE_MAKE_PROGRAM} ${PROJECT_NAME}
        WORKING_DIRECTORY ${CMAKE_BINARY_DIR}
        )

    add_custom_command(TARGET gcov
        COMMAND echo "=================== GCOV ===================="
        COMMAND echo "${GCOV_PATH} -b ${CMAKE_SOURCE_DIR}/exercises/*.cpp -o ${OBJECT_DIR}/exercises"
        COMMAND echo "${GCOV_PATH} -b ${CMAKE_SOURCE_DIR}/common/*.cpp -o ${OBJECT_DIR}/common"

        #COMMAND ${GCOV_PATH} -b ${CMAKE_SOURCE_DIR}/exercises/*.cpp -o ${OBJECT_DIR}/exercises
        #COMMAND ${GCOV_PATH} -b ${CMAKE_SOURCE_DIR}/common/*.cpp -o ${OBJECT_DIR}/common

        COMMAND echo "-- Coverage files have been output to ${CMAKE_BINARY_DIR}/gcoverage"
        WORKING_DIRECTORY ${CMAKE_BINARY_DIR}/gcoverage
        )

    add_dependencies(gcov ${PROJECT_NAME})

    add_custom_target(lcov
        COMMAND mkdir -p lcoverage
        )

    add_custom_command(TARGET lcov
        COMMAND echo "=================== LCOV ===================="
        COMMAND echo "-- Passing lcov tool under code coverage"
        COMMAND lcov --capture --directory ${OBJECT_DIR} --output-file lcoverage/main_coverage.info -b .
        COMMAND echo "-- Remove undesired files from main_coverage"
        COMMAND lcov --remove lcoverage/main_coverage.info '*/usr/include/*' '*/gtest/*' -o lcoverage/filtered_coverage.info
        COMMAND echo "-- Generating HTML output files"
        COMMAND genhtml lcoverage/filtered_coverage.info --output-directory lcoverage
        WORKING_DIRECTORY ${CMAKE_BINARY_DIR}
        )


endif()

set(BASE_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/input/)
set(EXTENSION .txt)
configure_file(config/config.hpp.in ${CMAKE_CURRENT_SOURCE_DIR}/config/config.hpp)




