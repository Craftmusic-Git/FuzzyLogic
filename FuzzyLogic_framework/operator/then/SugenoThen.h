#ifndef FUZZYLOGIC_SUGENOTHEN_H
#define FUZZYLOGIC_SUGENOTHEN_H

#include "Then.h"

namespace fuzzyLogic::core::op{
    template<typename T>
    class SugenoThen : public Then<T>{
    public :
        SugenoThen() = default;
        explicit SugenoThen(T premiseValue);

        virtual ~SugenoThen() = default;

        T* evaluate(Expression<T>* l, Expression<T>* r) const override;
        T* getPremiseValue();

    private:
        T* premiseValue;
    };

    template<typename T>
    SugenoThen<T>::SugenoThen(T premiseValue): premiseValue(new T(premiseValue)) { }

    template<typename T>
    T *SugenoThen<T>::evaluate(Expression<T> *l, Expression<T> *r) const {
        premiseValue = l->evaluate();
        return premiseValue * r->evaluate();
    }

    template<typename T>
    T *SugenoThen<T>::getPremiseValue() {
        return premiseValue;
    }


}

#endif //FUZZYLOGIC_SUGENOTHEN_H
