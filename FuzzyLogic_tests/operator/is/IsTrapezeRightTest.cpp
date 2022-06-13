#include "gtest/gtest.h"
#include "core/ValueModel.h"
#include "operator/is/IsTrapezeRight.h"

using namespace fuzzyLogic::core;
using namespace fuzzyLogic::core::op;

class IsTrapezeRightTestSuite : public ::testing::Test{
protected:
    void SetUp() override{
        sut = new IsTrapezeRight<double>(0,2);
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

    IsTrapezeRight<double>* sut;
    ValueModel<double> *val1;
    ValueModel<double> *val3;
    ValueModel<double> *val4;
};

TEST_F(IsTrapezeRightTestSuite, fonctionnalTest){
    // verification de la valeur mi-montée
    EXPECT_EQ(*sut->evaluate(val1),0.5);

    // y = 0, x-> +infini
    EXPECT_EQ(*sut->evaluate(val3),1);

    // y = 0, x-> -infini
    EXPECT_EQ(*sut->evaluate(val4),0);
}

TEST_F(IsTrapezeRightTestSuite, exceptionTest){

    // test NullOperatorException pour x = nullptr
    EXPECT_THROW( *sut->evaluate(nullptr), std::runtime_error);

    // si min == midL alors InconsistentValueException
    sut->setMin(2);
    EXPECT_THROW( *sut->evaluate(val1), std::runtime_error);
}
