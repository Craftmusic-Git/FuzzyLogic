#ifndef FUZZYLOGIC_AGGPLUS_H
#define FUZZYLOGIC_AGGPLUS_H

#include "operator/agg/Agg.h"

namespace fuzzyLogic::core::op {
    template<typename T>
    class AggPlus : public Agg<T>{
    public:
        virtual ~AggPlus() = default;
        T* evaluate(Expression<T>* l, Expression<T>* r) const override;
    };

    template<typename T>
    T *AggPlus<T>::evaluate(Expression<T> *l, Expression<T> *r) const {
        if(l == nullptr || r == nullptr)
            return nullptr;
        return new T(*l->evaluate() + *r->evaluate());
    }
}

#endif //FUZZYLOGIC_AGGPLUS_H
