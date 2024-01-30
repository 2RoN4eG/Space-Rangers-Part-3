#include "t_game_systems.h"

#include "interfaces/i_game_system.h"

t_game_systems::t_game_systems(t_game_components& game_components)
    : _game_components { game_components }
{
}

void t_game_systems::update(const t_delta_timestamp delta) {
}
