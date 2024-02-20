#ifndef T_ROCKET_MOVING_SYSTEM_H
#define T_ROCKET_MOVING_SYSTEM_H

#include "../../../t_common_entities.h"

class t_game_components;
class t_component_rocket;


class t_rocket_moving_system
{
public:
    t_rocket_moving_system(t_game_components& game_components);

    void update(const t_delta delta = t_delta_frame_per_second);

    void move_rocket(t_component_rocket& rocket, const t_delta delta);

private:
    t_game_components& _game_components;
};

#endif // T_ROCKET_MOVING_SYSTEM_H
