#include "t_planet_game_component.h"

t_planet_game_component::t_planet_game_component(const t_planet_id_entity id, const t_radius_entity radius, const t_angle_entity angle)
    : _id { id }
    , _radius { radius }
    , _degrees { angle }
{
}

t_planet_id_entity t_planet_game_component::id() const {
    return _id;
}


t_2d_position_entity& t_planet_game_component::position() {
    return _position;
}

t_2d_position_entity t_planet_game_component::get_position() const {
    return _position;
}

void t_planet_game_component::set_position(t_2d_position_entity position) {
    _position = position;
}


t_speed_entity t_planet_game_component::get_radial_speed() const {
    return _radial_speed;
}

void t_planet_game_component::set_radial_speed(const t_radial_speed_entity speed) {
    _radial_speed = speed;
}


std::vector<t_planet_game_component> make_planets(size_t count, t_planet_id_generator planet_id_generator, t_planet_position_generator planet_position_generator) {
    t_stepper<t_radius_entity> radius_generator { 300., 60. };
    t_stepper<t_angle_entity> angle_generator  { 0., 90. / 4 };

    std::vector<t_planet_game_component> planets;
    for (size_t index {}; index < count; ++index) {
        const t_planet_id_entity planet_id = planet_id_generator.get_planet_id();
        const t_radius_entity radius = radius_generator.next();
        const t_angle_entity angle = angle_generator.next();

        planets.emplace_back(t_planet_game_component { planet_id, radius, angle });
    }
    return planets;
}
