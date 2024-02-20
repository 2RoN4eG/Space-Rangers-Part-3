#ifndef T_COMMON_ENTITIES_H
#define T_COMMON_ENTITIES_H

#include "linear_algebra/t_2d_linear_algebra_entities.h"

#include "extra/t_value_stepper.h"

using t_integer                                     = int;

using t_id_entity                                   = t_integer;
constexpr t_id_entity t_none_id                     = std::numeric_limits<t_id_entity>::max();

using t_spaceship_id_entity                         = t_id_entity;
using t_spaceship_id                                = t_spaceship_id_entity;
using t_spaceship_id_generator                      = t_value_stepper<t_spaceship_id>;
constexpr t_spaceship_id t_none_spaceship_id        = t_none_id;
constexpr t_spaceship_id t_player_spaceship_id      = 0;

using t_planet_id_entity                            = t_id_entity;
using t_planet_id                                   = t_planet_id_entity;
using t_planet_id_generator                         = t_value_stepper<t_planet_id>;
constexpr t_spaceship_id t_none_planet_id           = t_none_id;

using t_planetsystem_id_entity                      = t_id_entity;
using t_planetsystem_id                             = t_planetsystem_id_entity;
using t_planetsystem_id_generator                   = t_value_stepper<t_planetsystem_id>;
constexpr t_planetsystem_id t_none_planetsystem_id  = t_none_id;

using t_rocket_id_entity                            = t_id_entity;
using t_rocket_id                                   = t_rocket_id_entity;
using t_rocket_id_generator                         = t_value_stepper<t_rocket_id>;
constexpr t_rocket_id t_none_rocket_id              = t_none_id;

using t_linear_speed_entity                         = t_integer;
using t_radial_speed_entity                         = t_floating_point;

using t_default_heading_axis                        = t_floating_point;
using t_2d_heading_entity                              = t_2d_container<t_default_heading_axis>;

using t_default_course_axis                         = t_floating_point;
using t_course_entity                               = t_2d_container<t_default_course_axis>;

using t_radius_entity                               = t_floating_point;
using t_radius                                      = t_radius_entity;

using t_angle_entity                                = t_floating_point;

using t_within_range_entity                         = t_integer;
using t_within_range                                = t_within_range_entity;

using t_delta                                       = t_floating_point;
constexpr size_t t_frames_per_second                = 30;
constexpr t_delta t_delta_frame_per_second          = t_delta { 1. } / t_frames_per_second;

using t_sprite_entity                               = t_integer;

using t_size_default_axis                           = t_integer;

using t_step_per_frame                              = t_2d_vector;

#define __CLASS_NAME__ typeid(*this).name()

#endif // T_COMMON_ENTITIES_H
