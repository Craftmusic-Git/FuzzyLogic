#ifndef FUZZYLOGIC_AGG_H
#define FUZZYLOGIC_AGG_H

#include "core/BinaryExpression.h"

namespace fuzzyLogic::core::op {
    template<typename T>
    class Agg : public BinaryExpression<T>{
    public:
        virtual ~Agg() = default;
        virtual T* evaluate(Expression<T>* l, Expression<T>* r) const = 0;
    };
}

#endif //FUZZYLOGIC_AGG_H
