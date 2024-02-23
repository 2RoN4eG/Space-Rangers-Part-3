#include "t_scene_components.h"

#include <string>
#include <iostream>

#include "planets/t_planet_system_make_planets.h"

namespace {
    template <typename t_item, typename t_item_id, typename t_container>
    t_item& item_by_id(const t_item_id id, t_container& container) {
        for (t_item& item : container) {
            if (item.id() != id) { continue; }

            return item;
        }

        throw std::runtime_error { "item by id " + std::to_string(id) + " does not exist" };
    }
    
    // void print_planetsystems([[maybe_unused]] const std::vector<t_component_planetsystem>& planetsystems) { }

    void print_planets(const std::vector<t_component_planet>& planets) {
        std::cout << "planets   : " << planets.size() << std::endl;
        for (const t_component_planet& planet : planets) {
            const t_planet_id_entity   pid = planet._id;
            const t_2d_position_entity pp  = planet.get_position();

            std::cout << "planet { id: " << pid << " } has position { x: " << pp.x() << ", y: " << pp.y() << " }" << std::endl;
        }
    }
    
    void print_spaceships(const std::vector<t_spaceship_component>& spaceships) {
        std::cout << "spaceships: " << spaceships.size() << std::endl;
        for (const t_spaceship_component& spaceship : spaceships) {
            const t_spaceship_id_entity sid = spaceship._id;
            const t_2d_position_entity  sp  = spaceship.get_position();

            std::cout << "spaceship { id: " << sid << " } has position { x: " << sp.x() << ", y: " << sp.y() << " }" << std::endl;
        }
    }

    void print_rockets([[maybe_unused]] const std::vector<t_component_rocket>& rockets) { }
}


t_scene_components::t_scene_components()
    : _spaceships { make_player(), make_spaceship() }
    , _planets { t_system_make_planets(5) }
    // , _planetsystems {}
    , _rockets {}
{
    // print_planetsystems(_planetsystems);

    print_planets(_planets);

    print_spaceships(_spaceships);

    print_rockets(_rockets);
}


// std::vector<t_component_planetsystem>& t_scene_components::planetsystems() {
//     return _planetsystems;
// }

// t_component_planetsystem& t_scene_components::planetsystem(const t_planetsystem_id_entity id) {
//     return item_by_id<t_component_planetsystem>(id, _planetsystems);
// }


std::vector<t_component_planet>& t_scene_components::planets() {
    return _planets;
}

t_component_planet& t_scene_components::planet(const t_planet_id_entity id) {
    return item_by_id<t_component_planet>(id, _planets);
}


std::vector<t_spaceship_component>& t_scene_components::spaceships() {
    return _spaceships;
}

t_spaceship_component &t_scene_components::player_spaceship() {
    for (t_spaceship_component& spaceship : _spaceships) {
        if (!spaceship.is_player()) { continue; }

        return spaceship;
    }

    throw std::runtime_error { "player's spaceship does not exist" };
}

t_spaceship_component& t_scene_components::spaceship(const t_spaceship_id_entity id) {
    return item_by_id<t_spaceship_component>(id, _spaceships);
}


std::vector<t_component_rocket>& t_scene_components::rockets() {
    return _rockets;
}
