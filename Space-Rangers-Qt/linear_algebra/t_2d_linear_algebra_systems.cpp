#include "t_2d_linear_algebra_systems.h"

#include "t_run_test_store_exception.h"

#include <cmath>
#include <iostream>


namespace {
inline t_2d_vector_length t_2d_imlementation_vector_length_system(const t_2d_vector& vector) {
        return t_2d_vector_length { std::sqrtf(vector.x() * vector.x() + vector.y() * vector.y()) };
    }

    inline t_2d_vector t_2d_imlementation_vector_division_system(const t_2d_vector& vector, const t_2d_scalar scalar) {
        return { vector.x() / scalar, vector.y() / scalar };
    }

    inline bool first_imlementation_of_2d_are_vectors_collinear_system(const t_2d_vector& vector, const t_2d_vector& other) {
        return (vector.x() / vector.y()) == (other.x() / other.y());
    }

    inline bool second_imlementation_of_2d_are_vectors_collinear_system(const t_2d_vector& vector, const t_2d_vector& other) {
        return (vector.x() / other.x()) == (vector.y() / other.y());
    }

    inline bool third_imlementation_of_2d_are_vectors_collinear_system(const t_2d_vector& vector, const t_2d_vector& other) {
        return (vector.x() * other.y()) == (other.x() * vector.y());
    }

    inline t_2d_vector t_2d_imlementation_make_vector_system(const t_2d_position& from, const t_2d_position& to) {
        return { t_2d_axis (to.x() - from.x()), t_2d_axis (to.y() - from.y()) };
    }

    inline t_2d_vector t_2d_imlementation_vector_normalization_system(const t_2d_position& vector) {
        const t_2d_vector_length&& vector_length = t_2d_imlementation_vector_length_system(vector);

        return t_2d_imlementation_vector_division_system(vector, vector_length);
    }
}


std::ostream& operator<<(std::ostream& stream, const t_2d_container<t_2d_axis>& container) {
    stream << "x: " << container.x() << ", y: " << container.y();
    return stream;
}


bool t_2d_vector_is_collinear_system(const t_2d_vector& vector, const t_2d_vector& other) {
    return third_imlementation_of_2d_are_vectors_collinear_system(vector, other);
}

t_2d_vector t_2d_vector_addition_system(const t_2d_vector& vector, const t_2d_vector& other) {
    return { vector.x() + other.x(), vector.y() + other.y() };
}

t_2d_vector t_2d_vector_subtraction_system(const t_2d_vector& vector, const t_2d_vector& other) {
    return { vector.x() - other.x(), vector.y() - other.y() };
}

t_2d_vector_length t_2d_vector_length_system(const t_2d_vector& vector) {
    return t_2d_imlementation_vector_length_system(vector);
}

t_2d_vector t_2d_vector_multiplication_system(const t_2d_vector& vector, const t_2d_scalar scalar) {
    return { vector.x() * scalar, vector.y() * scalar };
}

t_2d_vector t_2d_vector_division_system(const t_2d_vector& vector, const t_2d_scalar scalar) {
    return t_2d_imlementation_vector_division_system(vector, scalar);
}

t_2d_vector t_2d_vector_normalization_system(const t_2d_vector& vector) {
    return t_2d_imlementation_vector_normalization_system(vector);
}


bool operator!=(const t_2d_vector& lhs, const t_2d_vector& rhs) {
    return (lhs.x() != rhs.x()) || (lhs.y() != rhs.y());
}

bool operator==(const t_2d_vector& lhs, const t_2d_vector& rhs) {
    return (lhs.x() == rhs.x()) || (lhs.y() == rhs.y());
}


t_2d_position t_2d_position_subtraction_system(const t_2d_position& lhs, const t_2d_position& rhs) {
    return { lhs.x() - rhs.x(), lhs.y() - lhs.y() };
}

t_2d_position t_2d_position_addition_system(const t_2d_position& lhs, const t_2d_position& rhs) {
    return { lhs.x() + rhs.x(), lhs.y() + lhs.y() };
}

t_2d_vector t_2d_system_make_vector(const t_2d_position& from, const t_2d_position& to) {
    return t_2d_imlementation_make_vector_system(from, to);
}

t_2d_vector t_2d_system_make_normalized_vector(const t_2d_position &from, const t_2d_position &to) {
    const t_2d_vector&& vector = t_2d_imlementation_make_vector_system(from, to);

    return t_2d_vector_normalization_system(vector);
}

t_2d_vector_length t_2d_distance_length_system(const t_2d_position& from, const t_2d_position& to) {
    const t_2d_vector&& vector = t_2d_imlementation_make_vector_system(from, to);

    return t_2d_imlementation_vector_length_system(std::move(vector));
}


// testing section

void test_2d_container(const t_2d_axis x, const t_2d_axis y) {
    const t_2d_container<t_2d_axis> vector { x, y };

    if (vector.x() != x) {
        throw std::runtime_error { "vector's x value does not equal with x" };
    }

    if (vector.y() != y) {
        throw std::runtime_error { "vector's y value does not equal with y" };
    }
}

void test_empty_integral_2d_container() {
    test_2d_container({}, {});
}

