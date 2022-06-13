#ifndef FUZZYLOGIC_SUGENODEFUZZ_H
#define FUZZYLOGIC_SUGENODEFUZZ_H

#include <vector>

#include "core/NaryExpression.h"
#include "core/BinaryShadowExpression.h"
#include "core/BinaryExpressionModel.h"
#include "operator/then/SugenoThen.h"

namespace fuzzyLogic::core::op{
    template<typename T>
    class SugenoDefuzz : public NaryExpression<T>{
    public:
        SugenoDefuzz() = default;
        virtual ~SugenoDefuzz() = default;

        T* evaluate(std::vector<Expression<T>*> *operands) const override;

    };

    template<typename T>
    T *SugenoDefuzz<T>::evaluate(std::vector<Expression<T>*> *operands) const {
        typename std::vector<const core::Expression<T>*>::const_iterator it;

        T numerator = 0, denumerator = 0;
        for(typename std::vector<const core::Expression<T>*>::const_iterator it = operands->begin(); it != operands->end(); it++){
            BinaryExpressionModel<T>* binaryExpressionModel = (BinaryExpressionModel<T>*)(*it);
            BinaryShadowExpression<T>* binaryShadowExpression = (BinaryShadowExpression<T>*)binaryExpressionModel->getOperator();
            SugenoThen<T>* sugenoThen = (SugenoThen<T>*) binaryShadowExpression->getTarget();

        }

        if(denumerator != 0)
            return numerator/denumerator;
        else
            return 0;
    }
}

#endif //FUZZYLOGIC_SUGENODEFUZZ_H
