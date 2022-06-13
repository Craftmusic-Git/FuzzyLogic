#ifndef NULLOPERATOREXCEPTION_H_ISTRAPEZELEFT_H
#define NULLOPERATOREXCEPTION_H_ISTRAPEZELEFT_H

#include "operator/is/Is.h"
#include "exceptions/NullOperatorException.h"
#include "exceptions/InconsistentValueException.h"

namespace fuzzyLogic::core::op {
    template<typename T>
    class IsTrapezeLeft : public Is<T>{
    public:
        IsTrapezeLeft(T, T);
        ~IsTrapezeLeft() = default;
        T* evaluate(Expression<T>* o) const;
        void setMax(T);
        void setMidRight(T);

    private:
        T max;
        T midR;
    };

    template<typename T>
    IsTrapezeLeft<T>::IsTrapezeLeft(T _midR, T _max) :
            max(_max), midR(_midR)
    {}

    template<typename T>
    T* IsTrapezeLeft<T>::evaluate(Expression<T>*  o) const{

        if( o == nullptr){
            //throw exceptions
            throw NullOperatorException("null operator");
        }

        if((midR == max)){
            throw InconsistentValueException("Inconsistent Value");
        }

        T x = *o->evaluate();

        if(x >= max) return new T(0);

        if(x < midR) return new T(1);

        return new T((max-x)/(max-midR));

    }

    template<typename T>
    void IsTrapezeLeft<T>::setMax(T _max){
        max = _max;
    }


    template<typename T>
    void IsTrapezeLeft<T>::setMidRight(T _midR){
        midR = _midR;
    }

}

#endif //NULLOPERATOREXCEPTION_H_ISTRAPEZELEFT_H
