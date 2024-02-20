#include "t_spaceship_get_withing_range_system.h"

#include "../t_scene_components.h"


t_spaceship_withing_range_system::t_spaceship_withing_range_system(t_scene_components& scene_components, const t_spaceship_id_entity spaceship_id)
    : _scene_components { scene_components }
    , _spaceship { _scene_components.spaceship(spaceship_id) }
{
}

void t_spaceship_withing_range_system::update(const t_delta delta) {
}
