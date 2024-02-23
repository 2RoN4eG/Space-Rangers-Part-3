#ifndef T_SPACESHIP_SYSTEM_GET_WITHIN_RANGE_H
#define T_SPACESHIP_SYSTEM_GET_WITHIN_RANGE_H

#include "../t_common_entities.h"

class t_scene_components;
class t_spaceship_component;

class t_spaceship_system_get_within_range
{
public:
    t_spaceship_system_get_within_range(t_scene_components& scene_components,
                                         const t_spaceship_id_entity spaceship_id);

    t_within_range_entity operator()() const;

private:
    t_scene_components& _scene_components;

    t_spaceship_component& _spaceship;

    const t_spaceship_id_entity _spaceship_id {};
};

#endif // T_SPACESHIP_SYSTEM_GET_WITHIN_RANGE_H
