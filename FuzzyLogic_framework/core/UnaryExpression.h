#ifndef LOGIQUEFLOU_UNARYEXPRESSION_H
#define LOGIQUEFLOU_UNARYEXPRESSION_H

#include "Expression.h"

namespace fuzzyLogic::core {
    template<typename T>
    class UnaryExpression {
    public:
        virtual T* evaluate(Expression<T>* o) = 0;
    };

}

#endif //LOGIQUEFLOU_UNARYEXPRESSION_H