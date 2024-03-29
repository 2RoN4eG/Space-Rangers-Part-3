#ifndef T_PLANET_COMPONENT_H
#define T_PLANET_COMPONENT_H

#include "../t_common_entities.h"
#include "../linear_algebra/t_2d_linear_algebra_entities.h"



using t_linear_direction = float;

class t_component_planet
{
public:
    t_component_planet(const t_planet_id_entity id, const t_radius_entity radius, const t_scalar_angle_entity angle);

    t_planet_id_entity id() const;
    
    t_2d_position_entity& position();
    t_2d_position_entity get_position() const;
    void set_position(t_2d_position_entity position);
    
    t_scalar_speed_entity get_radial_speed() const;
    void set_radial_speed(const t_radial_speed_entity speed);

public:
    t_planet_id_entity      _id {};
    t_radius_entity         _radius { 1 };  // distance from center
    t_scalar_angle_entity          _degrees { };
    t_linear_direction      _direction { 1 };
    
    t_2d_position_entity           _cached_position {};
    t_radial_speed_entity   _radial_speed { 5 };
};

#endif // T_PLANET_COMPONENT_H
