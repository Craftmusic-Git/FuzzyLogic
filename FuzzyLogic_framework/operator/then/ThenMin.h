#ifndef FUZZYLOGIC_THENMIN_H
#define FUZZYLOGIC_THENMIN_H

#include "operator/then/Then.h"

namespace fuzzyLogic::core::op {
    template<typename T>
    class ThenMin : public Then<T>{
    public:
        ThenMin() = default;
        virtual ~ThenMin() = default;
        T* evaluate(Expression<T>* l, Expression<T>* r) const override;
    };

    template<typename T>
    T *ThenMin<T>::evaluate(Expression<T> *l, Expression<T> *r) const {
        if(l == nullptr || r == nullptr)
            return nullptr;
        T* lEval = l->evaluate();
        T* rEval = r->evaluate();
        if(*lEval > *rEval)
            return rEval;
        return lEval;
    }
}

#endif //FUZZYLOGIC_THENMIN_H
