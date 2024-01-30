#ifndef T_2D_COMMON_UTILITIES_H
#define T_2D_COMMON_UTILITIES_H

#include "t_2d_container_entity.h"

#include <cmath>

template <typename t_angle
         , typename = std::enable_if_t<std::is_floating_point<t_angle>::value>
         >
t_angle angle_from_degrees(const t_angle degrees) {
    return degrees * 3.14159 / 180;
}

#endif // T_2D_COMMON_UTILITIES_H
