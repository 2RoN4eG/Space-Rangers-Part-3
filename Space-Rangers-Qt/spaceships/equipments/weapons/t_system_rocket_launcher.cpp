#include "t_system_rocket_launcher.h"

#include "../../../t_game_components.h"
#include "../../../linear_algebra/t_2d_position_systems.h"


t_system_rocket_launcher::t_system_rocket_launcher(t_game_components& game_components)
    : _game_components { game_components }
{
}

void t_system_rocket_launcher::launch_rockets(const t_component_spaceship& spaceship, const t_delta delta) {
    const t_component_rocket_weapon& rocket_weapon = spaceship._rocket_weapon;

    const t_spaceship_id_entity aim_id = rocket_weapon.get_aim_id();

    if (aim_id != t_none_spaceship_id) { return; }

    const t_component_spaceship& aim_spaceship = _game_components.spaceship(aim_id);

    const t_2d_position_entity& aim_spaceship_position = aim_spaceship.get_position();

    const t_2d_position_entity& spaceship_position = spaceship.get_position();

    const t_2d_vector_length distance_length = t_2d_distance_length_system(spaceship_position, aim_spaceship_position);

    if (distance_length <= rocket_weapon.withing_range()) {
        std::vector<t_component_rocket>& rockets = _game_components.rockets();

        const t_rocket_id_entity rocket_id = _rocket_id_generator.get_value_and_generate_next();

        rockets.emplace_back(t_component_rocket { rocket_id, aim_id });
    }
}

void t_system_rocket_launcher::update(const t_delta delta) {
    for (t_component_spaceship& spaceship : _game_components.spaceships()) {
        launch_rockets(spaceship, delta);
    }
}
