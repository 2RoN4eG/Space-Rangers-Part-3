#ifndef T_SPACESHIP_GET_WITHING_RANGE_H
#define T_SPACESHIP_GET_WITHING_RANGE_H

#include "../t_common_entities.h"

class t_game_components;
class t_spaceship_component;

class t_spaceship_get_withing_range
{
public:
    t_spaceship_get_withing_range(t_game_components& game_components, const t_spaceship_id_entity spaceship_id);

    void update(const t_delta delta = t_delta_frame_per_second);

private:
    t_game_components& _game_components;

    t_spaceship_component& _spaceship;
};

#endif // T_SPACESHIP_GET_WITHING_RANGE_H
