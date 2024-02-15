#ifndef T_2D_COMMON_ENTITIES_H
#define T_2D_COMMON_ENTITIES_H

#include <cmath>
#include "t_2d_container_entity.h"


using t_2d_axis_value           = float;

using t_2d_vector_axis_value    = t_2d_axis_value;

using t_2d_vector_entity        = t_2d_container<t_2d_vector_axis_value>;

using t_2d_vector_length_entity = t_2d_axis_value;

using p_2d_scalar_entity        = t_2d_axis_value;

using t_2d_position_axis_value  = t_2d_axis_value;

using t_2d_position_entity      = t_2d_container<t_2d_position_axis_value>;


template <typename t_angle, typename = std::enable_if_t<std::is_floating_point<t_angle>::value>>
t_angle t_convert_from_degrees_to_radians(const t_angle angle_degrees) {
    return angle_degrees * t_angle { M_PI } / t_angle { 180. };
}

template <typename t_value, typename = std::enable_if_t<std::is_floating_point<t_value>::value>>
bool t_compare_floating(t_value lhs, t_value rhs) {
    return std::abs(lhs - rhs) <= std::numeric_limits<t_value>::epsilon();
}

template <typename t_value, typename = std::enable_if_t<std::is_floating_point<t_value>::value>>
bool t_fast_compare_floating(t_value lhs, t_value rhs) {
    return lhs == rhs;
}

#endif // T_2D_COMMON_ENTITIES_H
