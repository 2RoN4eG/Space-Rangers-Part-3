#include "t_planet_circle_moving_system.h"

#include "../t_game_components.h"

t_planet_circle_moving_system::t_planet_circle_moving_system(t_game_components& game_components)
    : i_game_system { "planet_circle_moving" }
    , _game_components { game_components }
{
}

void t_planet_circle_moving_system::update([[maybe_unused]] const t_delta_timestamp delta) {
    for (t_planet_game_component& planet : _game_components.planets()) {
        step(delta, planet);
    }
}

void t_planet_circle_moving_system::step(const t_delta_timestamp delta, t_planet_game_component& planet) {
    const t_radial_speed_entity radial_speed = planet.get_radial_speed() / (1000 / delta);

    planet._degrees = (planet._degrees + radial_speed);

    const t_angle_entity angle = angle_from_degrees(planet._degrees);

    planet.position() = t_2d_position_entity { planet._radius * std::cos(angle), planet._radius * std::sin(angle) };
}
