#ifndef T_2D_VECTOR_ENTITY_H
#define T_2D_VECTOR_ENTITY_H

#include "t_2d_container_entity.h"
#include "t_2d_common.h"

using t_2d_vector_length    = t_2d_default_axis;

using t_2d_vector_entity    = t_2d_container<t_2d_default_axis>;

using p_2d_scalar_entity    = t_2d_default_axis;

bool operator!=(const t_2d_vector_entity lhs, const t_2d_vector_entity rhs);

bool operator==(const t_2d_vector_entity lhs, const t_2d_vector_entity rhs);

#endif // T_2D_VECTOR_ENTITY_H
