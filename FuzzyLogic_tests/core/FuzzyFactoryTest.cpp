#include "gtest/gtest.h"
#include "FuzzyLogic.h"

#include <iostream>

using namespace fuzzyLogic::core;
using namespace fuzzyLogic::core::op;

class FuzzyFactoryTestSuite : public ::testing::Test{

protected:
    void SetUp() override{
        opNot = new NotMinus1<double>();
        opAnd = new AndMin<double>();
        opOr = new OrMax<double>();
        opThen = new ThenMin<double>();
        opDefuzz = new CogDefuzz<double>(start, end, step);
        opAgg = new AggMax<double>();
        sut = new FuzzyFactory<double>(opNot,opAnd,opOr,opThen,opAgg,opDefuzz);
    }

    void TearDown() override{
        delete sut;
        delete opNot;
        delete opAnd;
        delete opOr;
        delete opThen;
        delete opAgg;
        delete opDefuzz;
    }

    FuzzyFactory<double>* sut;
    NotMinus1<double>* opNot;
    AndMin<double>* opAnd;
    OrMax<double>* opOr;
    AggMax<double>* opAgg;
    ThenMin<double>* opThen;
    CogDefuzz<double>* opDefuzz;

    const double start = 0;
    const double end = 10;
    const double step = 0.01;
};

TEST_F(FuzzyFactoryTestSuite, SimpleEvaluation){
    Expression<double> *r = sut->newNot(sut->newValue(0.3));
    Expression<double> *system = sut->newDefuzz(new ValueModel<double>(0.5), r, start, end, step);
    bool test;
    if(4.999999999< *system->evaluate() < 5.00000001)
        test = true;
    EXPECT_EQ(true,test);
}

TEST_F(FuzzyFactoryTestSuite, CompleteExemple) {
    //membership function
    IsTriangle<double> poor(-5, 0, 5);
    IsTriangle<double> good(0, 5, 10);
    IsTriangle<double> excellent(5, 10, 15);

    IsTriangle<double> cheap(0, 5, 10);
    IsTriangle<double> average(10, 15, 20);
    IsTriangle<double> generous(20, 25, 30);

    //values
    ValueModel<double> service(.0);
    ValueModel<double> food(0);
    ValueModel<double> tips(0);

    Expression<double> *r =
            sut->newAgg(
                    sut->newAgg(
                            sut->newThen(
                                    sut->newIs(&service, &poor),
                                    sut->newIs(&tips, &cheap)
                            ),
                            sut->newThen(
                                    sut->newIs(&service, &good),
                                    sut->newIs(&tips, &average)
                            )
                    ),
                    sut->newThen(
                            sut->newIs(&service, &excellent),
                            sut->newIs(&tips, &generous)
                    )
            );

    //defuzzification
    Expression<double> *system = sut->newDefuzz(&tips, r, 0, 25, 1);
    EXPECT_NO_THROW(system->evaluate());
}