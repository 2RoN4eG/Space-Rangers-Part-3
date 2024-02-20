#include "t_component_spaceship.h"

#include "../t_common_systems.h"

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

t_2d_position& t_spaceship_component::position() { return _position; }

t_2d_position t_spaceship_component::get_position() const { return _position; }

t_trajectory_entity& t_spaceship_component::trajectory() { return _trajectory; }

t_linear_speed_entity t_spaceship_component::get_linear_speed() const { return _linear_speed; }

void t_spaceship_component::set_linear_speed(const t_linear_speed_entity speed) { _linear_speed = speed; }

t_is_player_entity t_spaceship_component::is_player() const { return _is_player; }


t_spaceship_component make_player() {
    t_spaceship_component player_spaceship { t_player_spaceship_id, true };

    player_spaceship.position() = t_2d_make_position_by_x_axis_system(45, 0);

    return player_spaceship;
}

t_spaceship_component make_spaceship() {
    t_spaceship_component spaceship { 2, {} };

    spaceship.position() = t_2d_make_position_by_x_axis_system(45, 150);

    return spaceship;
}
