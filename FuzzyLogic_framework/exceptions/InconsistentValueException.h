#ifndef FUZZYLOGIC_INCONSISTENTVALUEEXCEPTION_H
#define FUZZYLOGIC_INCONSISTENTVALUEEXCEPTION_H

#include <stdexcept>

namespace fuzzyLogic::core::op {
    struct InconsistentValueException : public std::runtime_error {
        InconsistentValueException(const std::string &msg) : std::runtime_error(msg) {}

        const char *what() const _GLIBCXX_USE_NOEXCEPT {
            return std::runtime_error::what();
        }
    };
}
#endif //FUZZYLOGIC_INCONSISTENTVALUEEXCEPTION_H