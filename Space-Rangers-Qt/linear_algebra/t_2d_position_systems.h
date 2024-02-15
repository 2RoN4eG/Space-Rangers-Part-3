#ifndef T_2D_POSITION_SYSTEMS_H
#define T_2D_POSITION_SYSTEMS_H

#include "t_2d_common_entities.h"


t_2d_position_entity t_2d_position_addition_system(const t_2d_position_entity& lhs, const t_2d_position_entity& rhs);

t_2d_position_entity t_2d_position_subtraction_system(const t_2d_position_entity& lhs, const t_2d_position_entity& rhs);

t_2d_vector_entity t_make_2d_vector_system(const t_2d_position_entity& from, const t_2d_position_entity& to);

t_2d_vector_length_entity t_2d_distance_length_system(const t_2d_position_entity& from, const t_2d_position_entity& to);

#endif // T_2D_POSITION_SYSTEMS_H
