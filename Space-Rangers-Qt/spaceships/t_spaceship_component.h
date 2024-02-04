#ifndef T_SPACESHIP_COMPONENT_H
#define T_SPACESHIP_COMPONENT_H

#include "../t_common_entities.h"
#include "../linear_algebra/t_2d_position_entity.h"


using t_trajectory_entity = std::vector<t_2d_position_entity>;

using t_is_player_entity = bool;

class t_spaceship_component
{
public:
    t_spaceship_component(const t_spaceship_id_entity id);
    t_spaceship_component(const t_spaceship_id_entity id, const t_is_player_entity is_player);

    t_spaceship_id_entity id() const;

    t_2d_position_entity& position();
    t_2d_position_entity get_position() const;

    t_trajectory_entity& trajectory();

    t_speed_entity get_speed() const;
    void get_speed(const t_speed_entity speed);

    t_is_player_entity is_player() const;

public:
    t_spaceship_id_entity _id {};

    t_2d_position_entity _position {};

    t_heading_entity heading {};

    t_course_entity course {};

    // weapon entities

    // device entities

    t_trajectory_entity _trajectory;

    t_speed_entity _speed { 25 };

    t_is_player_entity _is_player {};
};

inline t_spaceship_component make_player() {
    return { 0, true };
}

inline t_spaceship_component make_ai() {
    return { 2, {} };
}

#endif // T_SPACESHIP_COMPONENT_H
