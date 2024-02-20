#include "t_system_planet_circle_moving.h"

#include "../t_game_components.h"
#include "../t_common_entities.h"
#include "../t_common_systems.h"

t_system_planet_circle_moving::t_system_planet_circle_moving(t_game_components& game_components)
    : i_game_system { __CLASS_NAME__ }
    , _game_components { game_components }
{
}

void t_system_planet_circle_moving::update(const t_delta delta) {
    for (t_component_planet& planet : _game_components.planets()) {
        move_planet(planet, delta);
    }
}

void t_system_planet_circle_moving::move_planet(t_component_planet& planet, const t_delta delta) {
    const t_radial_speed_entity planet_radial_speed = planet.get_radial_speed();

    const t_radial_speed_entity planet_delta_radial_speed = planet_radial_speed * delta;

    t_angle_entity& planet_degrees = planet._degrees;

    planet_degrees += planet_delta_radial_speed;

    const t_radius_entity planet_radius = planet._radius;

    planet.position() = t_2d_make_position_by_x_axis_system(planet_degrees, planet_radius);
}
