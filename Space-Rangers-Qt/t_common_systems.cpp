#include "t_common_systems.h"

#include <cmath>

#include "linear_algebra/t_2d_linear_algebra_systems.h"


t_angle_entity t_convert_angle_from_degrees_to_radians_system(const t_angle_entity degrees) {
    return degrees * t_angle_entity { M_PI } / t_angle_entity { 180. };
}

t_angle_entity t_convert_angle_from_radians_to_degrees_system(const t_angle_entity radians) {
    return radians * t_angle_entity { 180. } / t_angle_entity { M_PI };
}

t_angle_entity t_convert_from_vector_to_radians_system(const t_2d_vector_entity& vector) {
    return std::atan2(vector.y(), vector.x());
}

t_angle_entity t_convert_from_vector_to_degrees_system(const t_2d_vector_entity& vector) {
    const t_angle_entity radians = t_convert_from_vector_to_radians_system(vector);

    return t_convert_angle_from_radians_to_degrees_system(radians);
}

t_2d_heading_entity t_2d_make_heading_by_x_system(const t_angle_entity degrees) {
    const t_angle_entity radians = t_convert_angle_from_degrees_to_radians_system(degrees);

    return { std::cos(radians), std::sin(radians) };
}

t_2d_heading_entity t_2d_make_heading_by_y_system(const t_angle_entity degrees) {
    return t_2d_make_heading_by_x_system(degrees + t_angle_entity { 90. });
}

t_2d_position_entity t_2d_make_position_by_x_axis_system(const t_angle_entity degrees, const t_radius_entity radius) {
    const t_angle_entity radians = t_convert_angle_from_degrees_to_radians_system(degrees);

    return { radius * std::cos(radians), radius * std::sin(radians) };
}

t_2d_position_entity t_2d_make_position_by_y_axis_system(const t_angle_entity degrees, const t_radius_entity radius) {
    return t_2d_make_position_by_x_axis_system(degrees + t_angle_entity { 90. }, radius);
}

t_2d_position_entity t_2d_make_position_by_x_axis_system(const t_angle_entity degrees, const t_radius_entity radius, const t_2d_position_entity& around) {
    const t_2d_position_entity&& position = t_2d_make_position_by_x_axis_system(degrees, radius);

    return t_2d_vector_addition_system(around, position);
}

t_2d_position_entity t_2d_make_position_by_y_axis_system(const t_angle_entity degrees, const t_radius_entity radius, const t_2d_position_entity& around) {
    const t_2d_position_entity&& position = t_2d_make_position_by_y_axis_system(degrees, radius);

    return t_2d_vector_addition_system(around, position);
}
