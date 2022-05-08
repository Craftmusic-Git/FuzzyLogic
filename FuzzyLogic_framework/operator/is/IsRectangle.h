#ifndef FUZZYLOGIC_ISRECTANGLE_H
#define FUZZYLOGIC_ISRECTANGLE_H

#include "operator/is/Is.h"

namespace fuzzyLogic::core::op {
    template<typename T>
    class IsRectangle : public Is<T>{
    public:
        IsRectangle(T inf, T sup);
        ~IsRectangle() = default;
        T* evaluate(Expression<T>* expr) const override;
    private:
        T* inf;
        T* sup;
    };

    template<typename T>
    IsRectangle<T>::IsRectangle(T inf, T sup) : inf(new T(inf)), sup(new T(sup)){
    }

    template<typename T>
    T *IsRectangle<T>::evaluate(Expression<T> *expr) const {
        if(expr == nullptr)
            return nullptr;
        T val = *expr->evaluate();
        if(val > *sup || val < *inf)
            return new T(0);
        return new T(1);
    }
}

#endif //FUZZYLOGIC_ISRECTANGLE_H
