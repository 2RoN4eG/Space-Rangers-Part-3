#ifndef T_ROCKET_WEAPON_COMPONENT_H
#define T_ROCKET_WEAPON_COMPONENT_H

#include "../../../t_common_entities.h"
#include <iostream>


using t_amount_per_launch_entity            = int;
using t_scattering_angle_entity             = int;
using t_reloading_time_millis_entity        = int;
using t_reloading_time_frames_entity        = int;
using t_reloading_time_playing_days_entity  = int;


class t_spaceship_rocket_weapon_component
{
public:
    t_spaceship_rocket_weapon_component();

    t_amount_per_launch_entity amount_per_launch() const;

    t_within_range_entity withing_range() const;

    t_scattering_angle_entity scattering_angle() const;

    void set_aim(const t_spaceship_id_entity aim_id);
    t_spaceship_id_entity get_aim_id() const;

    bool launch_is_posible() const;

private:
    t_spaceship_id_entity _aim_id { 2 };

    mutable size_t _frames_cache {};

    //
    const size_t _launch_possible_per_frames { 30 };

    // Кол-во ракет при запуске
    const t_amount_per_launch_entity _amount_per_launch { 5 };

    // Растояния (дистанция) выстрела (запуска рокет)
    const t_within_range_entity _withing_range { 150 };

    // Угол разлета ракет
    const t_scattering_angle_entity _scattering_angle { 30 };

    // Время перезарядки оружия (в данном случае в кол-ве кардров)
    const t_reloading_time_frames_entity _reloading_time { 2 * 30 };

public:
};

#endif // T_ROCKET_WEAPON_COMPONENT_H
