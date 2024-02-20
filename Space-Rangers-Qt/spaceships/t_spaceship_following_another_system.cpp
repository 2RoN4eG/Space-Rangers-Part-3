#include "t_spaceship_following_another_system.h"

#include "../t_game_components.h"

#include "../linear_algebra/t_2d_linear_algebra_systems.h"

namespace {
using t_steps = float;
}

t_spaceship_following_another_system::t_spaceship_following_another_system(t_game_components& game_components,
                                                                           const t_spaceship_id_entity stalker_id,
                                                                           const t_spaceship_id_entity victim_id,
                                                                           const t_within_range_entity within_range)
    : i_game_system { __CLASS_NAME__ }
    , _stalker { game_components.spaceship(stalker_id) }
    , _victim { game_components.spaceship(victim_id) }
    , _within_range { within_range }
{
}

void t_spaceship_following_another_system::update(const t_delta delta) {
    const t_2d_position_entity& stalker_position = _stalker.position();

    const t_2d_position_entity& victim_position = _victim.position();

    const t_2d_course_entity stalker_course = make_vector_2d_system(stalker_position, victim_position);

    const t_2d_distance_entity distance = t_2d_vector_length_system(stalker_course);

    if (distance <= _within_range) {
        return;
    }

    const t_steps steps = distance / _stalker.get_linear_speed();

    const t_2d_step_per_frame step_per_frame = t_2d_vector_division_system(stalker_course, steps);

    _stalker.position() = t_2d_vector_addition_system(stalker_position, step_per_frame);
}
