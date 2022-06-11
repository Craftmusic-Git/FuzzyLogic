#ifndef FUZZYLOGIC_BINARYSHADOWEXPRESSION_H
#define FUZZYLOGIC_BINARYSHADOWEXPRESSION_H

#include "BinaryExpression.h"

namespace fuzzyLogic::core {
    template <typename T>
    class BinaryShadowExpression : public BinaryExpression<T>{
    public:
        BinaryShadowExpression() = default;
        explicit BinaryShadowExpression(BinaryExpression<T>* target);
        virtual ~BinaryShadowExpression() = default;
        T* evaluate(Expression<T>* l, Expression<T>* r) const override;

        // GET / SET
        BinaryExpression<T>* getTarget();
        void setTarget(BinaryExpression<T>* t);

    private:
        BinaryExpression<T>* target;
    };

    template<typename T>
    T *BinaryShadowExpression<T>::evaluate(Expression<T> *l, Expression<T> *r) const {
        if(target != nullptr)
            return target->evaluate(l,r);
        else return nullptr;
    }

    template<typename T>
    BinaryExpression<T> *BinaryShadowExpression<T>::getTarget() {
        return target;
    }

    template<typename T>
    void BinaryShadowExpression<T>::setTarget(BinaryExpression<T> *t) {
        target = t;
    }

    template<typename T>
    BinaryShadowExpression<T>::BinaryShadowExpression(BinaryExpression<T> *target) : target(target){

    }
}

#endif //FUZZYLOGIC_BINARYSHADOWEXPRESSION_H
