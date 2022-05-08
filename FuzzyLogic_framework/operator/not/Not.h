#ifndef FUZZYLOGIC_NOT_H
#define FUZZYLOGIC_NOT_H

#include "core/UnaryExpression.h"

namespace fuzzyLogic::core::op {
    template <typename T>
    class Not : public UnaryExpression<T>{
    public:
        virtual T* evaluate(Expression<T>* expr) const = 0;
    };
}

#endif //FUZZYLOGIC_NOT_H
