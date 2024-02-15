#ifndef T_COMPONENT_ROCKET_H
#define T_COMPONENT_ROCKET_H

#include "../../../t_common_entities.h"
#include "../../../linear_algebra/t_2d_position_entity.h"


class t_component_rocket
{
public:
    t_component_rocket(const t_rocket_id_entity id);
    t_component_rocket(const t_rocket_id_entity id, const t_spaceship_id_entity aim_id);

    t_rocket_id_entity id() const;

    t_spaceship_id_entity aim_id() const;

    // t_2d_position_entity& position();
    // t_2d_position_entity get_position() const;

    // t_linear_speed_entity get_linear_speed() const;
    // void set_linear_speed(const t_linear_speed_entity speed);

protected:
    t_rocket_id_entity _id {};

    t_spaceship_id_entity _aim_id {};

    // t_2d_position_entity _position {};

    // t_linear_speed_entity _linear_speed { 25 };
    // t_heading_entity heading {};
    // t_course_entity course {};
};

#endif // T_COMPONENT_ROCKET_H