#ifndef T_SPACESHIP_FOLLOWING_ANOTHER_SYSTEM_H
#define T_SPACESHIP_FOLLOWING_ANOTHER_SYSTEM_H

#include "../interfaces/i_game_system.h"

class t_spaceship_following_another_system : public i_game_system
{
public:
    t_spaceship_following_another_system();

    void update(const t_delta_timestamp delta);
};

#endif // T_SPACESHIP_FOLLOWING_ANOTHER_SYSTEM_H
