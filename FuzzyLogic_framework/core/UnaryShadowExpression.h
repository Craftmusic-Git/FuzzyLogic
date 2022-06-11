#ifndef FUZZYLOGIC_UNARYSHADOWEXPRESSION_H
#define FUZZYLOGIC_UNARYSHADOWEXPRESSION_H

#include "core/UnaryExpression.h"
#include "core/Expression.h"

namespace fuzzyLogic::core{
    template <typename T>
    class UnaryShadowExpression : public UnaryExpression<T> {
    public :
        UnaryShadowExpression() = default;
        explicit UnaryShadowExpression(UnaryExpression<T>* target);
        virtual ~UnaryShadowExpression() = default;
        T* evaluate( Expression<T>* o) const override;

        // GET / SET

        UnaryExpression<T>* getTarget();
        void setTarget(UnaryExpression<T>* t);

    private :
        UnaryExpression<T>* target;
    };

    template<typename T>
    T *UnaryShadowExpression<T>::evaluate(Expression<T> *o) const {
        if(target != nullptr)
            return target->evaluate(o);
        else return nullptr;
    }

    template<typename T>
    UnaryExpression<T> *UnaryShadowExpression<T>::getTarget() {
        return target;
    }

    template<typename T>
    void UnaryShadowExpression<T>::setTarget(UnaryExpression<T> *t) {
        target = t;
    }

    template<typename T>
    UnaryShadowExpression<T>::UnaryShadowExpression(UnaryExpression<T>* target) : target(target) {

    }


}

#endif //FUZZYLOGIC_UNARYSHADOWEXPRESSION_H
