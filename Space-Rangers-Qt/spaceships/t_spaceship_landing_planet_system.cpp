#include "t_spaceship_landing_planet_system.h"

#include "../t_game_components.h"
#include "../t_common_entities.h"

#include "../planets/t_planet_component.h"

t_spaceship_landing_planet_system::t_spaceship_landing_planet_system(t_game_components& game_components,
                                                                     const t_spaceship_id_entity spaceship_id,
                                                                     const t_planet_id_entity planet_id)
    : i_system { __CLASS_NAME__ }
    , _spaceship { game_components.spaceship(spaceship_id) }
    , _planet { game_components.planet(planet_id) }
{
}

void t_spaceship_landing_planet_system::update(const t_delta_timestamp delta) {
}
