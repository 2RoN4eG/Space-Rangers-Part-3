#ifndef T_GAME_SYSTEMS_H
#define T_GAME_SYSTEMS_H

#include "t_common_entities.h"

class t_game_components;
class i_game_system;

class [[maybe_unused]] t_game_systems
{
public:
    t_game_systems(t_game_components& game_components);
    
    void update(const t_delta delta = t_delta_frame_per_second);

private:
    t_game_components& _game_components;
};

#endif // T_GAME_SYSTEMS_H
