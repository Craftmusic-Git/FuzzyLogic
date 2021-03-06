# 'FuzzyLogic_Tests'  subproject name
project(FuzzyLogic_tests)

# 'lib' is the folder with the GoogleTest sources
add_subdirectory(lib)
include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

add_executable(Google_Tests_run
        core/ValueModelTest.cpp
        core/UnaryExpressionModelTest.cpp
        core/BinaryExpressionModelTest.cpp
        operator/and/AndMinTest.cpp
        operator/and/AndMultTest.cpp
        operator/or/OrMaxTest.cpp
        operator/or/OrPlusTest.cpp
        operator/is/IsTriangleTest.cpp
        operator/then/ThenMinTest.cpp
        operator/then/ThenMultTest.cpp
        operator/agg/AggMaxTest.cpp
        operator/agg/AggPlus.cpp
        core/EvaluatorTest.cpp
        operator/not/NotMinus1Test.cpp
        operator/is/IsRectangleTest.cpp
        operator/CogDefuzzTest.cpp
        core/UnaryShadowExpressionTest.cpp
        core/BinaryShadowExpressionTest.cpp core/FuzzyFactoryTest.cpp operator/is/IsTrapezeTest.cpp operator/is/IsSingletonTest.cpp operator/is/IsSigmoidTest.cpp operator/is/IsLinearTest.cpp operator/is/IsGeneralizedBellTest.cpp operator/is/IsGaussianTest.cpp operator/is/IsSigmoidLeft.cpp operator/is/IsSigmoidLeftTest.cpp operator/is/IsTrapezeRightTest.cpp operator/CosDefuzzTest.cpp operator/LomDefuzzTest.cpp operator/FomDefuzzTest.cpp)
target_link_libraries(Google_Tests_run FuzzyLogicFramework)
target_link_libraries(Google_Tests_run gtest gtest_main)
