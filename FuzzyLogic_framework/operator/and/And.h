#ifndef FUZZYLOGIC_AND_H
#define FUZZYLOGIC_AND_H

#include "core/BinaryExpression.h"
#include "core/Expression.h"

namespace fuzzyLogic::core::op {
    template< typename T>
    class And : public BinaryExpression<T> {
    public:
        T* evaluate(Expression<T>* l, Expression<T>* r) override = 0;
    };
}

#endif //FUZZYLOGIC_AND_H
