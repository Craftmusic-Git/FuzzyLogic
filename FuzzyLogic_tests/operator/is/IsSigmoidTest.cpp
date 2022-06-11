#include "gtest/gtest.h"
#include "core/ValueModel.h"
#include "operator/is/IsSigmoid.h"

using namespace fuzzyLogic::core;
using namespace fuzzyLogic::core::op;

class IsSigmoidTestSuite : public ::testing::Test{
protected:
    void SetUp() override{
        sut = new IsSigmoid<double>();
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

    IsSigmoid<double>* sut;
    ValueModel<double> *val1;
    ValueModel<double> *val3;
    ValueModel<double> *val4;
};


TEST_F(IsSigmoidTestSuite, fonctionnalTest){
    // verification de la valeur mi-monté
    EXPECT_EQ(*sut->evaluate(val1),0.5);

    // y = 1, x-> +infini
    EXPECT_EQ(*sut->evaluate(val3),1.0);

    // y = 0, x-> -infini
    EXPECT_EQ(*sut->evaluate(val4),0);

}

TEST_F(IsSigmoidTestSuite, exceptionTest){
    // test NullOperatorException pour x = nullptr
    EXPECT_THROW( *sut->evaluate(nullptr), NullOperatorException);
}
