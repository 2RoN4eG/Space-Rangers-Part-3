#ifndef T_COMPONENT_ROCKET_WEAPON_H
#define T_COMPONENT_ROCKET_WEAPON_H

#include "../../../t_common_entities.h"


using t_rocket_launcher_withing_range = float;
using t_rocket_launcher_rocket_amount = int;
using t_reloading_time_millis         = int;
using t_reloading_time_frames         = int;
using t_reloading_time_playing_days   = int;


class t_component_rocket_weapon
{
public:
    t_component_rocket_weapon();

    inline t_rocket_launcher_withing_range withing_range() const {
        return _withing_range;
    }

    inline t_rocket_launcher_rocket_amount rocket_amount() const {
        return _rocket_amount;
    }

    inline void set_aim(const t_spaceship_id_entity aim_id) {
        _aim_id = aim_id;
    }

    inline t_spaceship_id_entity get_aim_id() const {
        return _aim_id;
    }

private:
    // Кол-во ракет при запуске
    const t_rocket_launcher_rocket_amount _rocket_amount { 5 };

    // Растояния выстрела (запуска рокет)
    t_rocket_launcher_withing_range _withing_range { 1000 };

    // Время перезарядки оружия (в данном случае в кол-ве кардров)
    t_reloading_time_frames _reloading_time { 2 * 30 };

    t_spaceship_id_entity _aim_id { t_none_spaceship_id };
};

#endif // T_COMPONENT_ROCKET_WEAPON_H
