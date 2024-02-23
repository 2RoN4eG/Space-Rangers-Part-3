#ifndef T_SPACESHIP_ROCKET_WEAPON_LAUNCHING_SYSTEM_H
#define T_SPACESHIP_ROCKET_WEAPON_LAUNCHING_SYSTEM_H

#include "../../../t_common_entities.h"
#include "../../../extra/t_value_stepper.h"


class t_scene_components;
class t_spaceship_component;
using t_rocket_weapon_rockets_per_launch_amount = int;
class t_spaceship_rocket_weapon_component;


class t_spaceship_rocket_weapon_launcher_system
{
public:
    t_spaceship_rocket_weapon_launcher_system(t_scene_components& scene_components,
                                            const t_spaceship_id_entity stalker_id);

    void update(const t_delta delta = t_delta_frame_per_second);

private:
    bool requirements_completed(const t_spaceship_rocket_weapon_component& rocket_weapon, const t_spaceship_component& aim) const;

    void launch_rockets(const t_spaceship_component& _stalker, const t_spaceship_id_entity aim_id);

private:
    t_scene_components& _scene_components;

    t_spaceship_component& _stalker;

    t_rocket_id_generator _rocket_id_generator { 0, 1 };
};

#endif // T_SPACESHIP_ROCKET_WEAPON_LAUNCHING_SYSTEM_H
