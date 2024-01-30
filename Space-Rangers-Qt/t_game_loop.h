#ifndef T_GAME_LOOP_H
#define T_GAME_LOOP_H

#include "t_common_entities.h"

class t_game_components;

class [[maybe_unused]] t_game_loop
{
public:
    t_game_loop(t_game_components& game_components);

    void update(const t_delta_timestamp delta = 500);

private:
    t_game_components& _game_components;
};

#endif // T_GAME_LOOP_H
