#ifndef T_SCENE_COMPONENTS_H
#define T_SCENE_COMPONENTS_H

#include "spaceships/t_component_spaceship.h"
#include "spaceships/equipments/weapons/t_component_rocket.h"
#include "planets/t_component_planet.h"
#include "planetsystems/t_component_planetsystem.h"

class [[maybe_unused]] t_scene_components
{
public:
    t_scene_components();

    // std::vector<t_component_planetsystem>& planetsystems();
    // t_component_planetsystem& planetsystem(const t_planetsystem_id_entity id);

    std::vector<t_component_planet>& planets();
    t_component_planet& planet(const t_planet_id_entity id);

    std::vector<t_spaceship_component>& spaceships();
    t_spaceship_component& player_spaceship();
    t_spaceship_component& spaceship(const t_spaceship_id_entity id);

    std::vector<t_component_rocket>& rockets();

private:
    std::vector<t_component_planetsystem> _planetsystems;

    std::vector<t_component_planet> _planets;

    std::vector<t_spaceship_component> _spaceships;

    std::vector<t_component_rocket> _rockets;
};

#endif // T_SCENE_COMPONENTS_H
