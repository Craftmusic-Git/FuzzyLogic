#include "gtest/gtest.h"
#include "core/ValueModel.h"
#include "core/Evaluator.h"
#include "operator/CosDefuzz.h"
#include "operator/is/IsRectangle.h"
#include "core/UnaryExpressionModel.h"

using namespace fuzzyLogic::core;
using namespace fuzzyLogic::core::op;

class CosDefuzzTestSuite : public ::testing::Test{
protected:
    void SetUp() override{
        sut = new CosDefuzz<double>(0,10,0.1);
        rectangle = new IsRectangle<double>(2.5,7.5);
        val1 = new ValueModel<double>(0.45);
        val2 = new ValueModel<double>(0.55);
        unaryExpr = new UnaryExpressionModel<double>();
    }

    void TearDown() override{
        delete sut;
        delete val1;
        delete val2;
        delete unaryExpr;
    }

    CosDefuzz<double>* sut;
    IsRectangle<double>* rectangle;
    ValueModel<double>* val1;
    ValueModel<double>* val2;
    UnaryExpressionModel<double>* unaryExpr;
};

TEST_F(CosDefuzzTestSuite, nullptrTest){
    EXPECT_EQ(sut->evaluate(nullptr, nullptr), nullptr);
    EXPECT_EQ(sut->evaluate(val1, nullptr), nullptr);
    EXPECT_EQ(sut->evaluate(nullptr,val2), nullptr);
}

TEST_F(CosDefuzzTestSuite, validationTest){
    unaryExpr->setOperand(val1);
    unaryExpr->setOperator(rectangle);
    bool test = false;
    if(4.999999999< *sut->evaluate(val1,unaryExpr) < 5.00000001)
        test = true;
    EXPECT_EQ(true,test);
}

