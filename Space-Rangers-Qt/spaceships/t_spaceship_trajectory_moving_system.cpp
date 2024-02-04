#include "t_spaceship_trajectory_moving_system.h"

#include "../t_game_components.h"

#include "../linear_algebra/t_2d_position_systems.h"
#include "../linear_algebra/t_2d_vector_systems.h"

#include <iostream>

#include "../t_common_entities.h"

t_spaceship_trajectory_moving_system::t_spaceship_trajectory_moving_system(t_spaceship_component& spaceship)
    : i_system { __CLASS_NAME__ }
    , _spaceship { spaceship }
{
}

t_spaceship_trajectory_moving_system::t_spaceship_trajectory_moving_system(t_game_components& game_components, const t_spaceship_id_entity spaceship_id)
    : t_spaceship_trajectory_moving_system { game_components.spaceship(spaceship_id) }
{
}

void t_spaceship_trajectory_moving_system::update([[maybe_unused]] t_delta_timestamp delta) {
    t_trajectory_entity& trajectory = _spaceship.trajectory();

    if (trajectory.empty()) {
        // std::cout << "spaceship " << _spaceship._id << " trajectory is empty" << std::endl;
        return;
    }

    // std::cout << "spaceship " << _spaceship._id << " speed is " << _spaceship.speed() << std::endl;

    t_2d_position_entity& position = _spaceship.position();
    // std::cout << "spaceship " << _spaceship._id << " position is { " << position.x() << ", " << position.y() << " }" << std::endl;

    const t_2d_position_entity& target = trajectory.front();
    // std::cout << "spaceship " << _spaceship._id << " target is { " << target.x() << ", " << target.y() << " }" << std::endl;

    const t_2d_vector_entity heading = make_2d_vector(position, target);
    // std::cout << "spaceship " << _spaceship._id << " heading is { " << heading.x() << ", " << heading.y() << " }" << std::endl;

    const t_2d_vector_length distance = t_2d_vector_length_system(heading);
    // std::cout << "spaceship " << _spaceship._id << " distance to point { " << destination.x() << ", " << destination.y() << " } is " << distance << std::endl;

    const float hopes = distance / _spaceship.get_speed();
    // std::cout << "spaceship " << _spaceship._id << " steps to point { " << destination.x() << ", " << destination.y() << " } are " << steps << std::endl;

    const t_2d_vector_entity step = t_2d_vector_division_system(heading, hopes);
    // std::cout << "spaceship " << _spaceship._id << " heading is { " << heading_.x() << ", " << heading_.y() << " }" << std::endl;

    // const t_2d_vector step = t_2d_vector_division_system(heading, _spaceship.speed());
    // std::cout << "spaceship " << _spaceship._id << " step is { " << step.x() << ", " << step.y() << " }" << std::endl;

    position = t_2d_vector_addition_system(position, step);
    // std::cout << "spaceship " << _spaceship._id << " position is { " << position.x() << ", " << position.y() << " }" << std::endl;

    const t_2d_vector_length heding_length = t_2d_vector_length_system(heading);
    if (_spaceship.get_speed() >= heding_length && !trajectory.empty()) {
        // std::cout << "spaceship " << _spaceship._id << " heading is { " << heading.x() << ", " << heading.y() << " }, length is " << heding_length << std::endl;

        position = trajectory.front();
        // std::cout << "spaceship " << _spaceship._id << " final position is { " << position.x() << ", " << position.y() << " }" << std::endl;

        trajectory.erase(trajectory.begin());
        // std::cout << "spaceship " << _spaceship._id << " trajectory size is " << trajectory.size() << std::endl;
    }

    // std::cout << std::endl;
}
