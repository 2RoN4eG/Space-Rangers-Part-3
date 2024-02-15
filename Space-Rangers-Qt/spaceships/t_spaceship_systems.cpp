#include "t_spaceship_systems.h"

#include "../linear_algebra/t_2d_common_entities.h"
#include "../t_common_entities.h"

#include <cmath>

t_heading_entity create_2d_heading_by_x(const t_angle_entity degrees) {
    const t_angle_entity angle = t_convert_from_degrees_to_radians(degrees);

    return { std::cos(angle), std::sin(angle) };
}

t_heading_entity create_2d_heading_by_y(const t_angle_entity degrees) {
    return create_2d_heading_by_x(degrees + t_angle_entity { 90 });
}
