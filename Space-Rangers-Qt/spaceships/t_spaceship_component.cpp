#include "t_spaceship_component.h"

t_spaceship_component::t_spaceship_component(const t_spaceship_id_entity id)
    : t_spaceship_component { id, {} }
{
}

t_spaceship_component::t_spaceship_component(const t_spaceship_id_entity id, const t_is_player_entity is_player)
    : _id { id }
    , _is_player { is_player }
{
}

t_spaceship_id_entity t_spaceship_component::id() const {
    return _id;
}

t_2d_position_entity& t_spaceship_component::position() { return _position; }

t_2d_position_entity t_spaceship_component::get_position() const { return _position; }

t_trajectory_entity& t_spaceship_component::trajectory() { return _trajectory; }

t_speed_entity t_spaceship_component::get_speed() const { return _speed; }

void t_spaceship_component::get_speed(const t_speed_entity speed) { _speed = speed; }

t_is_player_entity t_spaceship_component::is_player() const { return _is_player; }
