#include "t_component_rocket.h"

#include <iostream>


t_component_rocket::t_component_rocket(const t_rocket_id_entity id, const t_spaceship_id_entity aim_id, const t_2d_position_entity& position)
    : _id { id }
    , _aim_id { aim_id }
    , _position { position }
{
    std::cout << "создана ракета { " << _id << " } на позиции { x: " << _position.x() << ", y: " << _position.y() << " }, наведена на корабль { " << _aim_id << " }" << std::endl;
}

t_spaceship_id_entity t_component_rocket::id() const { return _id; }

t_spaceship_id_entity t_component_rocket::get_aim_id() const { return _aim_id; }

t_2d_position_entity& t_component_rocket::position() { return _position; }

t_2d_position_entity t_component_rocket::get_position() const { return _position; }

t_speed_entity t_component_rocket::get_speed() const { return _linear_speed; }

// void t_component_rocket::set_linear_speed(const t_linear_speed_entity linear_speed) { _linear_speed = linear_speed; }


