#include "t_system_planet_circle_moving.h"

#include "../t_game_components.h"

t_system_planet_circle_moving::t_system_planet_circle_moving(t_game_components& game_components)
    : i_game_system { __CLASS_NAME__ }
    , _game_components { game_components }
{
}

void t_system_planet_circle_moving::update(const t_delta delta) {
    for (t_planet_component& planet : _game_components.planets()) {
        move_planet(planet, delta);
    }
}

void t_system_planet_circle_moving::move_planet(t_planet_component& planet, const t_delta delta) {
    const t_radial_speed_entity planet_radial_speed = planet.get_radial_speed();

    const t_radial_speed_entity planet_delta_radial_speed = planet_radial_speed * delta;

    planet._angle_degrees = (planet._angle_degrees + planet_delta_radial_speed);

    const t_angle_entity angle_radians = t_convert_from_degrees_to_radians(planet._angle_degrees);

    planet.position() = t_2d_position_entity { planet._radius * std::cos(angle_radians), planet._radius * std::sin(angle_radians) };
}
