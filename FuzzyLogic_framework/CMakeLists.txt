# 'FuzzyLogic_framework' is the subproject name
project(FuzzyLogic_Framework)

set(HEADER_FILES
        core/BinaryExpression.h
        core/Expression.h
        core/UnaryExpression.h
        core/ValueModel.h
        )

set(SOURCE_FILES )

add_library(FuzzyLogicFramework STATIC ${SOURCE_FILES} ${HEADER_FILES})
set_target_properties(FuzzyLogicFramework PROPERTIES LINKER_LANGUAGE CXX)
