#ifndef FUZZYLOGIC_ISTRIANGLE_H
#define FUZZYLOGIC_ISTRIANGLE_H

#include "operator/is/Is.h"
#include "exceptions/NullOperatorException.h"

namespace fuzzyLogic::core::op {
    template<typename T>
    class IsTriangle : public Is<T>{
    private:
        T* min;
        T* mid;
        T* max;

    public :
        explicit IsTriangle(T min = 0, T mid =0, T max=0);
        virtual ~IsTriangle() = default;
        T* evaluate(Expression<T>* expr) const;
    };

    template<typename T>
    IsTriangle<T>::IsTriangle(T min, T mid, T max) : min(new T(min)), mid(new T(mid)), max(new T(max)){
    }

    template<typename T>
    T *IsTriangle<T>::evaluate(Expression<T> *expr) const {
        if(expr == nullptr)
            throw NullOperatorException("null operator");
        T* eval = expr->evaluate();

        if(*eval < *min || *eval > *max)
            return new T(0);

        return (*eval < *mid) ? new T((*eval-*min)/(*mid-*min)) : new T((*max-*eval)/(*max-*mid));
    }
}

#endif //FUZZYLOGIC_ISTRIANGLE_H