#ifndef T_PLANET_SYSTEM_CIRCLE_MOVING_H
#define T_PLANET_SYSTEM_CIRCLE_MOVING_H

#include "../interfaces/i_game_system.h"

class t_scene_components;
class t_component_planet;

class t_planet_system_circle_moving : public i_game_system
{
public:
    t_planet_system_circle_moving(t_scene_components& scene_components);

    void update(const t_delta delta = t_delta_frame_per_second);

private:
    void move_planet(t_component_planet& planet, const t_delta delta);

private:
    t_scene_components& _scene_components;
};

#endif // T_PLANET_SYSTEM_CIRCLE_MOVING_H
