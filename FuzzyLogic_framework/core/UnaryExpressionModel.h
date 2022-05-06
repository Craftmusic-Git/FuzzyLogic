#ifndef FUZZYLOGIC_UNARYEXPRESSIONMODEL_H
#define FUZZYLOGIC_UNARYEXPRESSIONMODEL_H

#include "Expression.h"
#include "UnaryExpression.h"

namespace fuzzyLogic::core {
    template <typename T>
    class UnaryExpressionModel : public Expression<T>, public UnaryExpression<T>{
    protected:
        UnaryExpression<T>* operatorUnaryExpression;
        Expression<T>* operand;
    public:
        T* evaluate() override;
        T* evaluate(Expression<T>* o) override;

        // SETTER/GETTER
        void setOperand(Expression<T>* o);
        Expression<T>* getOperand();
        void setOperator(UnaryExpression<T>* o);
        UnaryExpression<T>* getOperator();
    };

    template<typename T>
    T* UnaryExpressionModel<T>::evaluate() {
        if(operand != NULL)
            return evaluate(operand);
        return NULL;
    }

    template<typename T>
    T* UnaryExpressionModel<T>::evaluate(Expression<T>* o) {
        if(operatorUnaryExpression != NULL)
            return operatorUnaryExpression->evaluate(operand);
        return NULL;
    }

    template<typename T>
    void UnaryExpressionModel<T>::setOperand(Expression<T>* o) {
        operand = o;
    }

    template<typename T>
    Expression<T> *UnaryExpressionModel<T>::getOperand() {
        return operand;
    }

    template<typename T>
    void UnaryExpressionModel<T>::setOperator(UnaryExpression<T> *o) {
        operatorUnaryExpression = o;
    }

    template<typename T>
    UnaryExpression<T> *UnaryExpressionModel<T>::getOperator() {
        return operatorUnaryExpression;
    }
}

#endif //FUZZYLOGIC_UNARYEXPRESSIONMODEL_H
