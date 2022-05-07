# 'FuzzyLogic_framework' is the subproject name
project(FuzzyLogic_Framework)

set(HEADER_FILES
        core/BinaryExpression.h
        core/Expression.h
        core/UnaryExpression.h
        core/ValueModel.h
        core/UnaryExpressionModel.h core/BinaryExpressionModel.h operator/and/And.h operator/and/AndMin.h operator/and/AndMult.h operator/or/OrMax.h operator/or/Or.h operator/or/OrPlus.h operator/is/Is.h)

set(SOURCE_FILES )

add_library(FuzzyLogicFramework STATIC ${SOURCE_FILES} ${HEADER_FILES})
set_target_properties(FuzzyLogicFramework PROPERTIES LINKER_LANGUAGE CXX)
