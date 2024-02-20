#include "t_spaceship_rocket_weapon_launcher_system.h"

#include "../../../t_game_components.h"
#include "../../../linear_algebra/t_2d_linear_algebra_systems.h"
#include "../../../t_common_systems.h"

#include <iostream>


t_spaceship_rocket_weapon_launcher_system::t_spaceship_rocket_weapon_launcher_system(t_game_components& game_components,
                                                   const t_spaceship_id_entity stalker_id)
    : _game_components { game_components }
    , _stalker { game_components.spaceship(stalker_id) }
{
}

bool t_spaceship_rocket_weapon_launcher_system::requirements_completed(const t_spaceship_rocket_weapon_component& rocket_weapon, const t_spaceship_component& aim_spaceship) const {
    const t_2d_position& stalker_position = _stalker.get_position();

    const t_2d_position& aim_position = aim_spaceship.get_position();

    const t_2d_vector_length distance_length = t_2d_distance_length_system(stalker_position, aim_position);

    const t_rocket_weapon_withing_range rocket_weapon_withing_range = rocket_weapon.withing_range();

    return rocket_weapon_withing_range >= distance_length && rocket_weapon.launch_is_posible();
}

void t_spaceship_rocket_weapon_launcher_system::launch_rockets(const t_spaceship_component& stalker, const t_spaceship_id_entity aim_id) {
    std::vector<t_component_rocket>& rockets_array = _game_components.rockets();

    const t_2d_position&& stalker_position = stalker.get_position();

    const t_spaceship_component& aim_spaceship = _game_components.spaceship(aim_id);

    const t_2d_position&& aim_position = aim_spaceship.get_position();

    const t_2d_vector&& heading = t_2d_system_make_vector(stalker_position, aim_position);

    const t_angle_entity heading_angle_in_degrees = t_convert_from_vector_to_degrees_system(heading);

    const t_angle_entity step_in_degrees = 15;

    const t_spaceship_rocket_weapon_component& rocket_weapon = stalker._rocket_weapon;

    for (t_rocket_weapon_rockets_per_launch_amount index { - rocket_weapon.amount_per_launch() / 2 }; index <= stalker._rocket_weapon.amount_per_launch() / 2; index ++) {
        const t_rocket_id_entity rocket_id = _rocket_id_generator.get_value_and_generate_next();

        const t_angle_entity rocket_angle_in_degrees = heading_angle_in_degrees + index * step_in_degrees;

        const t_2d_position&& rocket_position = t_2d_make_position_by_x_axis_system(rocket_angle_in_degrees, 100, stalker_position);

        rockets_array.emplace_back(t_component_rocket { rocket_id, aim_id, rocket_position });
    }
}

void t_spaceship_rocket_weapon_launcher_system::update(const t_delta delta) {
    const t_spaceship_rocket_weapon_component& rocket_weapon = _stalker._rocket_weapon;

    const t_spaceship_id_entity aim_id = rocket_weapon.get_aim_id();

    const t_spaceship_component& aim = _game_components.spaceship(aim_id);

    if (requirements_completed(rocket_weapon, aim)) {
        launch_rockets(_stalker, aim_id);
    }
}
