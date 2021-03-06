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
        virtual ~BinaryExpressionModel() = default;
        T* evaluate() const override;
        T* evaluate(Expression<T>* l, Expression<T>* r) const override;

        // Getter/Setter :
        BinaryExpression<T>* getOperator() const;
        void setOperator(BinaryExpression<T>* o);
        Expression<T>* getLeft() const;
        void setLeft(Expression<T>* o);
        Expression<T>* getRight() const;
        void setRight(Expression<T>* o);
    };

    template<typename T>
    T *BinaryExpressionModel<T>::evaluate() const {
        if(left != NULL && right != NULL)
            return operatorBinaryExpression->evaluate(left,right);
        return nullptr;
    }

    template<typename T>
    T *BinaryExpressionModel<T>::evaluate(Expression<T> *l, Expression<T> *r) const {
        if(operatorBinaryExpression != NULL)
            return evaluate(l,r);
        return nullptr;
    }

    template<typename T>
    BinaryExpression<T>* BinaryExpressionModel<T>::getOperator() const {
        return operatorBinaryExpression;
    }

    template<typename T>
    void BinaryExpressionModel<T>::setOperator(BinaryExpression<T> *o) {
        operatorBinaryExpression = o;
    }

    template<typename T>
    Expression<T>* BinaryExpressionModel<T>::getLeft() const {
        return left;
    }

    template<typename T>
    void BinaryExpressionModel<T>::setLeft(Expression<T>* o) {
        left = o;
    }

    template<typename T>
    Expression<T>* BinaryExpressionModel<T>::getRight() const {
        return right;
    }

    template<typename T>
    void BinaryExpressionModel<T>::setRight(Expression<T>* o) {
        right = o;
    }

}

#endif //FUZZYLOGIC_BINARYEXPRESSIONMODEL_H
