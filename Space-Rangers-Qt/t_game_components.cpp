#include "t_game_components.h"

#include <string>
#include <iostream>

t_game_components::t_game_components()
    : _spaceships { make_player(), make_ai() }
    , _planets { make_planets(5) }
{
    std::cout << "spaceships: " << _spaceships.size() << std::endl;

    std::cout << "planets   : " << _planets.size() << std::endl;
    for (const t_planet_game_component& planet : _planets) {
        const t_2d_position_entity position = planet.get_position();

        std::cout << "planet { id: " << planet._id << " } has position { x: " << position.x() << ", y: " << position.y() << " }" << std::endl;
    }
}


std::vector<t_spaceship_component>& t_game_components::spaceships() {
    return _spaceships;
}

t_spaceship_component& t_game_components::spaceship(const t_spaceship_id_entity id) {
    for (t_spaceship_component& spaceship : _spaceships) {
        if (spaceship.id() != id) {
            continue;
        }

        return spaceship;
    }

    throw std::runtime_error { "spaceship by id " + std::to_string(id) + " does not exist" };
}


std::vector<t_planet_game_component>& t_game_components::planets() {
    return _planets;
}

t_planet_game_component& t_game_components::planet(const t_planet_id_entity id) {
    for (t_planet_game_component& planet : _planets) {
        if (planet.id() != id) {
            continue;
        }

        return planet;
    }

    throw std::runtime_error { "planet by id " + std::to_string(id) + " does not exist" };
}
