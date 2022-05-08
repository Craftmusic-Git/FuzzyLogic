#ifndef FUZZYLOGIC_AND_H
#define FUZZYLOGIC_AND_H

#include "core/BinaryExpression.h"
#include "core/Expression.h"

namespace fuzzyLogic::core::op {
    template< typename T>
    class And : public BinaryExpression<T> {
    public:
        virtual T* evaluate(Expression<T>* l, Expression<T>* r) const = 0;
    };
}

#endif //FUZZYLOGIC_AND_H
