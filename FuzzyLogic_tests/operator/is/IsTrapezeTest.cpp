#include "gtest/gtest.h"
#include "core/ValueModel.h"
#include "operator/is/IsTrapeze.h"

using namespace fuzzyLogic::core;
using namespace fuzzyLogic::core::op;

class IsTrapezeTestSuite : public ::testing::Test{
protected:
    void SetUp() override{
        sut = new IsTrapeze<double>(0,6,2,4);
        val1 = new ValueModel<double>(1);
        val2 = new ValueModel<double>(5);
        val3 = new ValueModel<double>(std::numeric_limits< double >::max()); // infini
        val4 = new ValueModel<double>(-(std::numeric_limits< double >::max())); // -infini
        val5 = new ValueModel<double>(3);

    }

    void TearDown() override{
        delete sut;
        delete val1;
        delete val2;
        delete val3;
        delete val4;
        delete val5;
    }

    IsTrapeze<double>* sut;
    ValueModel<double> *val1;
    ValueModel<double> *val2;
    ValueModel<double> *val3;
    ValueModel<double> *val4;
    ValueModel<double> *val5;
};

TEST_F(IsTrapezeTestSuite, fonctionnalTest){
    // verification de la valeur mi-monter
    EXPECT_EQ(*sut->evaluate(val1),0.5);

    // verification de la valeur mi-descente
    EXPECT_EQ(*sut->evaluate(val2),0.5);

    // verification de la valeur haute
    EXPECT_EQ(*sut->evaluate(val5),1);

    // y = 0, x-> +infini
    EXPECT_EQ(*sut->evaluate(val3),0);

    // y = 0, x-> -infini
    EXPECT_EQ(*sut->evaluate(val4),0);
}

TEST_F(IsTrapezeTestSuite, exceptionTest){

    // test NullOperatorException pour x = nullptr
    EXPECT_THROW( *sut->evaluate(nullptr), std::runtime_error);

    // si min == midL alors InconsistentValueException
    sut->setMin(2);
    EXPECT_THROW( *sut->evaluate(val1), std::runtime_error);

    // si max == midR alors inconsistentValueException
    sut->setMin(0);
    sut->setMax(4);
    EXPECT_THROW( *sut->evaluate(val1), InconsistentValueException);

}





