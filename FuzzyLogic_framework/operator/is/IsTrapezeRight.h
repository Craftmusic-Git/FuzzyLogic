#ifndef NULLOPERATOREXCEPTION_H_ISTRAPEZERIGHT_H
#define NULLOPERATOREXCEPTION_H_ISTRAPEZERIGHT_H

#include "operator/is/Is.h"
#include "exceptions/NullOperatorException.h"
#include "exceptions/InconsistentValueException.h"

namespace fuzzyLogic::core::op {
    template<typename T>
    class IsTrapezeRight : public Is<T>{
    public:
        IsTrapezeRight(T, T);
        ~IsTrapezeRight() = default;
        T* evaluate(Expression<T>* o) const;
        void setMin(T);
        void setMidLeft(T);

    private:
        T min;
        T midL;
    };

    template<typename T>
    IsTrapezeRight<T>::IsTrapezeRight(T _min, T _midL) :
            min(_min), midL(_midL)
    {}

    template<typename T>
    T* IsTrapezeRight<T>::evaluate(Expression<T>*  o) const{

        if( o == nullptr){
            //throw exceptions
            throw NullOperatorException("null operator");
        }

        if((midL == min)){
            throw InconsistentValueException("Inconsistent Value");
        }

        T x = *o->evaluate();

        if(x <= min) return new T(0);

        if(x > midL) return new T(1);

        return new T((x-min)/(midL-min));

    }

    template<typename T>
    void IsTrapezeRight<T>::setMin(T _min){
        min = _min;
    }


    template<typename T>
    void IsTrapezeRight<T>::setMidLeft(T _midL){
        midL = _midL;
    }

}

#endif //NULLOPERATOREXCEPTION_H_ISTRAPEZERIGHT_H
