#include "t_component_spaceship.h"

t_component_spaceship::t_component_spaceship(const t_spaceship_id_entity id)
    : t_component_spaceship { id, {} }
{
}

t_component_spaceship::t_component_spaceship(const t_spaceship_id_entity id, const t_is_player_entity is_player)
    : _id { id }
    , _is_player { is_player }
{
}

t_spaceship_id_entity t_component_spaceship::id() const {
    return _id;
}

t_2d_position_entity& t_component_spaceship::position() { return _position; }

t_2d_position_entity t_component_spaceship::get_position() const { return _position; }

t_trajectory_entity& t_component_spaceship::trajectory() { return _trajectory; }

t_linear_speed_entity t_component_spaceship::get_linear_speed() const { return _linear_speed; }

void t_component_spaceship::set_linear_speed(const t_linear_speed_entity speed) { _linear_speed = speed; }

t_is_player_entity t_component_spaceship::is_player() const { return _is_player; }
