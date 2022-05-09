#ifndef FUZZYLOGIC_NARYEXPRESSION_H
#define FUZZYLOGIC_NARYEXPRESSION_H

#include <vector>

#include "core/Expression.h"

namespace fuzzyLogic::core {
    template<typename T>
    class NaryExpression {
    public:
        virtual ~NaryExpression() = default;
        virtual T* evaluate(std::vector<Expression<T>*> *operands) const = 0;
    };
}

#endif //FUZZYLOGIC_NARYEXPRESSION_H
