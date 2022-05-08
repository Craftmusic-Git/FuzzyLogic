#include "gtest/gtest.h"
#include "core/ValueModel.h"
#include "operator/agg/AggPlus.h"

using namespace fuzzyLogic::core;
using namespace fuzzyLogic::core::op;

class AggPlusTestSuite : public ::testing::Test{
protected:
    void SetUp() override{
        sut = new AggPlus<double>();
        val1 = new ValueModel<double>(0.42);
        val2 = new ValueModel<double>(0.55);
    }
    void TearDown() override{
        delete sut;
        delete val1;
        delete val2;
    }

    AggPlus<double>* sut;
    ValueModel<double>* val1;
    ValueModel<double>* val2;
};

TEST_F(AggPlusTestSuite, nullptrTest){
    EXPECT_EQ(sut->evaluate(nullptr, nullptr), nullptr);
    EXPECT_EQ(sut->evaluate(val1, nullptr), nullptr);
    EXPECT_EQ(sut->evaluate(nullptr,val2), nullptr);
}

TEST_F(AggPlusTestSuite, AggFonctionalTest){
    EXPECT_EQ(*sut->evaluate(val1,val2), *val2->evaluate() + *val1->evaluate());
}