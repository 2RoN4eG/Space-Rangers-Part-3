#include "t_2d_container_entity.h"

#include "run_test_store_exception.h"

template <typename t_vector_value, typename std::enable_if_t<std::is_integral_v<t_vector_value>, bool> = true>
void test_2d_container(const t_vector_value x, const t_vector_value y) {
    const t_2d_container<t_vector_value> vector { x, y };

    if (vector.x() != x) { throw std::runtime_error { "vector's x value does not equal with x" }; }

    if (vector.y() != y) { throw std::runtime_error { "vector's y value does not equal with y" }; }
}

void test_empty_integral_2d_container() { test_2d_container<int>({}, {}); }

void complex_test_2d_container(std::vector<std::runtime_error>& errors) {
    run_test_store_exceptions(errors, test_2d_container<int>, 1, 1);

    run_test_store_exceptions(errors, test_empty_integral_2d_container);
}
