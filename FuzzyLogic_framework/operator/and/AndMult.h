#ifndef FUZZYLOGIC_ANDMULT_H
#define FUZZYLOGIC_ANDMULT_H

#include "operator/and/And.h"

namespace fuzzyLogic::core::op {
    template<typename T>
    class AndMult : public And<T>{
    public:
        AndMult() = default;
        T* evaluate(Expression<T>* l, Expression<T>* r) override;
    };

    template<typename T>
    T *AndMult<T>::evaluate(Expression<T> *l, Expression<T> *r) {
        if(l != nullptr && r != nullptr)
            return new T(*(l->evaluate()) * *(r->evaluate()));
        return nullptr;
    }
}

#endif //FUZZYLOGIC_ANDMULT_H
