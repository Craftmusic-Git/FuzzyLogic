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
        T value;

    public:
        T evaluate(){
            return value;
        }

        void setValue(T v){
            value = v;
        }
    };
}

#endif //LOGIQUEFLOU_VALUEMODEL_H
