#include "gtest/gtest.h"
#include "core/ValueModel.h"
#include "operator/not/NotMinus1.h"

using namespace fuzzyLogic::core;
using namespace fuzzyLogic::core::op;

class NotMinus1TestSuite : public ::testing::Test{
protected:
    void SetUp() override{
        sut = new NotMinus1<double>();
        valueTest = new ValueModel<double>(0.3);
    }

    void TearDown() override{
        delete sut;
        delete valueTest;
    }

    NotMinus1<double>* sut;
    ValueModel<double>* valueTest;

};

TEST_F(NotMinus1TestSuite, nullptrTest){
    EXPECT_EQ(sut->evaluate(nullptr), nullptr);
}

TEST_F(NotMinus1TestSuite, fonctionnalTest){
    EXPECT_EQ(*sut->evaluate(valueTest),1 - *valueTest->evaluate());
}
