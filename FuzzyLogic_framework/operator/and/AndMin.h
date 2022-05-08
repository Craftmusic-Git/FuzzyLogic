//
// Created by pc-etude-michel on 06/05/2022.
//

#ifndef FUZZYLOGIC_ANDMIN_H
#define FUZZYLOGIC_ANDMIN_H

#include "operator/and/And.h"

namespace fuzzyLogic::core::op {
    template<typename T>
    class AndMin : public And<T> {
    public:
        AndMin() = default;
        T* evaluate(Expression<T>* l, Expression<T>* r) const override;
    };

    template<typename T>
    T *AndMin<T>::evaluate(Expression<T>* l, Expression<T>* r) const {
        if(l != nullptr && r != nullptr) {
            T *le = l->evaluate();
            T *re = r->evaluate();
            return *le > *re ? re : le;
        }else return nullptr;
    }
}

#endif //FUZZYLOGIC_ANDMIN_H
