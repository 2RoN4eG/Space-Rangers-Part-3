#ifndef T_ROCKET_MOVING_SYSTEM_H
#define T_ROCKET_MOVING_SYSTEM_H

#include "../../../t_common_entities.h"

class t_scene_components;
class t_component_rocket;
class t_spaceship_component;


class t_rocket_moving_system
{
public:
    t_rocket_moving_system(t_scene_components& scene_components);

    void update(const t_delta delta = t_delta_frame_per_second);

    void move_rocket_for(t_component_rocket& rocket, const t_spaceship_component& aim_spaceship, const t_delta delta);

private:
    t_scene_components& _scene_components;
};

#endif // T_ROCKET_MOVING_SYSTEM_H
