#ifndef T_SYSTEM_MAKE_PLANETS_H
#define T_SYSTEM_MAKE_PLANETS_H

#include "t_component_planet.h"
#include "../t_common_entities.h"


std::vector<t_planet_component> t_system_make_planets(const size_t amount, t_planet_id_generator planet_id_generator = { 0, 1 });

#endif // T_SYSTEM_MAKE_PLANETS_H
