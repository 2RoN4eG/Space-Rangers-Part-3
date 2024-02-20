#ifndef T_2D_LINEAR_ALGEBRA_SYSTEMS_H
#define T_2D_LINEAR_ALGEBRA_SYSTEMS_H

#include "t_2d_linear_algebra_entities.h"


bool t_2d_vector_are_collinear_system(const t_2d_vector_entity& lhs, const t_2d_vector_entity& rhs);

t_2d_vector_entity t_2d_vector_addition_system(const t_2d_vector_entity& lhs, const t_2d_vector_entity& rhs);

t_2d_vector_entity t_2d_vector_subtraction_system(const t_2d_vector_entity& lhs, const t_2d_vector_entity& rhs);

t_2d_length_entity t_2d_vector_length_system(const t_2d_vector_entity& vector);

t_2d_vector_entity t_2d_vector_multiplication_system(const t_2d_vector_entity& vector, const t_2d_scalar_entity scalar);

t_2d_vector_entity t_2d_vector_division_system(const t_2d_vector_entity& vector, const t_2d_scalar_entity scalar);

t_2d_vector_entity normalize_vector_system(const t_2d_vector_entity& vector);


// TODO: Merge with t_2d_vector_addition_system
t_2d_position_entity t_2d_position_addition_system(const t_2d_position_entity& lhs, const t_2d_position_entity& rhs);

// TODO: Merge with t_2d_vector_subtraction_system
t_2d_position_entity t_2d_position_subtraction_system(const t_2d_position_entity& lhs, const t_2d_position_entity& rhs);

t_2d_vector_entity make_vector_2d_system(const t_2d_position_entity& from, const t_2d_position_entity& to);

t_2d_vector_entity normalize_vector_system(const t_2d_position_entity& from, const t_2d_position_entity& to);

t_2d_distance_entity make_distance_system(const t_2d_position_entity& from, const t_2d_position_entity& to);


bool operator!=(const t_2d_vector_entity& lhs, const t_2d_vector_entity& rhs);

bool operator==(const t_2d_vector_entity& lhs, const t_2d_vector_entity& rhs);


std::ostream& operator<<(std::ostream& stream, const t_2d_container<t_2d_axis>& container);


void complex_test_2d_container_system(std::vector<std::runtime_error>& errors);

void complex_test_2d_vector_systems(std::vector<std::runtime_error>& errors);


#endif // T_2D_LINEAR_ALGEBRA_SYSTEMS_H
