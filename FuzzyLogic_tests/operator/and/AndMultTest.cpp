#include "gtest/gtest.h"
#include "core/ValueModel.h"
#include "operator/and/AndMult.h"

using namespace fuzzyLogic::core;
using namespace fuzzyLogic::core::op;

class AndMultTestSuite : public ::testing::Test{
protected:
    void SetUp() override{
        double1 = new double(0.42);
        val1 = new ValueModel<double>();
        val1->setValue(double1);
        double2 = new double(0.69);
        val2 = new ValueModel<double>();
        val2->setValue(double2);
        sut = new AndMult<double>();
    }

    void TearDown() override{
        delete double1;
        delete double2;
        delete val1;
        delete val2;
        delete sut;
    }

    double* double1,*double2;
    ValueModel<double>* val1;
    ValueModel<double>* val2;
    AndMult<double>* sut;
};

TEST_F(AndMultTestSuite, evaluateTestNull){
    EXPECT_EQ(sut->evaluate(val1, nullptr), nullptr);
    EXPECT_EQ(sut->evaluate(nullptr,val2), nullptr);
}

TEST_F(AndMultTestSuite, evaluateTestMult){
    EXPECT_EQ(*sut->evaluate(val1, val2), *val1->evaluate() * *val2->evaluate());
}
