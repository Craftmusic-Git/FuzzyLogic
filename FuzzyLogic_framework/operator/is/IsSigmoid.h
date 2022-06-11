#ifndef IsSigmoid_H
#define IsSigmoid_H

#include <iostream>
#include <cmath>

#include "Is.h"
#include "exceptions/NullOperatorException.h"


namespace fuzzyLogic::core::op{
    template<class T>
    class IsSigmoid : public Is<T>{
    public:
        virtual ~IsSigmoid() = default;

        virtual T* evaluate(core::Expression<T>*) const;
    };

    template<class T>
    T* IsSigmoid<T>::evaluate(core::Expression<T> *o) const{

        if( o == nullptr){
            throw NullOperatorException("null operator");
        }

        // get x value
        T x = *o->evaluate();

        return new T( 1/(1+exp(-x)) );
    }

}
#endif