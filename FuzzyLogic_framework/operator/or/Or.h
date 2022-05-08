#ifndef FUZZYLOGIC_OR_H
#define FUZZYLOGIC_OR_H

#include "core/BinaryExpression.h"
#include "core/Expression.h"

namespace fuzzyLogic::core::op {
    template<typename T>
    class Or : public BinaryExpression<T>{
    public:
        virtual T* evaluate(Expression<T>* l, Expression<T>* r) const = 0;
    };
}


#endif //FUZZYLOGIC_OR_H
