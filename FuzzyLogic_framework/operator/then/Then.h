#ifndef FUZZYLOGIC_THEN_H
#define FUZZYLOGIC_THEN_H

#include "core/Expression.h"
#include "core/BinaryExpression.h"

namespace fuzzyLogic::core::op {
    template<typename T>
    class Then : public BinaryExpression<T>{
    public:
        virtual ~Then() = default;
        virtual T* evaluate(Expression<T>* l, Expression<T>* r) const = 0;
    };
}

#endif //FUZZYLOGIC_THEN_H
