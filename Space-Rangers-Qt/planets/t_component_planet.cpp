#include "t_component_planet.h"

t_planet_component::t_planet_component(const t_planet_id_entity id, const t_radius_entity radius, const t_angle_entity angle)
    : _id { id }
    , _radius { radius }
    , _angle_degrees { angle }
{
}

t_planet_id_entity t_planet_component::id() const {
    return _id;
}


t_2d_position_entity& t_planet_component::position() {
    return _position_cache;
}

t_2d_position_entity t_planet_component::get_position() const {
    return _position_cache;
}

void t_planet_component::set_position(t_2d_position_entity position) {
    _position_cache = position;
}


t_linear_speed_entity t_planet_component::get_radial_speed() const {
    return _radial_speed;
}

void t_planet_component::set_radial_speed(const t_radial_speed_entity speed) {
    _radial_speed = speed;
}

