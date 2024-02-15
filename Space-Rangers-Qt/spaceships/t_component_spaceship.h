#ifndef T_COMPONENT_SPACESHIP_H
#define T_COMPONENT_SPACESHIP_H

#include "../t_common_entities.h"
#include "equipments/weapons/t_component_rocket_weapon.h"


using t_trajectory_entity = std::vector<t_2d_position_entity>;

using t_is_player_entity = bool;

class t_component_spaceship
{
public:
    t_component_spaceship(const t_spaceship_id_entity id);
    t_component_spaceship(const t_spaceship_id_entity id, const t_is_player_entity is_player);

    t_spaceship_id_entity id() const;

    t_2d_position_entity& position();
    t_2d_position_entity get_position() const;

    t_trajectory_entity& trajectory();

    t_linear_speed_entity get_linear_speed() const;
    void set_linear_speed(const t_linear_speed_entity speed);

    t_is_player_entity is_player() const;

public:
    t_spaceship_id_entity _id {};

    t_2d_position_entity _position {};

    t_linear_speed_entity _linear_speed { 25 };

    // t_heading_entity _heading {};

    // t_course_entity _course {};

    // weapon entities

    t_component_rocket_weapon _rocket_weapon {};

    // device entities

    t_is_player_entity _is_player {};

    t_trajectory_entity _trajectory;
};

inline t_component_spaceship make_player() {
    return { t_player_spaceship_id, true };
}

inline t_component_spaceship make_spaceship() {
    return { 2, {} };
}

#endif // T_COMPONENT_SPACESHIP_H
