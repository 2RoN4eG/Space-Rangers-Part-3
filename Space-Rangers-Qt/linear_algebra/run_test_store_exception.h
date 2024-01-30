#ifndef RUN_TEST_STORE_EXCEPTION_H
#define RUN_TEST_STORE_EXCEPTION_H

#include <vector>

template <typename ...t_arguments>
inline void run_test_store_exceptions(std::vector<std::runtime_error>& exceptions, void (*testable)(t_arguments ...), t_arguments ...arguments) {
    try {
        testable(std::forward<t_arguments>(arguments) ...);
    }
    catch (const std::runtime_error& exception) {
        exceptions.emplace_back(std::move(exception));
    }
}

#endif // RUN_TEST_STORE_EXCEPTION_H
