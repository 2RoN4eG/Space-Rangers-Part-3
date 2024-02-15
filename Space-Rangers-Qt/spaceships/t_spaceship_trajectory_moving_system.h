#ifndef T_SPACESHIP_TRAJECTORY_MOVING_SYSTEM_H
#define T_SPACESHIP_TRAJECTORY_MOVING_SYSTEM_H

#include "../interfaces/i_game_system.h"

class t_game_components;
class t_component_spaceship;

class t_spaceship_trajectory_moving_system : public i_game_system {
public:
    t_spaceship_trajectory_moving_system(t_component_spaceship& spaceship);
    t_spaceship_trajectory_moving_system(t_game_components& game_components, const t_spaceship_id_entity spaceship_id);

    void update(const t_delta delta = t_delta_frame_per_second);

private:
    t_component_spaceship& _spaceship;

    // t_game_components& _game_components;
};

#endif // T_SPACESHIP_TRAJECTORY_MOVING_SYSTEM_H
