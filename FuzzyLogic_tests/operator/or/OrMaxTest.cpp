#include "gtest/gtest.h"
#include "operator/or/OrMax.h"
#include "core/ValueModel.h"

using namespace fuzzyLogic::core;
using namespace fuzzyLogic::core::op;

class OrMaxTestSuite : public ::testing::Test{
protected:
    void SetUp() override{
        double1 = new double(0.42);
        val1 = new ValueModel<double>();
        val1->setValue(double1);
        double2 = new double(0.69);
        val2 = new ValueModel<double>();
        val2->setValue(double2);
        sut = new OrMax<double>();
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
    OrMax<double>* sut;
};

TEST_F(OrMaxTestSuite, evaluateTestNull){
    EXPECT_EQ(sut->evaluate(val1, nullptr), nullptr);
    EXPECT_EQ(sut->evaluate(nullptr,val2), nullptr);
}

TEST_F(OrMaxTestSuite, evaluateTest){
    EXPECT_EQ(sut->evaluate(val1,val2),val2->evaluate());
    ASSERT_EQ(*sut->evaluate(val2,val1),*val2->evaluate());
}