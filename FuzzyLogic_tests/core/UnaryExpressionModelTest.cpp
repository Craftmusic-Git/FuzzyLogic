#include "gtest/gtest.h"
#include "core/UnaryExpressionModel.h"
#include "core/ValueModel.h"

using namespace fuzzyLogic::core;

class UnaryExpressionModelTestSuite : public ::testing::Test {

protected:
    void SetUp() override
    {
        sut = new UnaryExpressionModel<int>();
        value = new ValueModel<int>();
    }

    void TearDown() override
    {
        delete value;
        delete sut;
    }

    ValueModel<int>* value;
    UnaryExpressionModel<int>* sut;
};

TEST_F(UnaryExpressionModelTestSuite, evaluateWithoutOperand){
    ASSERT_EQ(sut->evaluate(), nullptr);
}

TEST_F(UnaryExpressionModelTestSuite, evaluateWithoutOperator){
    ASSERT_EQ(sut->evaluate(value), nullptr);
}

TEST_F(UnaryExpressionModelTestSuite, getSetOperand){
    sut->setOperand(value);
    ASSERT_EQ(sut->getOperand(),value);
}

TEST_F(UnaryExpressionModelTestSuite, evaluateWithOperand){
    int* val = new int();
    value->setValue(val);
    sut->setOperand(value);
    EXPECT_EQ(sut->getOperand()->evaluate(),value->evaluate());
    EXPECT_EQ(sut->evaluate(), nullptr);
    delete val;
}

TEST_F(UnaryExpressionModelTestSuite, getSetOperator){
    auto* unaryExpression = new UnaryExpressionModel<int>();
    sut->setOperator(unaryExpression);
    EXPECT_EQ(sut->getOperator(),unaryExpression);
    delete unaryExpression;
}