#ifndef T_2D_COMMON_H
#define T_2D_COMMON_H

#include <cmath>


using t_2d_default_axis = float;


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

#endif // T_2D_COMMON_H
