#ifndef FUZZYLOGIC_ISTRAPEZE_H
#define FUZZYLOGIC_ISTRAPEZE_H

#include "operator/is/Is.h"
#include "exceptions/NullOperatorException.h"
#include "exceptions/InconsistentValueException.h"

namespace fuzzyLogic::core::op {
    template<typename T>
    class IsTrapeze : public Is<T>{
    public:
        IsTrapeze(T, T, T, T);
        ~IsTrapeze() = default;
        T* evaluate(Expression<T>* o) const;
        void setMin(T);
        void setMidLeft(T);
        void setMidRight(T);
        void setMax(T);

    private:
        T min;
        T max;
        T midL;
        T midR;
    };

    template<typename T>
    IsTrapeze<T>::IsTrapeze(T _min, T _max, T _midL, T _midR) :
            min(_min), max(_max), midL(_midL), midR(_midR)
    {}

    template<typename T>
    T* IsTrapeze<T>::evaluate(Expression<T>*  o) const{

        if( o == nullptr){
            //throw exceptions
            throw NullOperatorException("null operator");
        }

        if((midL == min) || (midR == max)){
            throw InconsistentValueException("Inconsistent Value");
        }

        T x = *o->evaluate();

        if(x <= min || x > max) return new T(0);

        if(x<= midR && x > midL) return new T(1);

        return (x<=midL) ? new T((x-min)/(midL-min)) : new T((max-x)/(max-midR));

    }

    template<typename T>
    void IsTrapeze<T>::setMin(T _min){
        min = _min;
    }

    template<typename T>
    void IsTrapeze<T>::setMax(T _max){
        max = _max;
    }

    template<typename T>
    void IsTrapeze<T>::setMidLeft(T _midL){
        midL = _midL;
    }

    template<typename T>
    void IsTrapeze<T>::setMidRight(T _midR){
        midR = _midR;
    }

}

#endif //FUZZYLOGIC_ISTRAPEZE_H
