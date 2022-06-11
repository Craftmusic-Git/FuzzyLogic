#ifndef IsLinear_H
#define IsLinear_H

#include <iostream>
#include <cmath>
#include "Is.h"
#include "exceptions/NullOperatorException.h"

namespace fuzzyLogic::core::op{
    template<class T>
    class IsLinear : public Is<T>{
    public:
        IsLinear(T,T);
        virtual ~IsLinear() = default;

        virtual T* evaluate(core::Expression<T>*) const;

        //set
        void setA(T);
        void setB(T);

    private:
        T a;
        T b;

    };

    template<class T>
    IsLinear<T>::IsLinear(T _a, T _b):
            a(_a), b(_b)
    {}

    template<class T>
    T* IsLinear<T>::evaluate(core::Expression<T> *o) const{

        if( o == nullptr){
            throw NullOperatorException("null operator");
        }

        // get x value
        T x = *o->evaluate();

        return new T( a * x + b );
    }

    template<class T>
    void IsLinear<T>::setA(T _a){
        a = _a;
    }

    template<class T>
    void IsLinear<T>::setB(T _b){
        b = _b;
    }

}
#endif