#ifndef T_2D_VECTOR_ENTITY_H
#define T_2D_VECTOR_ENTITY_H

#include "t_2d_container_entity.h"


using t_2d_vector_value     = float;

using t_2d_vector_length    = t_2d_vector_value;

using t_2d_vector_entity    = t_2d_container<t_2d_vector_value>;

using t_2d_scalar_value     = float;

bool operator!=(const t_2d_vector_entity lhs, const t_2d_vector_entity rhs);

#endif // T_2D_VECTOR_ENTITY_H
