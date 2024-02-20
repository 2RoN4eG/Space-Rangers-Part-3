#ifndef T_SPACESHIP_GET_WITHING_RANGE_SYSTEM_H
#define T_SPACESHIP_GET_WITHING_RANGE_SYSTEM_H

#include "../t_common_entities.h"

class t_scene_components;
class t_spaceship_component;

class t_spaceship_withing_range_system
{
public:
    t_spaceship_withing_range_system(t_scene_components& scene_components, const t_spaceship_id_entity spaceship_id);

    void update(const t_delta delta = t_delta_frame_per_second);

private:
    t_scene_components& _scene_components;

    t_spaceship_component& _spaceship;
};

#endif // T_SPACESHIP_GET_WITHING_RANGE_SYSTEM_H
