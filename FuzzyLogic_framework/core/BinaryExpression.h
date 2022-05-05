#ifndef LOGIQUEFLOU_BINARYEXPRESSION_H
#define LOGIQUEFLOU_BINARYEXPRESSION_H

#include "Expression.h"

namespace fuzzyLogic::core {
    template <typename T>
    class BinaryExpression {
        T evaluate(Expression<T> l, Expression<T> r);
    };
}

#endif //LOGIQUEFLOU_BINARYEXPRESSION_H
