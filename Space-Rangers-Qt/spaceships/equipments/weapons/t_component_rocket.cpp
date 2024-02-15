#include "t_component_rocket.h"


t_component_rocket::t_component_rocket(const t_rocket_id_entity id)
    : t_component_rocket { id, t_spaceship_id_entity { 0 } }
{
}

t_component_rocket::t_component_rocket(const t_rocket_id_entity id, const t_spaceship_id_entity aim_id)
    : _id { id }
    , _aim_id { aim_id }
{
}

t_spaceship_id_entity t_component_rocket::id() const { return _id; }

t_spaceship_id_entity t_component_rocket::aim_id() const { return _aim_id; }

// t_2d_position_entity& t_component_rocket::position() { return _position; }

// t_2d_position_entity t_component_rocket::get_position() const { return _position; }

// t_linear_speed_entity t_component_rocket::get_linear_speed() const { return _linear_speed; }

// void t_component_rocket::set_linear_speed(const t_linear_speed_entity linear_speed) { _linear_speed = linear_speed; }


