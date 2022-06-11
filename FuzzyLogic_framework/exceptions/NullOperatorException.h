#ifndef LOCAL_NULLOPERATOREXCEPTION_H
#define LOCAL_NULLOPERATOREXCEPTION_H
#include <stdexcept>

namespace fuzzyLogic::core::op {
    struct NullOperatorException : public std::runtime_error {
        NullOperatorException(const std::string &msg) : std::runtime_error(msg) {}

        const char *what() const _GLIBCXX_USE_NOEXCEPT {
            return std::runtime_error::what();
        }
    };
}
#endif //LOCAL_NULLOPERATOREXCEPTION_H