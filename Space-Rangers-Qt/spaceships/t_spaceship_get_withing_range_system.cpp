#include "t_spaceship_get_withing_range_system.h"

#include "../t_game_components.h"

t_spaceship_get_withing_range_system::t_spaceship_get_withing_range_system(t_game_components &game_components, const t_spaceship_id_entity spaceship_id)
    : _game_components { game_components }
    , _spaceship { _game_components.spaceship(spaceship_id) }
{
}

void t_spaceship_get_withing_range_system::update(const t_delta delta) {
}
