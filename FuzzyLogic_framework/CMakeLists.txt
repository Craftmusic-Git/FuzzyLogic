# 'FuzzyLogic_framework' is the subproject name
project(FuzzyLogic_Framework)

set(HEADER_FILES
        core/BinaryExpression.h
        core/Expression.h
        core/UnaryExpression.h
        core/ValueModel.h
        core/UnaryExpressionModel.h
        core/BinaryExpressionModel.h
        operator/and/And.h
        operator/and/AndMin.h
        operator/and/AndMult.h
        operator/or/OrMax.h
        operator/or/Or.h
        operator/or/OrPlus.h
        operator/is/Is.h
        operator/is/IsTriangle.h
        operator/then/Then.h
        operator/then/ThenMin.h
        operator/then/ThenMult.h
        operator/agg/Agg.h
        operator/agg/AggMax.h
        operator/agg/AggPlus.h
        core/Evaluator.h
        operator/not/NotMinus1.h
        operator/not/Not.h
        operator/MamdaniDefuzz.h
        operator/CogDefuzz.h
        core/NaryExpression.h
        core/UnaryShadowExpression.h
        core/BinaryShadowExpression.h
        core/ExpressionFactory.h
        core/FuzzyFactory.h
        FuzzyLogic.h
        exceptions/NullParameterException.h
        exceptions/InconsistentValueException.h
        operator/is/IsTrapeze.h
        operator/is/IsSigmoid.h
        operator/is/IsLinear.h
        operator/is/IsGeneralizedBell.h
        operator/is/IsGaussian.h operator/is/IsSigmoidLeft.h operator/is/IsTrapezeLeft.h operator/is/IsTrapezeRight.h operator/CosDefuzz.h operator/LomDefuzz.h operator/FomDefuzz.h operator/then/SugenoThen.h operator/SugenoDefuzz.h operator/SugenoConclusion.h)

set(SOURCE_FILES operator/is/IsRectangle.h operator/is/IsSingleton.h)

add_library(FuzzyLogicFramework STATIC ${SOURCE_FILES} ${HEADER_FILES})
set_target_properties(FuzzyLogicFramework PROPERTIES LINKER_LANGUAGE CXX)
