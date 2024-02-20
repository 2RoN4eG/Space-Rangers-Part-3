#include "t_rocket_moving_system.h"

#include "../../../t_common_entities.h"
#include "../../../t_common_systems.h"

#include "t_component_rocket.h"
#include "../../../spaceships/t_component_spaceship.h"
#include "../../../t_scene_components.h"

#include "../../../linear_algebra/t_2d_linear_algebra_systems.h"


t_rocket_moving_system::t_rocket_moving_system(t_scene_components& scene_components)
    : _scene_components { scene_components }
{
}

void t_rocket_moving_system::update(const t_delta delta) {
    for (t_component_rocket& rocket : _scene_components.rockets()) {
        move_rocket(rocket, delta);
    }
}

void t_rocket_moving_system::move_rocket(t_component_rocket& rocket, const t_delta delta) {
    const t_spaceship_id aim_id = rocket.get_aim_id();
    
    t_2d_position_entity& rocket_position = rocket.position();

    const t_spaceship_component& aim_spaceship = _scene_components.spaceship(aim_id);
    
    const t_2d_position_entity& aim_position = aim_spaceship.get_position();

    const t_2d_heading_entity rocket_heading = make_vector_2d_system(rocket_position, aim_position);

    const t_linear_speed_entity rocket_linear_speed = rocket.get_linear_speed();
    
    const t_scalar_length_entity distance_length = t_2d_vector_length_system(rocket_heading);

    const float frames_to_destination = distance_length / rocket_linear_speed;

    const t_2d_step_per_frame step_per_frame = t_2d_vector_division_system(rocket_heading, frames_to_destination);

    rocket.position() = t_2d_vector_addition_system(rocket_position, step_per_frame);
}
