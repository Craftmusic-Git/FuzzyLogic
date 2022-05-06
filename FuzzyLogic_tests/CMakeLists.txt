# 'FuzzyLogic_Tests'  subproject name
project(FuzzyLogic_tests)

# 'lib' is the folder with the GoogleTest sources
add_subdirectory(lib)
include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

add_executable(Google_Tests_run core/ValueModelTest.cpp core/UnaryExpressionModelTest.cpp core/BinaryExpressionModelTest.cpp)
target_link_libraries(Google_Tests_run FuzzyLogicFramework)
target_link_libraries(Google_Tests_run gtest gtest_main)
