#include "t_spaceship_system_landing_planet.h"

#include "../t_scene_components.h"
#include "../t_common_entities.h"

#include "../planets/t_planet_component.h"

t_spaceship_system_landing_planet::t_spaceship_system_landing_planet(t_scene_components& scene_components,
                                                                     const t_spaceship_id_entity spaceship_id,
                                                                     const t_planet_id_entity planet_id)
    : i_game_system { __CLASS_NAME__ }
    , _spaceship { scene_components.spaceship(spaceship_id) }
    , _planet { scene_components.planet(planet_id) }
{
}

void t_spaceship_system_landing_planet::update(const t_delta delta) {
}
