#include "t_spaceship_system_trajectory_moving.h"

#include "../t_common_entities.h"
#include "../t_scene_components.h"

#include "../linear_algebra/t_2d_linear_algebra_systems.h"


t_spaceship_system_trajectory_moving::t_spaceship_system_trajectory_moving(t_spaceship_component& spaceship)
    : i_game_system { __CLASS_NAME__ }
    , _spaceship { spaceship }
{
}

t_spaceship_system_trajectory_moving::t_spaceship_system_trajectory_moving(t_scene_components& scene_components, const t_spaceship_id_entity spaceship_id)
    : t_spaceship_system_trajectory_moving { scene_components.spaceship(spaceship_id) }
{
}

void t_spaceship_system_trajectory_moving::update(t_delta delta) {
    t_trajectory_entity& trajectory = _spaceship.trajectory();

    if (trajectory.empty()) {
        return;
    }

    t_2d_position_entity& spaceship_position = _spaceship.position();

    const t_2d_position_entity& target_position = trajectory.front();
    
    const t_2d_vector_entity heading = make_vector_2d_system(spaceship_position, target_position);
    
    const t_scalar_length_entity scalar_distance = t_2d_vector_length_system(heading);

    const t_scalar_speed_entity spaceship_delta_speed = _spaceship.get_speed() * delta;

    const t_scalar_distance_entity frames_to_destination = scalar_distance / spaceship_delta_speed;

    const t_2d_step_per_frame step_per_frame = t_2d_vector_division_system(heading, frames_to_destination);

    spaceship_position = t_2d_vector_addition_system(spaceship_position, step_per_frame);

    const t_scalar_length_entity heading_length = t_2d_vector_length_system(heading);

    if (spaceship_delta_speed >= heading_length && !trajectory.empty()) {
        spaceship_position = trajectory.front();

        trajectory.erase(trajectory.begin());
    }
}
