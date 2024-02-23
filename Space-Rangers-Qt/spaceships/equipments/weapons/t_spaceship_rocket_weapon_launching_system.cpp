#include "t_spaceship_rocket_weapon_launching_system.h"

#include "../../../t_scene_components.h"
#include "../../../linear_algebra/t_2d_linear_algebra_systems.h"
#include "../../../t_common_systems.h"

#include <iostream>


t_spaceship_rocket_weapon_launcher_system::t_spaceship_rocket_weapon_launcher_system(t_scene_components& scene_components,
                                                   const t_spaceship_id_entity stalker_id)
    : _scene_components { scene_components }
    , _stalker { scene_components.spaceship(stalker_id) }
{
}

bool t_spaceship_rocket_weapon_launcher_system::requirements_completed(const t_spaceship_rocket_weapon_component& rocket_weapon, const t_spaceship_component& aim_spaceship) const {
    const t_2d_position_entity& stalker_position = _stalker.get_position();

    const t_2d_position_entity& aim_position = aim_spaceship.get_position();

    const t_scalar_length_entity distance_length = make_distance_system(stalker_position, aim_position);

    const t_within_range_entity rocket_weapon_withing_range = rocket_weapon.withing_range();

    return rocket_weapon_withing_range >= distance_length && rocket_weapon.launch_is_posible();
}

void t_spaceship_rocket_weapon_launcher_system::launch_rockets(const t_spaceship_component& stalker, const t_spaceship_id_entity aim_id) {
    std::vector<t_component_rocket>& rockets_array = _scene_components.rockets();

    const t_2d_position_entity&& stalker_position = stalker.get_position();

    const t_spaceship_component& aim_spaceship = _scene_components.spaceship(aim_id);

    const t_2d_position_entity&& aim_position = aim_spaceship.get_position();

    const t_2d_vector_entity&& heading = make_vector_2d_system(stalker_position, aim_position);

    const t_scalar_angle_entity heading_angle_in_degrees = convert_from_vector_to_degrees(heading);

    const t_spaceship_rocket_weapon_component& rocket_weapon = stalker._rocket_weapon;

    // Начальная дистанция
    const t_scalar_distance_entity launch_distance { 15 };

    for (t_rocket_weapon_rockets_per_launch_amount index { - rocket_weapon.amount_per_launch() / 2 }; index <= rocket_weapon.amount_per_launch() / 2; index ++) {
        const t_rocket_id_entity rocket_id = _rocket_id_generator.get_value_and_generate_next();

        const t_scalar_angle_entity rocket_angle_in_degrees = heading_angle_in_degrees + index * rocket_weapon.scattering_angle();

        const t_2d_position_entity&& rocket_position = make_2d_position_by_x_axis(rocket_angle_in_degrees, launch_distance, stalker_position);

        rockets_array.emplace_back(t_component_rocket { rocket_id, aim_id, rocket_position });
    }
}

void t_spaceship_rocket_weapon_launcher_system::update(const t_delta delta) {
    const t_spaceship_rocket_weapon_component& rocket_weapon = _stalker._rocket_weapon;

    const t_spaceship_id_entity aim_id = rocket_weapon.get_aim_id();

    const t_spaceship_component& aim = _scene_components.spaceship(aim_id);

    if (requirements_completed(rocket_weapon, aim)) {
        launch_rockets(_stalker, aim_id);
    }
}
