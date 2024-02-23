#ifndef T_COMMON_ENTITIES_H
#define T_COMMON_ENTITIES_H

#include "linear_algebra/t_2d_linear_algebra_entities.h"

#include "extra/t_value_stepper.h"

using t_integer                                             = unsigned int;

using t_id_entity                                           = t_integer;
constexpr t_id_entity t_none_id                             = std::numeric_limits<t_id_entity>::max();

using t_spaceship_id_entity                                 = t_id_entity;
using t_spaceship_id_generator                              = t_value_stepper<t_spaceship_id_entity>;
constexpr t_spaceship_id_entity t_none_spaceship_id         = t_none_id;
constexpr t_spaceship_id_entity t_player_spaceship_id       = std::numeric_limits<t_id_entity>::min();

using t_planet_id_entity                                    = t_id_entity;
using t_planet_id_generator                                 = t_value_stepper<t_planet_id_entity>;
constexpr t_planet_id_entity t_none_planet_id               = t_none_id;

using t_planetsystem_id_entity                              = t_id_entity;
using t_planetsystem_id_generator                           = t_value_stepper<t_planetsystem_id_entity>;
constexpr t_planetsystem_id_entity t_none_planetsystem_id   = t_none_id;

using t_rocket_id_entity                                    = t_id_entity;
using t_rocket_id_generator                                 = t_value_stepper<t_rocket_id_entity>;
constexpr t_rocket_id_entity t_none_rocket_id               = t_none_id;

using t_speed_entity                                        = t_scalar_entity;
using t_radial_speed_entity                                 = t_scalar_entity;
using t_radius_entity                                       = t_scalar_entity;
using t_angle_entity                                        = t_scalar_entity;
using t_within_range_entity                                 = t_scalar_entity;

using t_delta                                               = t_scalar_entity;
constexpr size_t t_frames_per_second                        = 30;
constexpr t_delta t_delta_frame_per_second                  = t_delta { 1. } / t_frames_per_second;

using t_frames_to_destination                               = t_scalar_entity;

using t_sprite_entity                                       = t_integer;
using t_2d_size_axis                                        = t_integer;
using t_2d_step_per_frame                                   = t_2d_vector_entity;

#define __CLASS_NAME__ typeid(*this).name()

#endif // T_COMMON_ENTITIES_H
