#ifndef T_2D_VECTOR_SYSTEMS_H
#define T_2D_VECTOR_SYSTEMS_H

#include "t_2d_vector_entity.h"


bool t_2d_vector_collinear_system(const t_2d_vector_entity lhs, const t_2d_vector_entity rhs);


t_2d_vector_entity t_2d_vector_addition_system(const t_2d_vector_entity lhs, const t_2d_vector_entity rhs);

t_2d_vector_entity t_2d_vector_subtraction_system(const t_2d_vector_entity lhs, const t_2d_vector_entity rhs);


t_2d_vector_length t_2d_vector_length_system(const t_2d_vector_entity vector);


t_2d_vector_entity t_2d_vector_multiplication_system(const t_2d_vector_entity vector, const p_2d_scalar_entity scalar);

t_2d_vector_entity t_2d_vector_division_system(const t_2d_vector_entity vector, const p_2d_scalar_entity scalar);


t_2d_vector_entity t_2d_vector_normalization_system(const t_2d_vector_entity vector);


void complex_test_2d_vector_systems(std::vector<std::runtime_error>& errors);

#endif // T_2D_VECTOR_SYSTEMS_H
