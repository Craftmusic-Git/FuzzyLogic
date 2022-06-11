#ifndef ISGAUSSIAN_H
#define ISGAUSSIAN_H

#include <iostream>
#include <cmath>
#include "Is.h"
#include "exceptions/NullOperatorException.h"
#include "exceptions/NullParameterException.h"

namespace fuzzyLogic::core::op{
    template<class T>
    class IsGaussian : public Is<T>{
    public:
        IsGaussian(T,T, T);
        virtual ~IsGaussian() = default;

        T* evaluate(core::Expression<T>*) const;

        //set
        void setHeight(T);
        void setMid(T);
        void setDeviation(T);


    private:
        T height; //a
        T mid; // b
        T deviation; //c
    };

    template<class T>
    IsGaussian<T>::IsGaussian(T _height, T _mid, T _deviation):
            height(_height), mid(_mid), deviation(_deviation)
    {}

    template<class T>
    T* IsGaussian<T>::evaluate(core::Expression<T> *o) const{

        if( o == nullptr){
            throw NullOperatorException("null operator");
        }

        // if deviation == 0 , div par 0
        if(deviation == 0){
            throw NullParameterException("null operator");
        }

        // get x value
        T x = *o->evaluate();

        // f(x) = a*exp( - [(x-b)^2]/ 2c^2)
        return new T( height * exp( - pow( ( x - mid ),2 ) / (2 * pow( deviation, 2 ) ) ) );
    }

    template<class T>
    void IsGaussian<T>::setHeight(T _height){
        height = _height;
    }

    template<class T>
    void IsGaussian<T>::setMid(T _mid){
        mid = _mid;
    }

    template<class T>
    void IsGaussian<T>::setDeviation(T _deviation){
        deviation = _deviation;
    }

}
#endif