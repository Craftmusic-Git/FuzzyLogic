#ifndef NULLOPERATOREXCEPTION_H_ISSIGMOIDLEFT_H
#define NULLOPERATOREXCEPTION_H_ISSIGMOIDLEFT_H

#include <cmath>

#include "Is.h"
#include "exceptions/NullOperatorException.h"


namespace fuzzyLogic::core::op{
    template<class T>
    class IsSigmoidLeft : public Is<T>{
    public:
        virtual ~IsSigmoidLeft() = default;

        virtual T* evaluate(core::Expression<T>*) const;
    };

    template<class T>
    T* IsSigmoidLeft<T>::evaluate(core::Expression<T> *o) const{

        if( o == nullptr){
            throw NullOperatorException("null operator");
        }

        // get x value
        T x = *o->evaluate();

        return new T(1 - (1/(1+exp(-x))) );
    }

}
#endif //NULLOPERATOREXCEPTION_H_ISSIGMOIDLEFT_H
