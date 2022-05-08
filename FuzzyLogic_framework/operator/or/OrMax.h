#ifndef FUZZYLOGIC_ORMAX_H
#define FUZZYLOGIC_ORMAX_H

#include "operator/or/Or.h"

namespace fuzzyLogic::core::op {
    template<typename T>
    class OrMax : public Or<T>{
    public:
        OrMax() = default;
        T* evaluate(Expression<T>* l, Expression<T>* r) const override;
    };

    template<typename T>
    T *OrMax<T>::evaluate(Expression<T> *l, Expression<T> *r) const{
        if(l != nullptr && r != nullptr) {
            T *le = l->evaluate();
            T *re = r->evaluate();
            return *le < *re ? re : le;
        }else return nullptr;
    }
}

#endif //FUZZYLOGIC_ORMAX_H
