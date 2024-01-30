#ifndef T_PLANET_CIRCLE_MOVING_SYSTEM_H
#define T_PLANET_CIRCLE_MOVING_SYSTEM_H

#include "../interfaces/i_game_system.h"

class t_game_components;
class t_planet_game_component;

class t_planet_circle_moving_system : public i_game_system
{
public:
    t_planet_circle_moving_system(t_game_components& game_components);

    void update(const t_delta_timestamp delta = 500);

private:
    void step(const t_delta_timestamp delta, t_planet_game_component& planet);

private:
    t_game_components& _game_components;
};

#endif // T_PLANET_CIRCLE_MOVING_SYSTEM_H
