#include "t_2d_vector_systems.h"

#include "run_test_store_exception.h"

#include <cmath>
#include <iostream>


bool are_vectors_collinear_system(const t_2d_vector_entity lhs, const t_2d_vector_entity rhs) {
    return {};
}


t_2d_vector_entity t_2d_vector_addition_system(const t_2d_vector_entity lhs, const t_2d_vector_entity rhs) {
    return { lhs.x() + rhs.x(), lhs.y() + rhs.y() };
}

t_2d_vector_entity t_2d_vector_subtraction_system(const t_2d_vector_entity lhs, const t_2d_vector_entity rhs) {
    return { lhs.x() - rhs.x(), lhs.y() - rhs.y() };
}


t_2d_vector_length t_2d_vector_length_system(const t_2d_vector_entity vector) {
    return t_2d_vector_length { std::sqrtf(vector.x() * vector.x() + vector.y() * vector.y()) };
}


t_2d_vector_entity t_2d_vector_multiplication_system(const t_2d_vector_entity vector, const t_2d_scalar_value scalar) {
    return { vector.x() * scalar, vector.y() * scalar };
}

t_2d_vector_entity t_2d_vector_division_system(const t_2d_vector_entity vector, const t_2d_scalar_value scalar) {
    return { vector.x() / scalar, vector.y() / scalar };
}

//

void test_are_vectors_collinear_system(const t_2d_vector_entity lhs, const t_2d_vector_entity rhs, const bool must_be_collinears) {
    if (are_vectors_collinear_system(lhs, rhs) != must_be_collinears) {
        throw std::runtime_error { "are_vectors_collinear does not equal with 'must_be' value" };
    }
}

void test_2d_vector_addition_system(const t_2d_vector_entity lhs, const t_2d_vector_entity rhs, const t_2d_vector_entity vector_must_be) {
    if (t_2d_vector_addition_system(lhs, rhs) != vector_must_be) {
        throw std::runtime_error { "result of vector addition does not equal with 'must_be' vector" };
    }
}

void test_2d_vector_subtraction_system(const t_2d_vector_entity lhs, const t_2d_vector_entity rhs, const t_2d_vector_entity vector_must_be) {
    if (t_2d_vector_subtraction_system(lhs, rhs) != vector_must_be) {
        throw std::runtime_error { "result of vector_subtraction does not equal with 'must_be' vector" };
    }
}

void test_2d_vector_length_system(const t_2d_vector_entity vector, const t_2d_vector_length vector_length_must_be) {
    if (t_2d_vector_length_system(vector) != vector_length_must_be) {
        throw std::runtime_error { "vector_length does not equal with 'vector_length_must_be' value" };
    }
}

void test_2d_vector_multiplication_system(const t_2d_vector_entity vector, const t_2d_scalar_value scalar, const t_2d_vector_entity vector_length_must_be) {
    if (t_2d_vector_multiplication_system(vector, scalar) != vector_length_must_be) {
        throw std::runtime_error { "result of vector multiplication does not equal with 'vector_length_must_be' value" };
    }
}

void test_2d_vector_division_system(const t_2d_vector_entity vector, const t_2d_scalar_value scalar, const t_2d_vector_entity vector_length_must_be) {
    if (t_2d_vector_division_system(vector, scalar) != vector_length_must_be) {
        throw std::runtime_error { "result of vector division does not equal with 'vector_length_must_be' value" };
    }
}


void complex_test_2d_vector_systems(std::vector<std::runtime_error>& errors) {
    run_test_store_exceptions(errors, test_2d_vector_addition_system,       t_2d_vector_entity { 0., 0. }, t_2d_vector_entity { 1., 1. }, t_2d_vector_entity { 1., 1. });

    run_test_store_exceptions(errors, test_2d_vector_subtraction_system,    t_2d_vector_entity { 1., 1. }, t_2d_vector_entity { 0., 0. }, t_2d_vector_entity { 1., 1. });

    run_test_store_exceptions(errors, test_2d_vector_length_system,         t_2d_vector_entity { 1., 0. }, t_2d_vector_length { 1. });
    run_test_store_exceptions(errors, test_2d_vector_length_system,         t_2d_vector_entity { 0., 1. }, t_2d_vector_length { 1. });
    run_test_store_exceptions(errors, test_2d_vector_length_system,         t_2d_vector_entity { 2., 0. }, t_2d_vector_length { 2. });
    run_test_store_exceptions(errors, test_2d_vector_length_system,         t_2d_vector_entity { 0., 2. }, t_2d_vector_length { 2. });

    run_test_store_exceptions(errors, test_2d_vector_multiplication_system, t_2d_vector_entity { 1., 1. }, t_2d_scalar_value { 1. }, t_2d_vector_entity { 1., 1. });
    run_test_store_exceptions(errors, test_2d_vector_multiplication_system, t_2d_vector_entity { 1., 1. }, t_2d_scalar_value { 2. }, t_2d_vector_entity { 2., 2. });

    run_test_store_exceptions(errors, test_2d_vector_division_system,       t_2d_vector_entity { 1., 1. }, t_2d_scalar_value { 1. }, t_2d_vector_entity { 1., 1. });
    run_test_store_exceptions(errors, test_2d_vector_division_system,       t_2d_vector_entity { 2., 2. }, t_2d_scalar_value { 2. }, t_2d_vector_entity { 1., 1. });
}
