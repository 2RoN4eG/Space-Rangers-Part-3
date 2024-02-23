#include "t_common_systems.h"

#include <cmath>

#include "linear_algebra/t_2d_linear_algebra_systems.h"


t_scalar_angle_entity convert_angle_from_degrees_to_radians(const t_scalar_angle_entity degrees) {
    return degrees * t_scalar_angle_entity { M_PI } / t_scalar_angle_entity { 180. };
}

t_scalar_angle_entity convert_angle_from_radians_to_degrees(const t_scalar_angle_entity radians) {
    return radians * t_scalar_angle_entity { 180. } / t_scalar_angle_entity { M_PI };
}

t_scalar_angle_entity convert_from_vector_to_radians(const t_2d_vector_entity& vector) {
    return std::atan2(vector.y(), vector.x());
}

t_scalar_angle_entity convert_from_vector_to_degrees(const t_2d_vector_entity& vector) {
    const t_scalar_angle_entity radians = convert_from_vector_to_radians(vector);

    return convert_angle_from_radians_to_degrees(radians);
}

t_2d_heading_entity make_2d_heading_by_x(const t_scalar_angle_entity degrees) {
    const t_scalar_angle_entity radians = convert_angle_from_degrees_to_radians(degrees);

    return { std::cos(radians), std::sin(radians) };
}

t_2d_heading_entity make_2d_heading_by_y(const t_scalar_angle_entity degrees) {
    return make_2d_heading_by_x(degrees + t_scalar_angle_entity { 90. });
}

t_2d_position_entity make_2d_position_by_x_axis(const t_scalar_angle_entity degrees, const t_radius_entity radius) {
    const t_scalar_angle_entity radians = convert_angle_from_degrees_to_radians(degrees);

    return { radius * std::cos(radians), radius * std::sin(radians) };
}

t_2d_position_entity make_2d_position_by_y_axis(const t_scalar_angle_entity degrees, const t_radius_entity radius) {
    return make_2d_position_by_x_axis(degrees + t_scalar_angle_entity { 90. }, radius);
}

t_2d_position_entity make_2d_position_by_x_axis(const t_scalar_angle_entity degrees, const t_radius_entity radius, const t_2d_position_entity& around) {
    const t_2d_position_entity&& position = make_2d_position_by_x_axis(degrees, radius);

    return t_2d_vector_addition_system(around, position);
}

t_2d_position_entity make_2d_position_by_y_axis(const t_scalar_angle_entity degrees, const t_radius_entity radius, const t_2d_position_entity& around) {
    const t_2d_position_entity&& position = make_2d_position_by_y_axis(degrees, radius);

    return t_2d_vector_addition_system(around, position);
}
