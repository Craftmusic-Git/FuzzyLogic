#ifndef LOGIQUEFLOU_EXPRESSION_H
#define LOGIQUEFLOU_EXPRESSION_H

namespace fuzzyLogic::core {
    template<typename T>
    class Expression {
    public:
        virtual T* evaluate() const = 0;
    };
}

#endif //LOGIQUEFLOU_EXPRESSION_H
