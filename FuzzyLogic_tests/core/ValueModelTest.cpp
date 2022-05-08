#include "gtest/gtest.h"
#include "core/ValueModel.h"

using namespace fuzzyLogic::core;

class ValueModelTestSuite : public ::testing::Test{

protected:
    void SetUp() override
    {
        sut = new ValueModel<int>();
    }

    void TearDown() override
    {
        delete sut;
    }

    ValueModel<int>* sut;
};

TEST_F(ValueModelTestSuite, SetGetTest){
    int* testedValue = new int(42);
    sut->setValue(testedValue);
    EXPECT_EQ(sut->evaluate(),testedValue);
}

TEST_F(ValueModelTestSuite, ConstructorOverchargeTest){
    double value = 12;
    ValueModel<double> *valueTest = new ValueModel<double>(value);
    EXPECT_DOUBLE_EQ(*valueTest->evaluate(),value);
    delete valueTest;
}