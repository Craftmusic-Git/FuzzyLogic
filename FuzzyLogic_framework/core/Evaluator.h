#ifndef FUZZYLOGIC_EVALUATOR_H
#define FUZZYLOGIC_EVALUATOR_H

#include <vector>
#include <utility>

#include "core/Expression.h"
#include "core/ValueModel.h"

namespace fuzzyLogic::core {
    template<typename T>
    class Evaluator {
    public:
        typedef std::pair<std::vector<T>*, std::vector<T>*> Shape;
        static Shape* buildShape(const T* min, const T* max, const T* step, ValueModel<T>* in, Expression<T>* out);

    };

    template<typename T>
    typename Evaluator<T>::Shape* Evaluator<T>::buildShape(const T* min, const T* max, const T* step, ValueModel<T>* input, Expression<T>* output) {
        if(min == nullptr || max == nullptr || step == nullptr || input == nullptr || output == nullptr)
            return new Shape(nullptr, nullptr);
        auto x = new std::vector<T>();
        auto y = new std::vector<T>();
        T* i = new T();
        for(*i = *min; *i <= *max; *i += *step){
            input->setValue(i);
            x->push_back(*output->evaluate());
            y->push_back(*i);
        }
        return new Shape(y,x);
    }
}

#endif //FUZZYLOGIC_EVALUATOR_H