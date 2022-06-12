#ifndef FUZZYLOGIC_AGGMAX_H
#define FUZZYLOGIC_AGGMAX_H

#include "operator/agg/Agg.h"

namespace fuzzyLogic::core::op {

    template<typename T>
    class AggMax : public Agg<T>{
    public:
        virtual ~AggMax() = default;
        T* evaluate(Expression<T>* l, Expression<T>* r) const override;
    };

    template<typename T>
    T *AggMax<T>::evaluate(Expression<T> *l, Expression<T> *r) const {
        if(l == nullptr || r== nullptr)
            return nullptr;
        T* lEval = l->evaluate();
        T* rEval = r->evaluate();
        return (*lEval < *rEval) ? rEval : lEval;
    }

}

#endif //FUZZYLOGIC_AGGMAX_H
