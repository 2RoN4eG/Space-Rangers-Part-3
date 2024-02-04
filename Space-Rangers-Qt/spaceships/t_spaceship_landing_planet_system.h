#ifndef T_SPACESHIP_LANDING_PLANET_SYSTEM_H
#define T_SPACESHIP_LANDING_PLANET_SYSTEM_H

#include "../interfaces/i_system.h"

class t_game_components;
class t_spaceship_component;
class t_planet_component;

class t_spaceship_landing_planet_system : public i_system
{
public:
    t_spaceship_landing_planet_system(t_game_components& game_components,
                                      const t_spaceship_id_entity spaceship_id,
                                      const t_planet_id_entity planet_id);

    void update(const t_delta_timestamp delta);

private:
    t_spaceship_component& _spaceship;

    t_planet_component& _planet;
};

#endif // T_SPACESHIP_LANDING_PLANET_SYSTEM_H
