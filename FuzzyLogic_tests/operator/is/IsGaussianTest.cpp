#include "gtest/gtest.h"
#include "core/ValueModel.h"
#include "operator/is/IsGaussian.h"

using namespace fuzzyLogic::core;
using namespace fuzzyLogic::core::op;

class IsGaussianTestSuite : public ::testing::Test{
protected:
    void SetUp() override{
        sut = new IsGaussian<double>(-1, 0, 1);
        val1 = new ValueModel<double>(0);
        val3 = new ValueModel<double>(std::numeric_limits< double >::max()); // infini
        val4 = new ValueModel<double>(-(std::numeric_limits< double >::max())); // -infini
    }

    void TearDown() override{
        delete sut;
        delete val1;
        delete val3;
        delete val4;
    }

    IsGaussian<double>* sut;
    ValueModel<double> *val1;
    ValueModel<double> *val3;
    ValueModel<double> *val4;
};


TEST_F(IsGaussianTestSuite, fonctionnalTest){
    // valeur max de la cloche (atteinte en x=0)
    EXPECT_EQ(*sut->evaluate(val1),-1.0);

    // y = 0, x -> +fini
    EXPECT_EQ(*sut->evaluate(val3),0);

    // y = 0, x -> -fini
    EXPECT_EQ(*sut->evaluate(val4),0);
}

TEST_F(IsGaussianTestSuite, exceptionTest){
    // test NullOperatorException pour  x = nullptr
    EXPECT_THROW( *sut->evaluate(nullptr), NullOperatorException);

    // test NullParameterException (Deviation==0)
    sut->setDeviation(0);
    EXPECT_THROW( *sut->evaluate(val1), NullParameterException);
}