#ifndef FUZZYLOGIC_FUZZYLOGIC_H
#define FUZZYLOGIC_FUZZYLOGIC_H

// FuzzyLogic core Framework elements

#include "core/BinaryExpression.h"
#include "core/BinaryExpressionModel.h"
#include "core/BinaryShadowExpression.h"
#include "core/Evaluator.h"
#include "core/Expression.h"
#include "core/ExpressionFactory.h"
#include "core/FuzzyFactory.h"
#include "core/NaryExpression.h"
#include "core/UnaryExpression.h"
#include "core/UnaryExpressionModel.h"
#include "core/UnaryShadowExpression.h"
#include "core/ValueModel.h"

// FuzzyLogic All Operators

#include "operator/CogDefuzz.h"
#include "operator/MamdaniDefuzz.h"
#include "operator/agg/Agg.h"
#include "operator/agg/AggMax.h"
#include "operator/agg/AggPlus.h"
#include "operator/and/And.h"
#include "operator/and/AndMin.h"
#include "operator/and/AndMult.h"
#include "operator/is/Is.h"
#include "operator/is/IsTriangle.h"
#include "operator/is/IsRectangle.h"
#include "operator/not/Not.h"
#include "operator/not/NotMinus1.h"
#include "operator/or/Or.h"
#include "operator/or/OrMax.h"
#include "operator/or/OrPlus.h"
#include "operator/then/Then.h"
#include "operator/then/ThenMin.h"
#include "operator/then/ThenMult.h"


#endif //FUZZYLOGIC_FUZZYLOGIC_H
