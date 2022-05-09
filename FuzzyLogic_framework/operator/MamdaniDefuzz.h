#ifndef FUZZYLOGIC_MAMDANIDEFUZZ_H
#define FUZZYLOGIC_MAMDANIDEFUZZ_H

#include "core/BinaryExpression.h"
#include "core/Evaluator.h"

namespace fuzzyLogic::core::op {
    template<typename T>
    class MamdaniDefuzz : public BinaryExpression<T> {
    public:
        virtual T* evaluate(Expression<T>* l, Expression<T>* r) const = 0;
        virtual T* defuzz(typename Evaluator<T>::Shape* shape) const = 0;
    };
}

#endif //FUZZYLOGIC_MAMDANIDEFUZZ_H
