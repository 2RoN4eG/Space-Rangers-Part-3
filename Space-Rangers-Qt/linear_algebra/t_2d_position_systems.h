#ifndef T_2D_POSITION_SYSTEMS_H
#define T_2D_POSITION_SYSTEMS_H

#include "t_2d_position_entity.h"
#include "t_2d_vector_entity.h"


t_2d_position position_addition_system(const t_2d_position& lhs, const t_2d_position& rhs);

t_2d_position position_subtraction_system(const t_2d_position& lhs, const t_2d_position& rhs);

t_2d_vector_entity make_2d_vector(const t_2d_position& from, const t_2d_position& to);

#endif // T_2D_POSITION_SYSTEMS_H
