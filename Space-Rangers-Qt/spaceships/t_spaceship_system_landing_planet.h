#ifndef T_SPACESHIP_SYSTEM_LANDING_PLANET_H
#define T_SPACESHIP_SYSTEM_LANDING_PLANET_H

#include "../interfaces/i_game_system.h"

class t_scene_components;
class t_spaceship_component;
class t_component_planet;


class t_spaceship_system_landing_planet : public i_game_system
{
public:
    t_spaceship_system_landing_planet(t_scene_components& scene_components,
                                      const t_spaceship_id_entity spaceship_id,
                                      const t_planet_id_entity planet_id);

    void update(const t_delta delta = t_delta_frame_per_second);

private:
    t_spaceship_component& _spaceship;

    t_component_planet& _planet;
};

#endif // T_SPACESHIP_SYSTEM_LANDING_PLANET_H
