#include "gtest/gtest.h"
#include "core/ValueModel.h"
#include "operator/is/IsLinear.h"

using namespace fuzzyLogic::core;
using namespace fuzzyLogic::core::op;

class IsLinearTestSuite : public ::testing::Test{
protected:
    void SetUp() override{
        sut = new IsLinear<double>(2,3);
        val1 = new ValueModel<double>(0);
        val2 = nullptr; // test nullPointerException
        val3 = new ValueModel<double>(std::numeric_limits< double >::max()); // infini
        val4 = new ValueModel<double>(-(std::numeric_limits< double >::max())); // -infini
    }

    void TearDown() override{
        delete sut;
        delete val1;
        delete val2;
        delete val3;
        delete val4;
    }

    IsLinear<double>* sut;
    ValueModel<double> *val1;
    ValueModel<double> *val2;
    ValueModel<double> *val3;
    ValueModel<double> *val4;
};


TEST_F(IsLinearTestSuite, fonctionnalTest) {
    // si x=0 alors y = b
    EXPECT_EQ(*sut->evaluate(val1), 3.0);

    //si a > 0 alors y -> +infini, x->infini
    EXPECT_GT(*sut->evaluate(val3),std::numeric_limits<double>::max());

    //si a > 0 alors y -> -infini, x->-infini
    EXPECT_LT(*sut->evaluate(val4),-(std::numeric_limits<double>::max()));

    //si a < 0 alors y -> -infini, x->infini
    sut->setA(-2);
    EXPECT_LT(*sut->evaluate(val3),-(std::numeric_limits<double>::max()));

    //si a > 0 alors y -> infini, x->-infini
    EXPECT_GT(*sut->evaluate(val4),std::numeric_limits<double>::max());

    //si a==0 alors y = b
    sut->setA(0);
    EXPECT_EQ(*sut->evaluate(val1), 3.0);

    //si a==0 alors y = b, x->infini
    EXPECT_EQ(*sut->evaluate(val3), 3.0);

    //si a==0 alors y = b, x->-infini
    EXPECT_EQ(*sut->evaluate(val4),3.0);

    //test des méthodes set
    sut->setA(2);
    sut->setB(0);
    EXPECT_EQ(*sut->evaluate(val1),0);

}

TEST_F(IsLinearTestSuite, exceptionTest){
    EXPECT_THROW( *sut->evaluate(nullptr), NullOperatorException);
}
