#ifndef LOGIQUEFLOU_UNARYEXPRESSION_H
#define LOGIQUEFLOU_UNARYEXPRESSION_H

#include "Expression.h"

namespace fuzzyLogic::core {
    template<typename T>
    class UnaryExpression {
    public:
        virtual ~UnaryExpression() = default;
        virtual T* evaluate(Expression<T>* o) const = 0;
    };
}

#endif //LOGIQUEFLOU_UNARYEXPRESSION_H
