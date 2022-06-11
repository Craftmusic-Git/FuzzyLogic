#include "gtest/gtest.h"
#include "core/ValueModel.h"
#include "operator/is/IsSingleton.h"

using namespace fuzzyLogic::core;
using namespace fuzzyLogic::core::op;

class IsSingletonTestSuite : public ::testing::Test{
protected:
    void SetUp() override{
        sut = new IsSingleton<double>(5);
        val1 = new ValueModel<double>(5);
        val2 = new ValueModel<double>(4);
    }

    void TearDown() override{
        delete sut;
        delete val1;
        delete val2;
    }

    IsSingleton<double>* sut;
    ValueModel<double> *val1;
    ValueModel<double> *val2;

};

TEST_F(IsSingletonTestSuite, fonctionnalTest){
    // y = 1 si x = value
    EXPECT_EQ(*sut->evaluate(val1),1);

    // y = 0 si x != value
    EXPECT_EQ(*sut->evaluate(val2),0);
}

TEST_F(IsSingletonTestSuite, exceptionTest){
    // test NullOperatorException pour x = nullptr
    EXPECT_THROW( *sut->evaluate(nullptr), NullOperatorException);
}