#include "t_rocket_weapon_component.h"

t_spaceship_rocket_weapon_component::t_spaceship_rocket_weapon_component() {}

t_rocket_weapon_withing_range t_spaceship_rocket_weapon_component::withing_range() const {
    return _withing_range;
}

t_rocket_weapon_amount_per_launch t_spaceship_rocket_weapon_component::amount_per_launch() const {
    return _amount_per_launch;
}

void t_spaceship_rocket_weapon_component::set_aim(const t_spaceship_id_entity aim_id) {
    _aim_id = aim_id;
}

t_spaceship_id_entity t_spaceship_rocket_weapon_component::get_aim_id() const {
    return _aim_id;
}

bool t_spaceship_rocket_weapon_component::launch_is_posible() const {
    // std::cout << "called launch_is_posible()" << std::endl;

    return (_frames_cache ++) % _launch_possible_per_frames == 0;
}
