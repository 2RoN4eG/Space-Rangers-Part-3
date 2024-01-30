#ifndef T_SPACESHIP_MOVING_BY_TRAJECTORY_SYSTEM_H
#define T_SPACESHIP_MOVING_BY_TRAJECTORY_SYSTEM_H

#include "../interfaces/i_game_system.h"
#include "t_spaceship_component.h"

class t_game_components;
class t_spaceship_component;

class t_spaceship_moving_by_trajectory_system : public i_game_system {
public:
    t_spaceship_moving_by_trajectory_system(t_spaceship_component& spaceship);

    t_spaceship_moving_by_trajectory_system(t_game_components& game_components, t_spaceship_id_entity& spaceship_id);

    void update(t_delta_timestamp msec = 500);

private:
    t_spaceship_component& _spaceship;

    // t_game_components& _game_components;
};

#endif // T_SPACESHIP_MOVING_BY_TRAJECTORY_SYSTEM_H
