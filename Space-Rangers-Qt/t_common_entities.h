#ifndef T_COMMON_ENTITIES_H
#define T_COMMON_ENTITIES_H

#include "linear_algebra/t_2d_container_entity.h"

using t_id = int;


using t_spaceship_id_entity = t_id;
using t_planet_id_entity    = t_id;


constexpr t_spaceship_id_entity t_spaceship_self_id { 0 };


using t_speed_value = int;
using t_speed_entity = t_speed_value;


using t_radial_speed_value = float;
using t_radial_speed_entity = t_radial_speed_value;


using t_default_heading_axis = float;
using t_heading_entity = t_2d_container<t_default_heading_axis>;


using t_default_course_axis = float;
using t_course_entity = t_2d_container<t_default_heading_axis>;


using t_radius_entity = float;


struct t_radar_component {
    t_radius_entity radius {};
};


using t_angle_entity = float;


using t_delta_timestamp = int;

#endif // T_COMMON_ENTITIES_H
