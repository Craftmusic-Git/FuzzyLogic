#include "gtest/gtest.h"
#include "core/ValueModel.h"
#include "core/BinaryShadowExpression.h"
#include "core/BinaryExpressionModel.h"
#include "operator/and/AndMin.h"

using namespace fuzzyLogic::core;

class BinaryShadowExpressionTestSuite : public ::testing::Test{

protected:
    void SetUp() override
    {
        expr = new BinaryExpressionModel<int>();
        sut = new BinaryShadowExpression<int>();
        left = new ValueModel<int>(10);
        right = new ValueModel<int>(30);
        op = new op::AndMin<int>();
    }

    void TearDown() override
    {
        delete left;
        delete right;
        delete expr;
        delete sut;
        delete op;
    }

    BinaryShadowExpression<int>* sut;
    ValueModel<int>* left;
    ValueModel<int>* right;
    op::AndMin<int>* op;
    BinaryExpressionModel<int>* expr;
};

TEST_F(BinaryShadowExpressionTestSuite, GetSetTest){
    EXPECT_EQ(sut->getTarget(), nullptr);
    sut->setTarget(expr);
    EXPECT_EQ(sut->getTarget(),expr);
}