#ifndef FUZZYLOGIC_THENMULT_H
#define FUZZYLOGIC_THENMULT_H

#include "operator/then/Then.h"

namespace fuzzyLogic::core::op {
    template <typename T>
    class ThenMult : public Then<T>{
    public:
        virtual ~ThenMult() = default;
        T* evaluate(Expression<T>* l, Expression<T>* r)const override;
    };

    template<typename T>
    T *ThenMult<T>::evaluate(Expression<T> *l, Expression<T> *r) const {
        if(l == nullptr || r == nullptr)
            return nullptr;
        return new T(*l->evaluate() * *r->evaluate());
    }
}

#endif //FUZZYLOGIC_THENMULT_H
