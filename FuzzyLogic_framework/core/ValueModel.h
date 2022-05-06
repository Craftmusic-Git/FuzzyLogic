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
        T* evaluate() override;
        void setValue(T* v);
    };

    template<typename T>
    T* ValueModel<T>::evaluate() {
        return value;
    }

    template<typename T>
    void ValueModel<T>::setValue(T* v) {
        value = v;
    }
}

#endif //LOGIQUEFLOU_VALUEMODEL_H
