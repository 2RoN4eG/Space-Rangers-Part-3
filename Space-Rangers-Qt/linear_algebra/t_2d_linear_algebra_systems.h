#ifndef T_2D_LINEAR_ALGEBRA_SYSTEMS_H
#define T_2D_LINEAR_ALGEBRA_SYSTEMS_H

#include "t_2d_linear_algebra_entities.h"


std::ostream& operator<<(std::ostream& stream, const t_2d_container<t_2d_axis>& container);


bool t_2d_vector_are_collinear_system(const t_2d_vector& lhs, const t_2d_vector& rhs);


t_2d_vector t_2d_vector_addition_system(const t_2d_vector& lhs, const t_2d_vector& rhs);

t_2d_vector t_2d_vector_subtraction_system(const t_2d_vector& lhs, const t_2d_vector& rhs);


t_2d_vector_length t_2d_vector_length_system(const t_2d_vector& vector);


t_2d_vector t_2d_vector_multiplication_system(const t_2d_vector& vector, const t_2d_scalar scalar);

t_2d_vector t_2d_vector_division_system(const t_2d_vector& vector, const t_2d_scalar scalar);


t_2d_vector t_2d_vector_normalization_system(const t_2d_vector& vector);


bool operator!=(const t_2d_vector& lhs, const t_2d_vector& rhs);

bool operator==(const t_2d_vector& lhs, const t_2d_vector& rhs);


t_2d_position t_2d_position_addition_system(const t_2d_position& lhs, const t_2d_position& rhs);

t_2d_position t_2d_position_subtraction_system(const t_2d_position& lhs, const t_2d_position& rhs);

t_2d_vector t_2d_system_make_vector(const t_2d_position& from, const t_2d_position& to);

t_2d_vector t_2d_system_make_normalized_vector(const t_2d_position& from, const t_2d_position& to);

t_2d_vector_length t_2d_distance_length_system(const t_2d_position& from, const t_2d_position& to);


void complex_test_2d_container_system(std::vector<std::runtime_error>& errors);

void complex_test_2d_vector_systems(std::vector<std::runtime_error>& errors);


#endif // T_2D_LINEAR_ALGEBRA_SYSTEMS_H