void complex_test_2d_container_system(std::vector<std::runtime_error>& errors) {
    // run_test_store_exceptions(errors, test_2d_container, t_2d_axis { 1. }, t_2d_axis { 1. });

    // run_test_store_exceptions(errors, test_empty_integral_2d_container);
}


void test_2d_vector_is_collinear_system(const t_2d_vector& vector, const t_2d_vector& other, const bool must_be) {
    if (const bool are_collinear = t_2d_vector_is_collinear_system(vector, other); are_collinear != must_be) {
        std::cout << "result of t_2d_vector_is_collinear_system { " << (are_collinear ? "true" : "false")
                  << " } does not equal with 'must_be' value { " << (must_be ? "true" : "false") << " }"
                  << std::endl;
        throw std::runtime_error { "result of t_2d_vector_is_collinear_system does not equal with 'must_be' value" };
    }
}

void test_2d_vector_addition_system(const t_2d_vector& vector, const t_2d_vector& other, const t_2d_vector& must_be) {
    if (t_2d_vector_addition_system(vector, other) != must_be) {
        throw std::runtime_error { "result of vector addition does not equal with 'must_be' vector" };
    }
}

void test_2d_vector_subtraction_system(const t_2d_vector& vector, const t_2d_vector& other, const t_2d_vector& must_be) {
    if (t_2d_vector_subtraction_system(vector, other) != must_be) {
        throw std::runtime_error { "result of t_2d_vector_subtraction_system does not equal with 'must_be' vector" };
    }
}

void test_2d_vector_length_system(const t_2d_vector& vector, const t_2d_vector_length vector_length_must_be) {
    if (t_2d_vector_length_system(vector) != vector_length_must_be) {
        throw std::runtime_error { "vector_length does not equal with 'vector_length_must_be' value" };
    }
}

void test_2d_vector_multiplication_system(const t_2d_vector& vector, const t_2d_scalar scalar, const t_2d_vector& must_be) {
    if (t_2d_vector_multiplication_system(vector, scalar) != must_be) {
        throw std::runtime_error { "result of vector multiplication does not equal with 'vector_length_must_be' value" };
    }
}

void test_2d_vector_division_system(const t_2d_vector& vector, const t_2d_scalar scalar, const t_2d_vector& must_be) {
    if (const t_2d_vector& result = t_2d_vector_division_system(vector, scalar); result != must_be) {
        std::cout << "result of test_2d_vector_division_system { " << result << " }"
                  << " does not equal with 'must_be' value { " << must_be << " }"
                  << std::endl;
        throw std::runtime_error { "result of t_2d_vector_division_system does not equal with 'must_be' value" };
    }
}

void test_2d_vector_normalization_system(const t_2d_vector& vector, const t_2d_vector& must_be) {
    if (const t_2d_vector& result = t_2d_vector_normalization_system(vector); result != must_be) {
        std::cout << "result of 't_2d_vector_normalization_system' { " << result << " }"
                  << " does not equal with 'must_be' value { " << must_be << " }"
                  << std::endl;
        throw std::runtime_error { "result of 't_2d_vector_normalization_system' does not equal with 'must_be' value" };
    }
}

void complex_test_2d_vector_systems(std::vector<std::runtime_error>& errors) {
    // run_test_store_exceptions(errors, test_2d_vector_is_collinear_system,   t_2d_vector { 3., 4. }, t_2d_vector { 6., 8. }, true);

    // run_test_store_exceptions(errors, test_2d_vector_addition_system,       t_2d_vector { 0., 0. }, t_2d_vector { 1., 1. }, t_2d_vector { 1., 1. });

    // run_test_store_exceptions(errors, test_2d_vector_subtraction_system,    t_2d_vector { 1., 1. }, t_2d_vector { 0., 0. }, t_2d_vector { 1., 1. });

    // run_test_store_exceptions(errors, test_2d_vector_length_system,         t_2d_vector { 1., 0. }, t_2d_vector_length { 1. });
    // run_test_store_exceptions(errors, test_2d_vector_length_system,         t_2d_vector { 0., 1. }, t_2d_vector_length { 1. });
    // run_test_store_exceptions(errors, test_2d_vector_length_system,         t_2d_vector { 2., 0. }, t_2d_vector_length { 2. });
    // run_test_store_exceptions(errors, test_2d_vector_length_system,         t_2d_vector { 0., 2. }, t_2d_vector_length { 2. });

    // run_test_store_exceptions(errors, test_2d_vector_multiplication_system, t_2d_vector { 1., 1. }, t_2d_scalar { 1. }, t_2d_vector { 1., 1. });
    // run_test_store_exceptions(errors, test_2d_vector_multiplication_system, t_2d_vector { 1., 1. }, t_2d_scalar { 2. }, t_2d_vector { 2., 2. });

    // run_test_store_exceptions(errors, test_2d_vector_division_system,       t_2d_vector { 1., 1. }, t_2d_scalar { 1. }, t_2d_vector { 1., 1. });
    // run_test_store_exceptions(errors, test_2d_vector_division_system,       t_2d_vector { 2., 2. }, t_2d_scalar { 2. }, t_2d_vector { 1., 1. });

    // run_test_store_exceptions(errors, test_2d_vector_normalization_system,  t_2d_vector { 3., 4. }, t_2d_vector { 3. / 5., 4. / 5. });
}
