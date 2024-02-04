#include "t_game_components.h"

#include <string>
#include <iostream>

namespace {
    template <typename t_item, typename t_item_id, typename t_container>
    t_item& item_by_id(const t_item_id id, t_container& container) {
        for (t_item& item : container) {
            if (item.id() != id) { continue; }

            return item;
        }

        throw std::runtime_error { "item by id " + std::to_string(id) + " does not exist" };
    }
}


t_game_components::t_game_components()
    : _spaceships { make_player(), make_ai() }
    , _planets { make_planets(5) }
    , _planetsystems {}
{
    std::cout << "spaceships: " << _spaceships.size() << std::endl;
    for (const t_spaceship_component& spaceship : _spaceships) {
        const t_2d_position_entity position = spaceship.get_position();

        std::cout << "spaceship { id: " << spaceship._id << " } has position { x: " << position.x() << ", y: " << position.y() << " }" << std::endl;
    }

    std::cout << "planets   : " << _planets.size() << std::endl;
    for (const t_planet_component& planet : _planets) {
        const t_2d_position_entity position = planet.get_position();

        std::cout << "planet { id: " << planet._id << " } has position { x: " << position.x() << ", y: " << position.y() << " }" << std::endl;
    }
}


std::vector<t_spaceship_component>& t_game_components::spaceships() {
    return _spaceships;
}

t_spaceship_component& t_game_components::spaceship(const t_spaceship_id_entity id) {
    return item_by_id<t_spaceship_component>(id, _spaceships);
}

t_spaceship_component &t_game_components::player_spaceship() {
    for (t_spaceship_component& spaceship : _spaceships) {
        if (!spaceship.is_player()) { continue; }

        return spaceship;
    }

    throw std::runtime_error { "player's spaceship does not exist" };
}


std::vector<t_planet_component>& t_game_components::planets() {
    return _planets;
}

t_planet_component& t_game_components::planet(const t_planet_id_entity id) {
    return item_by_id<t_planet_component>(id, _planets);
}


std::vector<t_planetsystem_component>& t_game_components::planetsystems() {
    return _planetsystems;
}

t_planetsystem_component& t_game_components::planetsystem(const t_planetsystem_id_entity id) {
    return item_by_id<t_planetsystem_component>(id, _planetsystems);
}
