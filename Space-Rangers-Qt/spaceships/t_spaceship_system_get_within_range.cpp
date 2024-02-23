#include "t_spaceship_system_get_within_range.h"

#include "../t_scene_components.h"


t_spaceship_system_get_within_range::t_spaceship_system_get_within_range(t_scene_components& scene_components, const t_spaceship_id_entity spaceship_id)
    : _scene_components { scene_components }
    , _spaceship { _scene_components.spaceship(spaceship_id) }
{
}

t_within_range_entity t_spaceship_system_get_within_range::operator()() const {
    t_within_range_entity withing_range { std::numeric_limits<t_within_range_entity>::max() };

    // for (
        const t_spaceship_rocket_weapon_component rocket_weapon = _spaceship._rocket_weapon;
    // ) {
        const t_within_range_entity weapon_withing_range = rocket_weapon.withing_range();

        withing_range = std::min(withing_range, weapon_withing_range);
    // }

    return withing_range;
}
