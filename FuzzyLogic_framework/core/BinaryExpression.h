#ifndef LOGIQUEFLOU_BINARYEXPRESSION_H
#define LOGIQUEFLOU_BINARYEXPRESSION_H

#include "Expression.h"

namespace fuzzyLogic::core {
    template <typename T>
    class BinaryExpression {
    public:
        virtual T* evaluate(Expression<T>* l, Expression<T>* r) = 0;
    };
}

#endif //LOGIQUEFLOU_BINARYEXPRESSION_H
