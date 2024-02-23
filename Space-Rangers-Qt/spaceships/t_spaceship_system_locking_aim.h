#ifndef T_SPACESHIP_SYSTEM_LOCKING_AIM_H
#define T_SPACESHIP_SYSTEM_LOCKING_AIM_H

#include "../t_common_entities.h"


class t_scene_components;


class t_spaceship_system_locking_aim
{
public:
    t_spaceship_system_locking_aim(t_scene_components& scene_components);

    bool lock_on(const t_spaceship_id_entity spaceship_id);
    bool lock_on(const t_weapon_id_entity weapon_id, const t_spaceship_id_entity aim_id);

    bool lock_off(const t_spaceship_id_entity aim_id);
    bool lock_off(const t_weapon_id_entity weapon_id, const t_spaceship_id_entity aim_id);

private:
    t_scene_components& _scene_components;
};

#endif // T_SPACESHIP_SYSTEM_LOCKING_AIM_H
