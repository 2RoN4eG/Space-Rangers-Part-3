#ifndef T_PLANET_COMPONENT_H
#define T_PLANET_COMPONENT_H

#include "../t_common_entities.h"
#include "../t_stepper.h"
#include "../linear_algebra/t_2d_position_entity.h"
#include "../linear_algebra/t_2d_vector_entity.h"
#include "../linear_algebra/t_2d_common_utilities.h"

#include "t_planet_id_generator.h"

#include <iostream>

using t_linear_direction = float;

class t_planet_component
{
public:
    t_planet_component(const t_planet_id_entity id, const t_radius_entity radius, const t_angle_entity angle);

    t_planet_id_entity id() const;

    t_2d_position_entity& position();
    t_2d_position_entity get_position() const;
    void set_position(t_2d_position_entity position);

    t_speed_entity get_radial_speed() const;
    void set_radial_speed(const t_radial_speed_entity speed);

public:
    t_planet_id_entity      _id {};
    t_radius_entity         _radius { 1 };
    t_angle_entity          _degrees { };
    t_radial_speed_entity   _radial_speed { 5 };
    t_linear_direction      _direction { 1 };

    t_2d_position_entity    _position {};
};

class t_planet_position_generator {
public:
    t_2d_position_entity get_position(const t_radius_entity radius) const { return get_position({}, radius); }

    t_2d_position_entity get_position(const t_planet_id_entity planet_id, const t_radius_entity radius) const {
        const t_angle_entity angle = angle_from_degrees(_degrees.next());

        std::cout << "planet { " << planet_id << " } has radius " << radius << std::endl;

        return { radius * std::cos(angle), radius * std::sin(angle) };
    }

private:
    t_stepper<t_angle_entity> _degrees { 0., 90. / 4 };
};

std::vector<t_planet_component> make_planets(size_t count, t_planet_id_generator planet_id_generator = {}, t_planet_position_generator planet_position_generator = {});

#endif // T_PLANET_COMPONENT_H
