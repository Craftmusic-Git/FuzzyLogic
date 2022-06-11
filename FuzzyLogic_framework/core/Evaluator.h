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

        virtual ~Evaluator() = default;
        typedef std::pair<std::vector<T>*, std::vector<T>*> Shape;
        static Shape* buildShape(const T* min, const T* max, const T* step, ValueModel<T>* in, Expression<T>* out);

    };

    template<typename T>
    typename Evaluator<T>::Shape* Evaluator<T>::buildShape(const T* min, const T* max, const T* step, ValueModel<T>* input, Expression<T>* output) {
        if(min == nullptr || max == nullptr || step == nullptr || output == nullptr)
            return new Shape(nullptr, nullptr);
        auto x = new std::vector<T>();
        auto y = new std::vector<T>();
        T* i = new T();
        for(*i = *min; *i < *max; *i += *step){
            if(input != nullptr)
                input->setValue(i);
            y->push_back(*output->evaluate());
            x->push_back(*i);
        }
        return new Shape(x,y);
    }
}

#endif //FUZZYLOGIC_EVALUATOR_H
