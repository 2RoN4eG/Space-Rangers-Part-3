#ifndef T_SPACESHIP_FOLLOWING_ANOTHER_SYSTEM_H
#define T_SPACESHIP_FOLLOWING_ANOTHER_SYSTEM_H

#include "../interfaces/i_game_system.h"
#include "../t_common_entities.h"

// TODO: Корабль stalker должен следовать за кораблем victim сохраняя на дистанции выстрела

class t_game_components;
class t_component_spaceship;

class t_spaceship_following_another_system : public i_game_system
{
public:
    t_spaceship_following_another_system(t_game_components& game_components,
                                         const t_spaceship_id_entity stalker_id,
                                         const t_spaceship_id_entity victim_id,
                                         const t_within_range_entity within_range = 60);

    void update(const t_delta delta = t_delta_frame_per_second);

private:
    t_component_spaceship& _stalker;

    t_component_spaceship& _victim;

    t_within_range_entity _within_range;
};

#endif // T_SPACESHIP_FOLLOWING_ANOTHER_SYSTEM_H
