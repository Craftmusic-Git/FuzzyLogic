#include "gtest/gtest.h"
#include "core/ValueModel.h"
#include "operator/is/IsGeneralizedBell.h"
#include <limits>

using namespace fuzzyLogic::core;
using namespace fuzzyLogic::core::op;

class IsGeneralizedBellTestSuite : public ::testing::Test{
protected:
    void SetUp() override{
        sut = new IsGeneralizedBell<double>(2, 3, 1);
        val1 = new ValueModel<double>(3);
        val3 = new ValueModel<double>(std::numeric_limits< double >::max()); // infini
        val4 = new ValueModel<double>(-(std::numeric_limits< double >::max())); // -infini
    }

    void TearDown() override{
        delete sut;
        delete val1;
        delete val3;
        delete val4;
    }

    IsGeneralizedBell<double>* sut;
    ValueModel<double> *val1;
    ValueModel<double> *val3;
    ValueModel<double> *val4;
};


TEST_F(IsGeneralizedBellTestSuite, fonctionnalTest){
    // valeur max de la cloche (atteinte en x=3)
    EXPECT_EQ(*sut->evaluate(val1),1.0);

    // y = 0, x-> +infini
    EXPECT_EQ(*sut->evaluate(val3),0);

    // y = 0, x-> -infini
    EXPECT_EQ(*sut->evaluate(val4),0);

    // si lope < 0 alors y = 1, x->infini
    sut->setSlope(-1);
    EXPECT_EQ(*sut->evaluate(val3),1.0);

    // si lope < 0 alors y = 1, x->-infini
    sut->setSlope(-1);
    EXPECT_EQ(*sut->evaluate(val4),1.0);
}

TEST_F(IsGeneralizedBellTestSuite, exceptionTest){
    // test NullOperatorException pour x = nullptr
    EXPECT_THROW( *sut->evaluate(nullptr), NullOperatorException);

    // test NullParameterException (SetHalfWidth==0)
    sut->setHalfWidth(0);
    EXPECT_THROW( *sut->evaluate(val1), NullParameterException);
}

