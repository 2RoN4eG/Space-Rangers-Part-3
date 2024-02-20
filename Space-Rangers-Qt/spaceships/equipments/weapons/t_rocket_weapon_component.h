#ifndef T_ROCKET_WEAPON_COMPONENT_H
#define T_ROCKET_WEAPON_COMPONENT_H

#include "../../../t_common_entities.h"
#include <iostream>


using t_rocket_weapon_withing_range     = float;
using t_rocket_weapon_amount_per_launch = int;
using t_rocket_weapon_scattering_angle  = int;
using t_reloading_time_millis           = int;
using t_reloading_time_frames           = int;
using t_reloading_time_playing_days     = int;


class t_spaceship_rocket_weapon_component
{
public:
    t_spaceship_rocket_weapon_component();

    t_rocket_weapon_withing_range withing_range() const;

    t_rocket_weapon_amount_per_launch amount_per_launch() const;

    void set_aim(const t_spaceship_id_entity aim_id);

    t_spaceship_id_entity get_aim_id() const;

    bool launch_is_posible() const;

private:
    // Кол-во ракет при запуске
    const t_rocket_weapon_amount_per_launch _amount_per_launch { 5 };

    // Угол разлета ракет
    const t_rocket_weapon_scattering_angle _scattering_angle { 10 };

    // Растояния (дистанция) выстрела (запуска рокет)
    t_rocket_weapon_withing_range _withing_range { 100 };

    // Время перезарядки оружия (в данном случае в кол-ве кардров)
    t_reloading_time_frames _reloading_time { 2 * 30 };

    t_spaceship_id_entity _aim_id { 2 };

    mutable size_t _frames_cache {};
    const size_t _launch_possible_per_frames { 30 };
};

#endif // T_ROCKET_WEAPON_COMPONENT_H
