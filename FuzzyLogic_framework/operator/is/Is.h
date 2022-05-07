#ifndef FUZZYLOGIC_IS_H
#define FUZZYLOGIC_IS_H

#include "core/UnaryExpression.h"

namespace fuzzyLogic::core::op {
    template< typename T>
    class Is : public UnaryExpression<T>{
    public:
        virtual T* evaluate(Expression<T>* expr) = 0;
    };
}

#endif //FUZZYLOGIC_IS_H
