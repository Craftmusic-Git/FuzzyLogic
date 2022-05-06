#include "gtest/gtest.h"
#include "core/ValueModel.h"
#include "core/BinaryExpressionModel.h"

using namespace fuzzyLogic::core;

class BinaryExpressionModelTestSuite : public ::testing::Test{
protected:

    void SetUp() override
    {
        sut = new BinaryExpressionModel<int>();
        exprTest = new ValueModel<int>();
    }

    void TearDown() override
    {
        delete sut;
        delete exprTest;
    }

    ValueModel<int>* exprTest;
    BinaryExpressionModel<int>* sut;
};

TEST_F(BinaryExpressionModelTestSuite, getSetOperator)
{
    auto* operatorTest = new BinaryExpressionModel<int>();
    sut->setOperator(operatorTest);
    EXPECT_EQ(sut->getOperator(),operatorTest);
    delete operatorTest;
}

TEST_F(BinaryExpressionModelTestSuite, getSetRight)
{
    sut->setRight(exprTest);
    EXPECT_EQ(sut->getRight(),exprTest);
}

TEST_F(BinaryExpressionModelTestSuite, getSetLeft)
{
    sut->setLeft(exprTest);
    EXPECT_EQ(sut->getLeft(),exprTest);
}

TEST_F(BinaryExpressionModelTestSuite, testNulEvaluate){
    EXPECT_EQ(sut->evaluate(), nullptr);
    sut->setLeft(exprTest);
    EXPECT_EQ(sut->evaluate(), nullptr);
    sut->setLeft(nullptr);
    sut->setRight(exprTest);
    EXPECT_EQ(sut->evaluate(), nullptr);
}