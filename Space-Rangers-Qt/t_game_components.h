#ifndef T_GAME_COMPONENTS_H
#define T_GAME_COMPONENTS_H

#include "spaceships/t_component_spaceship.h"
#include "spaceships/equipments/weapons/t_component_rocket.h"
#include "planets/t_component_planet.h"
#include "planetsystems/t_component_planetsystem.h"

class [[maybe_unused]] t_game_components
{
public:
    t_game_components();

    std::vector<t_planetsystem_component>& planetsystems();
    t_planetsystem_component& planetsystem(const t_planetsystem_id_entity id);

    std::vector<t_planet_component>& planets();
    t_planet_component& planet(const t_planet_id_entity id);

    std::vector<t_component_spaceship>& spaceships();
    t_component_spaceship& player_spaceship();
    t_component_spaceship& spaceship(const t_spaceship_id_entity id);

    std::vector<t_component_rocket>& rockets();

private:
    std::vector<t_planetsystem_component> _planetsystems;

    std::vector<t_planet_component> _planets;
    
    std::vector<t_component_spaceship> _spaceships;
    
    std::vector<t_component_rocket> _rockets;
};

#endif // T_GAME_COMPONENTS_H
