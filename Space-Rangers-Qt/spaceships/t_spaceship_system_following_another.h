#ifndef T_SPACESHIP_SYSTEM_FOLLOWING_ANOTHER_H
#define T_SPACESHIP_SYSTEM_FOLLOWING_ANOTHER_H

#include "../t_common_entities.h"
#include "../interfaces/i_game_system.h"

#include "t_spaceship_system_get_within_range.h"

// TODO: Корабль stalker должен следовать за кораблем victim сохраняя на дистанции выстрела

class t_scene_components;
class t_spaceship_component;

class t_spaceship_following_another_system : public i_game_system
{
public:
    t_spaceship_following_another_system(t_scene_components& scene_components,
                                         const t_spaceship_id_entity stalker_id,
                                         const t_spaceship_id_entity victim_id);

    void update(const t_delta delta = t_delta_frame_per_second);

private:
    t_spaceship_component& _stalker;

    t_spaceship_component& _victim;

    t_spaceship_system_get_within_range _get_within_range;
};

#endif // T_SPACESHIP_SYSTEM_FOLLOWING_ANOTHER_H
