#include "gtest/gtest.h"
#include "core/UnaryExpressionModel.h"
#include "core/ValueModel.h"
#include "core/UnaryShadowExpression.h"

using namespace fuzzyLogic::core;

class UnaryShadowExpressionTestSuite : public ::testing::Test{

protected:
    void SetUp() override
    {
        expr = new UnaryExpressionModel<int>();
        value = new ValueModel<int>();
        sut = new UnaryShadowExpression<int>();
        expr->setOperand(value);
    }

    void TearDown() override
    {
        delete value;
        delete expr;
        delete sut;
    }

    UnaryShadowExpression<int>* sut;
    ValueModel<int>* value;
    UnaryExpressionModel<int>* expr;
};

TEST_F(UnaryShadowExpressionTestSuite, nullExecute){
    EXPECT_EQ(nullptr, sut->evaluate(nullptr));
}

TEST_F(UnaryShadowExpressionTestSuite, setGetTargetTest){
    EXPECT_EQ(sut->getTarget(), nullptr);
    sut->setTarget(expr);
    EXPECT_EQ(sut->getTarget(),expr);
}

TEST_F(UnaryShadowExpressionTestSuite, executionTest){
    EXPECT_EQ(sut->evaluate(value),expr->evaluate(value));
    sut->setTarget(expr);
    expr->setOperand(value);
    EXPECT_EQ(sut->evaluate(expr),expr->evaluate());
}