#ifndef T_SYSTEM_ROCKET_LAUNCHER_H
#define T_SYSTEM_ROCKET_LAUNCHER_H

#include "../../../t_common_entities.h"
#include "../../../t_value_stepper.h"


class t_game_components;
using t_rocket_launcher_rocket_amount = int;
class t_component_spaceship;


class t_system_rocket_launcher
{
public:
    t_system_rocket_launcher(t_game_components& game_components);

    void update(const t_delta delta = t_delta_frame_per_second);

private:
    void launch_rockets(const t_component_spaceship& spaceship, const t_delta delta);

private:
    t_game_components& _game_components;

    t_rocket_id_generator _rocket_id_generator { 0, 1 };
};

#endif // T_SYSTEM_ROCKET_LAUNCHER_H
