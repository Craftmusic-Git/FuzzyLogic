#ifndef FUZZYLOGIC_OR_H
#define FUZZYLOGIC_OR_H

#include "core/BinaryExpression.h"
#include "core/Expression.h"

namespace fuzzyLogic::core::op {
    template<typename T>
    class Or : public BinaryExpression<T>{
    public:
        T* evaluate(Expression<T>* l, Expression<T>* r) override = 0;
    };
}


#endif //FUZZYLOGIC_OR_H
