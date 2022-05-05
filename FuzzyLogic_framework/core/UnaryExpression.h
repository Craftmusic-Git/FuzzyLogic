#ifndef LOGIQUEFLOU_UNARYEXPRESSION_H
#define LOGIQUEFLOU_UNARYEXPRESSION_H

#include "Expression.h"

namespace fuzzyLogic::core {
    template<typename T>
    class UnaryExpression {
        T evaluate(Expression<T> o);
    };

}

#endif //LOGIQUEFLOU_UNARYEXPRESSION_H
