#include "t_planet_system_circle_moving.h"

#include "../t_scene_components.h"
#include "../t_common_entities.h"
#include "../t_common_systems.h"

t_planet_system_circle_moving::t_planet_system_circle_moving(t_scene_components& scene_components)
    : i_game_system { __CLASS_NAME__ }
    , _scene_components { scene_components }
{
}

void t_planet_system_circle_moving::update(const t_delta delta) {
    for (t_component_planet& planet : _scene_components.planets()) {
        move_planet(planet, delta);
    }
}

void t_planet_system_circle_moving::move_planet(t_component_planet& planet, const t_delta delta) {
    const t_radial_speed_entity planet_radial_speed = planet.get_radial_speed();

    const t_radial_speed_entity planet_delta_radial_speed = planet_radial_speed * delta;

    t_scalar_angle_entity& planet_degrees = planet._degrees;

    planet_degrees += planet_delta_radial_speed;

    const t_radius_entity planet_radius = planet._radius;

    planet.position() = make_2d_position_by_x_axis(planet_degrees, planet_radius);
}
