#ifndef LOCAL_NULLPARAMETEREXCEPTION_H
#define LOCAL_NULLPARAMETEREXCEPTION_H
#include <stdexcept>

namespace fuzzyLogic::core::op {
    struct NullParameterException : public std::runtime_error {
        NullParameterException(const std::string &msg) : std::runtime_error(msg) {}

        const char *what() const _GLIBCXX_USE_NOEXCEPT {
            return std::runtime_error::what();
        }
    };
}
#endif //LOCAL_NULLPARAMETEREXCEPTION_H