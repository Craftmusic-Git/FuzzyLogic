#ifndef IsSingleton_H
#define IsSingleton_H

#include <iostream>
#include <cmath>
#include "Is.h"
#include "exceptions/NullOperatorException.h"

namespace fuzzyLogic::core::op{
    template<class T>
    class IsSingleton : public Is<T>{
    public:
        IsSingleton(T);
        virtual ~IsSingleton() = default;
        virtual T* evaluate(core::Expression<T>*) const;

        void setValue(T);

    private:
        T value;
    };

    template<class T>
    IsSingleton<T>::IsSingleton(T _value):
            value(_value)
    {}

    template<class T>
    T* IsSingleton<T>::evaluate(core::Expression<T> *o) const{

        if( o == nullptr){
            throw NullOperatorException("null operator");
        }

        // get x value
        T x = *o->evaluate();

        return (x == value ? new T(1) : new T(0));
    }

    template<class T>
    void IsSingleton<T>::setValue(T _value){
        value = _value;
    }

}
#endif