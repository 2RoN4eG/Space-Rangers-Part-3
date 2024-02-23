#ifndef T_COMMON_SYSTEMS_H
#define T_COMMON_SYSTEMS_H

#include "t_common_entities.h"


t_scalar_angle_entity convert_angle_from_degrees_to_radians(const t_scalar_angle_entity degrees);

t_scalar_angle_entity convert_angle_from_radians_to_degrees(const t_scalar_angle_entity radians);

t_scalar_angle_entity convert_from_vector_to_degrees(const t_2d_vector_entity& vector);

t_2d_heading_entity make_2d_heading_by_x(const t_scalar_angle_entity degrees);

t_2d_heading_entity make_2d_heading_by_y(const t_scalar_angle_entity degrees);

t_2d_position_entity make_2d_position_by_x_axis(const t_scalar_angle_entity degrees, const t_radius_entity radius = 1.);

t_2d_position_entity make_2d_position_by_y_axis(const t_scalar_angle_entity degrees, const t_radius_entity radius = 1.);

t_2d_position_entity make_2d_position_by_x_axis(const t_scalar_angle_entity degrees, const t_radius_entity radius, const t_2d_position_entity& position);

t_2d_position_entity make_2d_position_by_y_axis(const t_scalar_angle_entity degrees, const t_radius_entity radius, const t_2d_position_entity& position);


#endif // T_COMMON_SYSTEMS_H
