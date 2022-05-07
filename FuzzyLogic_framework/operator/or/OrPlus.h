//
// Created by pc-etude-michel on 07/05/2022.
//

#ifndef FUZZYLOGIC_ORPLUS_H
#define FUZZYLOGIC_ORPLUS_H

#include "operator/or/Or.h"

namespace fuzzyLogic::core::op {
    template <typename T>
    class OrPlus : Or<T> {
    public:
        T* evaluate(Expression<T>* l, Expression<T>* r) override;
        OrPlus() = default;
    };

    template<typename T>
    T *OrPlus<T>::evaluate(Expression<T> *l, Expression<T> *r) {
        if(l != nullptr && r != nullptr)
            return new T(*l->evaluate() + *r->evaluate());
        return nullptr;
    }
}

#endif //FUZZYLOGIC_ORPLUS_H
