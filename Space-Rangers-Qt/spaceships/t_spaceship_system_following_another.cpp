#include "t_spaceship_system_following_another.h"

#include "../t_scene_components.h"

#include "../linear_algebra/t_2d_linear_algebra_systems.h"

namespace {
using t_distance_in_frames = float;
}

t_spaceship_following_another_system::t_spaceship_following_another_system(t_scene_components& scene_components,
                                                                           const t_spaceship_id_entity stalker_id,
                                                                           const t_spaceship_id_entity victim_id)
    : i_game_system { __CLASS_NAME__ }
    , _stalker { scene_components.spaceship(stalker_id) }
    , _victim { scene_components.spaceship(victim_id) }
    , _get_within_range { scene_components, stalker_id }
{
}

void t_spaceship_following_another_system::update(const t_delta delta) {
    const t_2d_position_entity& stalker_position = _stalker.position();

    const t_2d_position_entity& victim_position = _victim.position();

    const t_2d_course_entity stalker_course = make_vector_2d_system(stalker_position, victim_position);

    const t_scalar_distance_entity distance = t_2d_vector_length_system(stalker_course);

    if (distance <= _get_within_range()) {
        return;
    }

    const t_scalar_speed_entity stalker_delta_speed = _stalker.get_speed() * delta;

    std::cout << "stalker speed: " << _stalker.get_speed() << ", delta speed: " << stalker_delta_speed << std::endl;

    const t_distance_in_frames frames = distance / stalker_delta_speed;

    const t_2d_step_per_frame step_per_frame = t_2d_vector_division_system(stalker_course, frames);

    _stalker.position() = t_2d_vector_addition_system(stalker_position, step_per_frame);
}
