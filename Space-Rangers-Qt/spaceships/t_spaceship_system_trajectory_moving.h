#ifndef T_SPACESHIP_SYSTEM_TRAJECTORY_MOVING_H
#define T_SPACESHIP_SYSTEM_TRAJECTORY_MOVING_H

#include "../interfaces/i_game_system.h"

class t_scene_components;
class t_spaceship_component;


class t_spaceship_system_trajectory_moving : public i_game_system
{
public:
    t_spaceship_system_trajectory_moving(t_spaceship_component& spaceship);
    t_spaceship_system_trajectory_moving(t_scene_components& scene_components, const t_spaceship_id_entity spaceship_id);

    void update(const t_delta delta = t_delta_frame_per_second);

private:
    t_spaceship_component& _spaceship;

    // t_scene_components& _scene_components;
};

#endif // T_SPACESHIP_SYSTEM_TRAJECTORY_MOVING_H
