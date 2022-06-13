//
// Created by Alexis on 12/06/2022.
//

#ifndef FUZZYLOGIC_LOMDEFUZZ_H
#define FUZZYLOGIC_LOMDEFUZZ_H

#include "operator/MamdaniDefuzz.h"

namespace fuzzyLogic::core::op {
    template <typename T>
    class LomDefuzz : public MamdaniDefuzz<T>{
    public:
        LomDefuzz(T min, T max, T step);
        T* evaluate(Expression<T>* l, Expression<T>* r) const override;
        T* defuzz(typename Evaluator<T>::Shape* shape) const override;
    private:
        T* min;
        T* max;
        T* step;
    };

    template<typename T>
    LomDefuzz<T>::LomDefuzz(T min, T max, T step) : min(new T(min)), max(new T(max)), step(new T(step)) {
    }

    template<typename T>
    T *LomDefuzz<T>::evaluate(Expression<T> *l, Expression<T> *r) const {
        if(l == nullptr || r == nullptr)
            return nullptr;
        return defuzz(Evaluator<T>::buildShape(min,max,step,(ValueModel<T>*)l,r));
    }

    template<typename T> // Gravity center approach with the rectangle integration method
    T *LomDefuzz<T>::defuzz(typename Evaluator<T>::Shape* shape) const {
        T den = 0, num = 0, max = shape->first[0][0] * shape->second[0][0];
        for(int i = 1; i < shape->first->size(); i++){
            if(shape->first[0][i]*shape->second[0][i]>=max)
                max = shape->first[0][i] * shape->second[0][i];
        }
        return new T(max);
    }
}

#endif //FUZZYLOGIC_LOMDEFUZZ_H
