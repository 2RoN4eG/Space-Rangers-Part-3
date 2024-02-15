#ifndef T_COMPONENT_PLANET_H
#define T_COMPONENT_PLANET_H

#include "../t_common_entities.h"
#include "../t_value_stepper.h"
#include "../linear_algebra/t_2d_position_entity.h"
#include "../linear_algebra/t_2d_common.h"



using t_linear_direction = float;

class t_planet_component
{
public:
    t_planet_component(const t_planet_id_entity id, const t_radius_entity radius, const t_angle_entity angle);

    t_planet_id_entity id() const;

    t_2d_position_entity& position();
    t_2d_position_entity get_position() const;
    void set_position(t_2d_position_entity position);
    
    t_linear_speed_entity get_radial_speed() const;
    void set_radial_speed(const t_radial_speed_entity speed);

public:
    t_planet_id_entity      _id {};
    t_radius_entity         _radius { 1 };
    t_angle_entity          _angle_degrees { };
    t_linear_direction      _direction { 1 };

    t_2d_position_entity    _position {};
    t_radial_speed_entity   _radial_speed { 5 };
};

#endif // T_COMPONENT_PLANET_H
