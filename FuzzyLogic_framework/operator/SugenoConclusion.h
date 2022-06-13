#ifndef FUZZYLOGIC_SUGENOCONCLUSION_H
#define FUZZYLOGIC_SUGENOCONCLUSION_H

#include <vector>

#include "core/NaryExpression.h"

namespace fuzzyLogic::core::op{
    template<typename T>
    class SugenoConclusion : public NaryExpression<T>{
    public:
        SugenoConclusion() = default;
        explicit SugenoConclusion(std::vector<T*>* coeff);

        virtual ~SugenoConclusion() = default;

        T* evaluate(std::vector<Expression<T>*> *operands) const override;
    private:
        const std::vector<T*> *coeff;
    };

    template<typename T>
    T *SugenoConclusion<T>::evaluate(std::vector<Expression<T>*> *operands) const {
        typename std::vector<T*>::const_iterator itcoef = coeff->begin();
        typename std::vector<Expression<T>*>::const_iterator itexpr = operands->begin();

        T somme;

        for(;itexpr != operands->end() && itcoef != coeff->end(); itexpr++, itcoef++){
            T* eval = (*itexpr)->evaluate();
            somme += (*itcoef) * *eval;
        }

        return somme;
    }

    template<typename T>
    SugenoConclusion<T>::SugenoConclusion(std::vector<T *> *coeff) : coeff(coeff) { }
}

#endif //FUZZYLOGIC_SUGENOCONCLUSION_H
