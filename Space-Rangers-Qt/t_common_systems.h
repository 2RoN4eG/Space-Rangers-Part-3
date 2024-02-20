#ifndef T_COMMON_SYSTEMS_H
#define T_COMMON_SYSTEMS_H

#include "t_common_entities.h"


t_angle_entity t_convert_angle_from_degrees_to_radians_system(const t_angle_entity degrees);

t_angle_entity t_convert_angle_from_radians_to_degrees_system(const t_angle_entity radians);

t_angle_entity t_convert_from_vector_to_degrees_system(const t_2d_vector& vector);

t_2d_heading_entity t_2d_make_heading_by_x_system(const t_angle_entity degrees);

t_2d_heading_entity t_2d_make_heading_by_y_system(const t_angle_entity degrees);

t_2d_position t_2d_make_position_by_x_axis_system(const t_angle_entity degrees, const t_radius_entity radius = 1.);

t_2d_position t_2d_make_position_by_y_axis_system(const t_angle_entity degrees, const t_radius_entity radius = 1.);

t_2d_position t_2d_make_position_by_x_axis_system(const t_angle_entity degrees, const t_radius_entity radius, const t_2d_position& position);

t_2d_position t_2d_make_position_by_y_axis_system(const t_angle_entity degrees, const t_radius_entity radius, const t_2d_position& position);


#endif // T_COMMON_SYSTEMS_H
