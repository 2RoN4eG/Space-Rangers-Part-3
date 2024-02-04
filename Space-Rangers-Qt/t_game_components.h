#ifndef T_GAME_COMPONENTS_H
#define T_GAME_COMPONENTS_H

#include "spaceships/t_spaceship_component.h"
#include "planets/t_planet_component.h"
#include "planetsystems/t_planetsystem_component.h"

class [[maybe_unused]] t_game_components
{
public:
    t_game_components();

    std::vector<t_spaceship_component>& spaceships();
    t_spaceship_component& spaceship(const t_spaceship_id_entity id);
    t_spaceship_component& player_spaceship();

    std::vector<t_planet_component>& planets();
    t_planet_component& planet(const t_planet_id_entity id);

    std::vector<t_planetsystem_component>& planetsystems();
    t_planetsystem_component& planetsystem(const t_planetsystem_id_entity id);

private:
    std::vector<t_spaceship_component> _spaceships;
    
    std::vector<t_planet_component> _planets;

    std::vector<t_planetsystem_component> _planetsystems;

};

#endif // T_GAME_COMPONENTS_H
