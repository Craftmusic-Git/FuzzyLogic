cmake_minimum_required(VERSION 3.21)
project(FuzzyLogic)

set(CMAKE_CXX_STANDARD 20)

include_directories(FuzzyLogic_framework)
add_subdirectory(FuzzyLogic_framework)

# Framework de test
add_subdirectory(FuzzyLogic_tests)

