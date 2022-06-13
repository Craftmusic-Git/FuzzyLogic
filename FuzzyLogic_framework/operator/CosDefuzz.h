

#ifndef FUZZYLOGIC_COSDEFUZZ_H
#define FUZZYLOGIC_COSDEFUZZ_H

#include "operator/MamdaniDefuzz.h"

namespace fuzzyLogic::core::op {
    template <typename T>
    class CosDefuzz : public MamdaniDefuzz<T>{
    public:
        CosDefuzz(T min, T max, T step);
        T* evaluate(Expression<T>* l, Expression<T>* r) const override;
        T* defuzz(typename Evaluator<T>::Shape* shape) const override;
    private:
        T* min;
        T* max;
        T* step;
    };

    template<typename T>
    CosDefuzz<T>::CosDefuzz(T min, T max, T step) : min(new T(min)), max(new T(max)), step(new T(step)) {
    }

    template<typename T>
    T *CosDefuzz<T>::evaluate(Expression<T> *l, Expression<T> *r) const {
        if(l == nullptr || r == nullptr)
            return nullptr;
        return defuzz(Evaluator<T>::buildShape(min,max,step,(ValueModel<T>*)l,r));
    }

    template<typename T> // Gravity center approach with the rectangle integration method
    T *CosDefuzz<T>::defuzz(typename Evaluator<T>::Shape* shape) const {
        T den = 0, num = 0, num2 = 0,den2=0;
        for(int i = 0; i < shape->first->size(); i++){
            num += shape->first[0][i];
            num2 +=shape->second[0][i];
        }
        for(auto y : *shape->second){
            den += y;
            den2+=1;
        }
        return new T((num+num2)/(den+den2));
    }
}


#endif //FUZZYLOGIC_COSDEFUZZ_H
