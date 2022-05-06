#ifndef FUZZYLOGIC_BINARYEXPRESSIONMODEL_H
#define FUZZYLOGIC_BINARYEXPRESSIONMODEL_H

#include <cstddef>

#include "BinaryExpression.h"
#include "Expression.h"

namespace fuzzyLogic::core {

    template <typename T>
    class BinaryExpressionModel : public BinaryExpression<T>, public Expression<T>{
    protected:
        BinaryExpression<T>* operatorBinaryExpression;
        Expression<T>* left;
        Expression<T>* right;

    public:
        // Implementations :
        T* evaluate() override;
        T* evaluate(Expression<T>* l, Expression<T>* r) override;

        // Getter/Setter :
        BinaryExpression<T>* getOperator();
        void setOperator(BinaryExpression<T>* o);
        Expression<T>* getLeft();
        void setLeft(Expression<T>* o);
        Expression<T>* getRight();
        void setRight(Expression<T>* o);
    };

    template<typename T>
    T *BinaryExpressionModel<T>::evaluate() {
        if(left != NULL && right != NULL)
            return operatorBinaryExpression->evaluate(left,right);
    }

    template<typename T>
    T *BinaryExpressionModel<T>::evaluate(Expression<T> *l, Expression<T> *r) {
        if(operatorBinaryExpression != NULL)
            return evaluate(l,r);
    }

    template<typename T>
    BinaryExpression<T>* BinaryExpressionModel<T>::getOperator() {
        return operatorBinaryExpression;
    }

    template<typename T>
    void BinaryExpressionModel<T>::setOperator(BinaryExpression<T> *o) {
        operatorBinaryExpression = o;
    }

    template<typename T>
    Expression<T>* BinaryExpressionModel<T>::getLeft() {
        return left;
    }

    template<typename T>
    void BinaryExpressionModel<T>::setLeft(Expression<T>* o) {
        left = o;
    }

    template<typename T>
    Expression<T>* BinaryExpressionModel<T>::getRight() {
        return right;
    }

    template<typename T>
    void BinaryExpressionModel<T>::setRight(Expression<T>* o) {
        right = o;
    }

}

#endif //FUZZYLOGIC_BINARYEXPRESSIONMODEL_H
