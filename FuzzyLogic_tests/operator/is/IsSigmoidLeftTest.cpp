#include "gtest/gtest.h"
#include "core/ValueModel.h"
#include "operator/is/IsTrapezeLeft.h"

using namespace fuzzyLogic::core;
using namespace fuzzyLogic::core::op;

class IsTrapezeLeftTestSuite : public ::testing::Test{
protected:
    void SetUp() override{
        sut = new IsTrapezeLeft<double>(0,2);
        val1 = new ValueModel<double>(1);
        val3 = new ValueModel<double>(std::numeric_limits< double >::max()); // infini
        val4 = new ValueModel<double>(-(std::numeric_limits< double >::max())); // -infini
    }

    void TearDown() override{
        delete sut;
        delete val1;
        delete val3;
        delete val4;
    }

    IsTrapezeLeft<double>* sut;
    ValueModel<double> *val1;
    ValueModel<double> *val3;
    ValueModel<double> *val4;
};

TEST_F(IsTrapezeLeftTestSuite, fonctionnalTest){
    // verification de la valeur mi-descente
    EXPECT_EQ(*sut->evaluate(val1),0.5);

    // y = 0, x-> +infini
    EXPECT_EQ(*sut->evaluate(val3),0);

    // y = 1, x-> -infini
    EXPECT_EQ(*sut->evaluate(val4),1);
}

TEST_F(IsTrapezeLeftTestSuite, exceptionTest){

    // test NullOperatorException pour x = nullptr
    EXPECT_THROW( *sut->evaluate(nullptr), std::runtime_error);

    // si max == midR alors inconsistentValueException
    sut->setMidRight(2);
    EXPECT_THROW( *sut->evaluate(val1), InconsistentValueException);
}
