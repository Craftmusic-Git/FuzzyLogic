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

TEST_F()