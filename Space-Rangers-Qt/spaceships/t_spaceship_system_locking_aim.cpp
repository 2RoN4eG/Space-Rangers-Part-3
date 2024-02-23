#include "t_spaceship_system_locking_aim.h"


t_spaceship_system_locking_aim::t_spaceship_system_locking_aim(t_scene_components &scene_components)
    : _scene_components { scene_components }
{
}

bool t_spaceship_system_locking_aim::lock_on(const t_spaceship_id_entity aim_id) {
    return {};
}

bool t_spaceship_system_locking_aim::lock_on(const t_weapon_id_entity weapon_id, const t_spaceship_id_entity aim_id) {
    return {};
}

bool t_spaceship_system_locking_aim::lock_off(const t_spaceship_id_entity aim_id) {
    return {};
}

bool t_spaceship_system_locking_aim::lock_off(const t_weapon_id_entity weapon_id, const t_spaceship_id_entity aim_id) {
    return {};
}
