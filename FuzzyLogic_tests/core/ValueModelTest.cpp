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
    int testedValue = 42;
    sut->setValue(testedValue);
    EXPECT_EQ(sut->evaluate(),testedValue);
}