#include "gtest/gtest.h"
#include "core/ValueModel.h"
#include "core/Evaluator.h"
#include "operator/is/IsTriangle.h"
#include "operator/agg/AggPlus.h"
#include "operator/is/IsRectangle.h"
#include "core/BinaryExpressionModel.h"
#include "core/UnaryExpressionModel.h"

using namespace fuzzyLogic::core;
using namespace fuzzyLogic::core::op;

class EvaluatorTestSuite : public ::testing::Test{
protected:
    typedef std::pair<std::vector<double>*, std::vector<double>*> Shape;

    void SetUp() override{
        sut = new Evaluator<double>();
        min = new double(0);
        max = new double(10);
        step = new double(0.05);
        simpleValue = new ValueModel<double>();
        triangle = new IsTriangle<double>(-1,0,1);
        val1 = new ValueModel<double>(0.45);
        val2 = new ValueModel<double>(0.55);
        aggPlus = new AggPlus<double>();
        rectangle = new IsRectangle<double>(-1,1);
        binExpr = new BinaryExpressionModel<double>();
        unaryExpr = new UnaryExpressionModel<double>();
    }

    void TearDown() override{
        delete sut;
        delete min;
        delete max;
        delete step;
        delete simpleValue;
        delete triangle;
        delete aggPlus;
        delete val1;
        delete val2;
        delete rectangle;
        delete unaryExpr;
    }
    Evaluator<double>* sut;
    double* min, *max, *step;
    ValueModel<double>* simpleValue;
    IsTriangle<double>* triangle;
    AggPlus<double>* aggPlus;
    ValueModel<double>* val1;
    ValueModel<double>* val2;
    IsRectangle<double>* rectangle;
    BinaryExpressionModel<double>* binExpr;
    UnaryExpressionModel<double>* unaryExpr;
};

TEST_F(EvaluatorTestSuite, nullBuildShapeTest){
    EXPECT_EQ(Shape(nullptr, nullptr),*sut->buildShape(nullptr, nullptr, nullptr, nullptr, nullptr));
}

TEST_F(EvaluatorTestSuite, simpleEvaluatorTest){
    binExpr->setOperator(aggPlus);
    binExpr->setLeft(val1);
    binExpr->setRight(val2);
    Shape* shape = sut->buildShape(min,max, step,simpleValue,binExpr);
    double xTest = *min;
    double resultTest = *val1->evaluate() + *val2->evaluate();
    for(auto x : *shape->first){
        EXPECT_EQ(x,xTest);
        xTest += *step;
    }
    for(auto y : *shape->second){
            EXPECT_EQ(y, resultTest);
    }
}

TEST_F(EvaluatorTestSuite, complexeTestEvaluation){
    unaryExpr->setOperator(rectangle);
    unaryExpr->setOperand(simpleValue);
    Shape* shape = sut->buildShape(min,max,step,simpleValue, unaryExpr);
    double xTest = *min;
    for(auto x : *shape->first){
        EXPECT_EQ(x,xTest);
        xTest += *step;
    }
}