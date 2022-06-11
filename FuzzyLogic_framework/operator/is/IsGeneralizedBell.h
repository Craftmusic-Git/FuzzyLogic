#ifndef IsGeneralizedBell_H
#define IsGeneralizedBell_H

#include <iostream>
#include <cmath>
#include "Is.h"
#include "exceptions/NullOperatorException.h"
#include "exceptions/NullParameterException.h"


namespace fuzzyLogic::core::op{
    template<class T>
    class IsGeneralizedBell : public Is<T>{
    public:
        IsGeneralizedBell(T, T, T);
        virtual ~IsGeneralizedBell() = default;

        virtual T* evaluate(core::Expression<T>*) const;

        //set
        void setHalfWidth(T);
        void setMid(T);
        void setSlope(T);


    private:
        T halfWidth; //a
        T mid; // c
        T slope; //b
    };

    template<class T>
    IsGeneralizedBell<T>::IsGeneralizedBell(T _halfWidth, T _mid, T _slope):
            halfWidth(_halfWidth), mid(_mid), slope(_slope)
    {}

    template<class T>
    T* IsGeneralizedBell<T>::evaluate(core::Expression<T> *o) const{

        if( o == nullptr){
            throw NullOperatorException("null operator");
        }

        if(halfWidth == 0){
            throw NullParameterException("null operator");
        }

        // get x value
        T x = *o->evaluate();

        // f(x) = 1/(1 + abs([x-c]/a)^(2b) )
        return new T( 1 / (1 + pow(abs((x - mid ) / halfWidth ), 2 * slope ) ) );
    }

    template<class T>
    void IsGeneralizedBell<T>::setHalfWidth(T _halfWidth){
        halfWidth = _halfWidth;
    }

    template<class T>
    void IsGeneralizedBell<T>::setMid(T _mid){
        mid = _mid;
    }

    template<class T>
    void IsGeneralizedBell<T>::setSlope(T _slope){
        slope = _slope;
    }

}
#endif