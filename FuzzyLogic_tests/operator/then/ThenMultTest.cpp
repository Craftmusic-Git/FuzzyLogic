#include "gtest/gtest.h"
#include "operator/then/ThenMult.h"
#include "core/ValueModel.h"

using namespace fuzzyLogic::core;
using namespace fuzzyLogic::core::op;

class ThenMultTestSuite : public ::testing::Test{
protected:
    void SetUp() override {
        sut = new ThenMult<double>();
        val1 = new ValueModel<double>(0.42);
        val2 = new ValueModel<double>(0.55);
    }

    void TearDown() override{
        delete sut;
        delete val1;
        delete val2;
    }

    ThenMult<double>* sut;
    ValueModel<double>* val1;
    ValueModel<double>* val2;
};

TEST_F(ThenMultTestSuite, nullptrTest){
    EXPECT_EQ(sut->evaluate(nullptr, nullptr), nullptr);
    EXPECT_EQ(sut->evaluate(val1, nullptr), nullptr);
    EXPECT_EQ(sut->evaluate(nullptr,val2), nullptr);
}

TEST_F(ThenMultTestSuite, thenTestCase){
    EXPECT_EQ(*sut->evaluate(val1,val2),*val1->evaluate() * *val2->evaluate());
}