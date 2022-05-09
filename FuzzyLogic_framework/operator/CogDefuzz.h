#ifndef FUZZYLOGIC_COGDEFUZZ_H
#define FUZZYLOGIC_COGDEFUZZ_H

#include "operator/MamdaniDefuzz.h"

namespace fuzzyLogic::core::op {
    template <typename T>
    class CogDefuzz : public MamdaniDefuzz<T>{
    public:
        CogDefuzz(T min, T max, T step);
        T* evaluate(Expression<T>* l, Expression<T>* r) const override;
        T* defuzz(typename Evaluator<T>::Shape* shape) const override;
    private:
        T* min;
        T* max;
        T* step;
    };

    template<typename T>
    CogDefuzz<T>::CogDefuzz(T min, T max, T step) : min(new T(min)), max(new T(max)), step(new T(step)) {
    }

    template<typename T>
    T *CogDefuzz<T>::evaluate(Expression<T> *l, Expression<T> *r) const {
        if(l == nullptr || r == nullptr)
            return nullptr;
        return defuzz(Evaluator<T>::buildShape(min,max,step,(ValueModel<T>*)l,r));
    }

    template<typename T> // Gravity center approach with the rectangle integration method
    T *CogDefuzz<T>::defuzz(typename Evaluator<T>::Shape* shape) const {
        T den = 0, num = 0;
        for(int i = 0; i < shape->first->size(); i++){
            num += shape->first[0][i] * shape->second[0][i];
        }
        for(auto y : *shape->second){
            den += y;
        }
        return new T(num/den);
    }
}

#endif //FUZZYLOGIC_COGDEFUZZ_H
