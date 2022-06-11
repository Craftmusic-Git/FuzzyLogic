#ifndef FUZZYLOGIC_FUZZYFACTORY_H
#define FUZZYLOGIC_FUZZYFACTORY_H

#include "ExpressionFactory.h"
#include "operator/and/And.h"
#include "operator/or/Or.h"
#include "operator/then/Then.h"
#include "operator/agg/Agg.h"
#include "operator/not/Not.h"
#include "operator/is/Is.h"
#include "core/BinaryShadowExpression.h"
#include "core/UnaryShadowExpression.h"
#include "operator/MamdaniDefuzz.h"
#include "operator/CogDefuzz.h"

namespace fuzzyLogic::core {
    using namespace fuzzyLogic::core::op;

    template<typename T>
    class FuzzyFactory : public ExpressionFactory<T> {
    private:
        BinaryShadowExpression<T> *_and, *_or, *_then, *_agg, *_deffuzz;
        UnaryShadowExpression<T> *_not;
    public:
        Expression<T>* newAnd(Expression<T>* l  = nullptr, Expression<T>* r  = nullptr);
        Expression<T>* newOr(Expression<T>* l  = nullptr, Expression<T>* r  = nullptr);
        Expression<T>* newThen(Expression<T>* l  = nullptr, Expression<T>* r  = nullptr);
        Expression<T>* newAgg(Expression<T>* l  = nullptr, Expression<T>* r  = nullptr);
        Expression<T>* newDefuzz(Expression<T>* l  = nullptr, Expression<T>* r  = nullptr, const T min = 0, const T max = 1, const T step = 1);
        Expression<T>* newNot(Expression<T>* o  = nullptr);
        Expression<T>* newIs(Is<T>* s = nullptr, Expression<T>* o = nullptr);
    };

    template<typename T>
    Expression<T>* FuzzyFactory<T>::newAnd(Expression<T>* l, Expression<T>* r) {
        return ExpressionFactory<T>::newBinary(_and,l,r);
    }

    template<typename T>
    Expression<T>* FuzzyFactory<T>::newOr(Expression<T>* l, Expression<T>* r) {
        return ExpressionFactory<T>::newBinary(_or,l,r);
    }

    template<typename T>
    Expression<T>* FuzzyFactory<T>::newThen(Expression<T>* l, Expression<T>* r) {
        return ExpressionFactory<T>::newBinary(_then,l,r);
    }

    template<typename T>
    Expression<T>* FuzzyFactory<T>::newAgg(Expression<T>* l, Expression<T>* r) {
        return ExpressionFactory<T>::newBinary(_agg,l,r);
    }

    template<typename T>
    Expression<T>* FuzzyFactory<T>::newNot(Expression<T>* o) {
        return ExpressionFactory<T>::newUnary(_not,o);
    }

    template<typename T>
    Expression<T>* FuzzyFactory<T>::newIs(Is<T>* s, Expression<T>* o) {
        return ExpressionFactory<T>::newUnary(s,o);
    }

    template<typename T>
    Expression<T> *
    FuzzyFactory<T>::newDefuzz(Expression<T> *l, Expression<T> *r, const T min, const T max, const T step) {
        MamdaniDefuzz<T>* target = (MamdaniDefuzz<T>*)(new CogDefuzz<T>(min,max,step));
        return ExpressionFactory<T>::newBinary(target, l, r);
    }
}

#endif //FUZZYLOGIC_FUZZYFACTORY_H
