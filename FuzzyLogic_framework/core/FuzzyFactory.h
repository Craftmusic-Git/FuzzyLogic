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
        FuzzyFactory() = default;
        FuzzyFactory(Not<T>*, And<T>*, Or<T>*, Then<T>*, Agg<T>*, CogDefuzz<T>*);

        virtual ~FuzzyFactory() = default;

        Expression<T>* newAnd(Expression<T>* l  = nullptr, Expression<T>* r  = nullptr);
        Expression<T>* newOr(Expression<T>* l  = nullptr, Expression<T>* r  = nullptr);
        Expression<T>* newThen(Expression<T>* l  = nullptr, Expression<T>* r  = nullptr);
        Expression<T>* newAgg(Expression<T>* l  = nullptr, Expression<T>* r  = nullptr);
        Expression<T>* newDefuzz(Expression<T>* l  = nullptr, Expression<T>* r  = nullptr, const T min = 0, const T max = 1, const T step = 1);
        Expression<T>* newNot(Expression<T>* o  = nullptr);
        Expression<T>* newIs(Expression<T>* o = nullptr, Is<T>* s = nullptr);


    };

    template<typename T>
    FuzzyFactory<T>::FuzzyFactory(Not<T> *_not, And<T> *_and, Or<T> *_or, Then<T> *_then, Agg<T> *_agg, CogDefuzz<T> *_deffuzz) :
            _not(new UnaryShadowExpression<T>(_not)),
            _and(new BinaryShadowExpression<T>(_and)),
            _or(new BinaryShadowExpression<T>(_or)),
            _then(new BinaryShadowExpression<T>(_then)),
            _agg(new BinaryShadowExpression<T>(_agg)),
            _deffuzz(new BinaryShadowExpression<T>(_deffuzz)){

    }

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
    Expression<T>* FuzzyFactory<T>::newIs(Expression<T>* o, Is<T>* s) {
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
