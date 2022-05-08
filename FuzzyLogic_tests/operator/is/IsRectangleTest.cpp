#include "gtest/gtest.h"
#include "core/ValueModel.h"
#include "operator/is/IsRectangle.h"

using namespace fuzzyLogic::core;
using namespace fuzzyLogic::core::op;

class IsRectangleTestSuite : public ::testing::Test{
protected:
    void SetUp() override{
        sut = new IsRectangle<double>(0.25,0.75);
        val1 = new ValueModel<double>(0.1);
        val2 = new ValueModel<double>(0.5);
        val3 = new ValueModel<double>(0.9);
    }

    void TearDown() override{
        delete sut;
        delete val1;
        delete val2;
        delete val3;
    }

    IsRectangle<double> *sut;
    ValueModel<double> *val1;
    ValueModel<double> *val2;
    ValueModel<double> *val3;

};

TEST_F(IsRectangleTestSuite, nullptrTest){
    EXPECT_EQ(sut->evaluate(nullptr),nullptr);
}

TEST_F(IsRectangleTestSuite, fonctionnalTest){
    EXPECT_EQ(*sut->evaluate(val1),0);
    EXPECT_EQ(*sut->evaluate(val2),1);
    EXPECT_EQ(*sut->evaluate(val3),0);
}