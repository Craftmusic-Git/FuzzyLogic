#ifndef FUZZYLOGIC_EXPRESSIONFACTORY_H
#define FUZZYLOGIC_EXPRESSIONFACTORY_H

#include <list>

#include "UnaryExpressionModel.h"
#include "BinaryExpressionModel.h"
#include "NaryExpression.h"
#include "ValueModel.h"

namespace fuzzyLogic {
    namespace core {

        template <typename T>
        class ExpressionFactory {
        private:


        public:
            ExpressionFactory();
            virtual ~ExpressionFactory() = default;

            UnaryExpressionModel<T>* newUnary(UnaryExpression<T>* op = nullptr, Expression<T>* operand = nullptr);
            BinaryExpressionModel<T>* newBinary(BinaryExpression<T>* op = nullptr, Expression<T>* left = nullptr, Expression<T>* right = nullptr);
            ValueModel<T>* newValue(const T& value);

        protected:
            void hold(Expression<T>* exp);
            std::vector<Expression<T>*>* memory;
        };

        template<typename T>
        UnaryExpressionModel<T> *ExpressionFactory<T>::newUnary(UnaryExpression<T> *op, Expression<T> *operand) {
            auto* exp = new UnaryExpressionModel<T>();
            exp->setOperator(op);
            exp->setOperand(operand);
            hold(exp);
            return exp;
        }

        template<typename T>
        BinaryExpressionModel<T> *
        ExpressionFactory<T>::newBinary(BinaryExpression<T> *op, Expression<T> *left, Expression<T> *right) {
            auto* exp = new BinaryExpressionModel<T>();
            exp->setOperator(op);
            exp->setLeft(left);
            exp->setRight(right);
            hold(exp);
            return exp;
        }

        template<typename T>
        void ExpressionFactory<T>::hold(Expression<T> *exp) {
            memory->push_back(exp);
        }

        template<typename T>
        ValueModel<T> *ExpressionFactory<T>::newValue(const T &value) {
            auto* exp = new ValueModel<T>(value);
            hold(exp);
            return exp;
        }

        template<typename T>
        ExpressionFactory<T>::ExpressionFactory(){
            memory = new std::vector<Expression<T>*>();
        }

    } // fuzzyLogic
} // core

#endif //FUZZYLOGIC_EXPRESSIONFACTORY_H
