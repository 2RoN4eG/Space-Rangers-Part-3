#ifndef T_PLANET_SYSTEM_MAKE_PLANETS_H
#define T_PLANET_SYSTEM_MAKE_PLANETS_H

#include "t_planet_component.h"
#include "../t_common_entities.h"


std::vector<t_component_planet> t_system_make_planets(const size_t amount, t_planet_id_generator planet_id_generator = { 0, 1 });

#endif // T_PLANET_SYSTEM_MAKE_PLANETS_H
