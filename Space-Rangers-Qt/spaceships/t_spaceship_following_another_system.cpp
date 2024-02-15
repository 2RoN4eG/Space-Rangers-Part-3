#include "t_spaceship_following_another_system.h"

#include "../t_game_components.h"

#include "../linear_algebra/t_2d_position_systems.h"
#include "../linear_algebra/t_2d_vector_systems.h"

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
    const t_2d_position_entity& follower_position = _stalker.position();

    const t_2d_position_entity& target_position = _victim.position();

    const t_2d_vector_entity directed_distance = t_make_2d_vector(follower_position, target_position);

    const t_2d_distance_length distance_length = t_2d_vector_length_system(directed_distance);

    if (distance_length <= _within_range) {
        return;
    }
    
    const t_steps steps = distance_length / _stalker.get_linear_speed();

    const t_2d_vector_entity step = t_2d_vector_division_system(directed_distance, steps);

    _stalker.position() = t_2d_vector_addition_system(follower_position, step);
}
