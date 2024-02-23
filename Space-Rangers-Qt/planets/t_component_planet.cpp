#include "t_component_planet.h"

t_component_planet::t_component_planet(const t_planet_id_entity id, const t_radius_entity radius, const t_angle_entity angle)
    : _id { id }
    , _radius { radius }
    , _degrees { angle }
{
}

t_planet_id_entity t_component_planet::id() const {
    return _id;
}


t_2d_position_entity& t_component_planet::position() {
    return _cached_position;
}

t_2d_position_entity t_component_planet::get_position() const {
    return _cached_position;
}

void t_component_planet::set_position(t_2d_position_entity position) {
    _cached_position = position;
}


t_speed_entity t_component_planet::get_radial_speed() const {
    return _radial_speed;
}

void t_component_planet::set_radial_speed(const t_radial_speed_entity speed) {
    _radial_speed = speed;
}

