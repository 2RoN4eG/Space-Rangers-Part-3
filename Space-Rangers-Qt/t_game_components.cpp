#include "t_game_components.h"

#include <string>
#include <iostream>

#include "planets/t_system_make_planets.h"

namespace {
    template <typename t_item, typename t_item_id, typename t_container>
    t_item& item_by_id(const t_item_id id, t_container& container) {
        for (t_item& item : container) {
            if (item.id() != id) { continue; }

            return item;
        }

        throw std::runtime_error { "item by id " + std::to_string(id) + " does not exist" };
    }

    void print_planetsystems([[maybe_unused]] const std::vector<t_planetsystem_component>& planetsystems) { }

    void print_planets(const std::vector<t_planet_component>& planets) {
        std::cout << "planets   : " << planets.size() << std::endl;
        for (const t_planet_component& planet : planets) {
            const t_planet_id_entity   pid = planet._id;
            const t_2d_position_entity pp  = planet.get_position();

            std::cout << "planet { id: " << pid << " } has position { x: " << pp.x() << ", y: " << pp.y() << " }" << std::endl;
        }
    }
    
    void print_spaceships(const std::vector<t_component_spaceship>& spaceships) {
        std::cout << "spaceships: " << spaceships.size() << std::endl;
        for (const t_component_spaceship& spaceship : spaceships) {
            const t_spaceship_id_entity sid = spaceship._id;
            const t_2d_position_entity  sp  = spaceship.get_position();

            std::cout << "spaceship { id: " << sid << " } has position { x: " << sp.x() << ", y: " << sp.y() << " }" << std::endl;
        }
    }

    void print_rockets([[maybe_unused]] const std::vector<t_component_rocket>& rockets) { }
}


t_game_components::t_game_components()
    : _spaceships { make_player(), make_spaceship() }
    , _planets { t_system_make_planets(5) }
    , _planetsystems {}
    , _rockets {}
{
    print_planetsystems(_planetsystems);

    print_planets(_planets);

    print_spaceships(_spaceships);

    print_rockets(_rockets);
}


std::vector<t_planetsystem_component>& t_game_components::planetsystems() {
    return _planetsystems;
}

t_planetsystem_component& t_game_components::planetsystem(const t_planetsystem_id_entity id) {
    return item_by_id<t_planetsystem_component>(id, _planetsystems);
}


std::vector<t_planet_component>& t_game_components::planets() {
    return _planets;
}

t_planet_component& t_game_components::planet(const t_planet_id_entity id) {
    return item_by_id<t_planet_component>(id, _planets);
}


std::vector<t_component_spaceship>& t_game_components::spaceships() {
    return _spaceships;
}

t_component_spaceship &t_game_components::player_spaceship() {
    for (t_component_spaceship& spaceship : _spaceships) {
        if (!spaceship.is_player()) { continue; }

        return spaceship;
    }

    throw std::runtime_error { "player's spaceship does not exist" };
}

t_component_spaceship& t_game_components::spaceship(const t_spaceship_id_entity id) {
    return item_by_id<t_component_spaceship>(id, _spaceships);
}


std::vector<t_component_rocket>& t_game_components::rockets() {
    return _rockets;
}
