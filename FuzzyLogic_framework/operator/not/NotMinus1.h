#ifndef FUZZYLOGIC_NOTMINUS1_H
#define FUZZYLOGIC_NOTMINUS1_H

#include "operator/not/Not.h"

namespace fuzzyLogic::core::op {
    template<typename T>
    class NotMinus1 : public Not<T> {
    public:
        T* evaluate(Expression<T>* expr) const override;
    };

    template<typename T>
    T *NotMinus1<T>::evaluate(Expression<T> *expr) const {
        if(expr == nullptr)
            return nullptr;
        return new T(1 - *expr->evaluate());
    }
}

#endif //FUZZYLOGIC_NOTMINUS1_H
