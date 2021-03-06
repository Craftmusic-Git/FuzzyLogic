//
// Created by pc-etude-michel on 05/05/2022.
//

#ifndef LOGIQUEFLOU_VALUEMODEL_H
#define LOGIQUEFLOU_VALUEMODEL_H

#include "Expression.h"

namespace fuzzyLogic::core {
    template<typename T>
    class ValueModel : public Expression<T>{
    private :
        T* value;

    public:
        ValueModel() = default;
        explicit ValueModel(T value);

        virtual ~ValueModel() = default;

        T* evaluate() const override;
        void setValue(T* v);
        void setValue(T v);
    };

    template<typename T>
    T* ValueModel<T>::evaluate() const{
        return value;
    }

    template<typename T>
    void ValueModel<T>::setValue(T* v) {
        value = v;
    }

    template<typename T>
    ValueModel<T>::ValueModel(T value) : value(new T(value)){

    }

    template<typename T>
    void ValueModel<T>::setValue(T v) {
        setValue(&v);
    }
}

#endif //LOGIQUEFLOU_VALUEMODEL_H
