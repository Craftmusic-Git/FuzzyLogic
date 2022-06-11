#include "gtest/gtest.h"
#include "core/ValueModel.h"
#include "operator/is/IsTriangle.h"

using namespace fuzzyLogic::core;
using namespace fuzzyLogic::core::op;

class IsTriangleTestSuite : public ::testing::Test{
protected:
    void SetUp() override{
        sut = new IsTriangle<double>(0.25,0.5,0.75);
        val1 = new ValueModel<double>(0.1);
        val2 = new ValueModel<double>(0.5);
        val3 = new ValueModel<double>(0.625);
    }

    void TearDown() override{
        delete sut;
        delete val1;
        delete val2;
        delete val3;
    }

    IsTriangle<double> *sut;
    ValueModel<double> *val1;
    ValueModel<double> *val2;
    ValueModel<double> *val3;

};

TEST_F(IsTriangleTestSuite, nullptrTest){
    EXPECT_THROW( *sut->evaluate(nullptr), NullOperatorException);
}

TEST_F(IsTriangleTestSuite, SimpleValueTest){
    EXPECT_DOUBLE_EQ(*sut->evaluate(val1),0);
    EXPECT_DOUBLE_EQ(*sut->evaluate(val2),1);
    EXPECT_DOUBLE_EQ(*sut->evaluate(val3),0.5);
}