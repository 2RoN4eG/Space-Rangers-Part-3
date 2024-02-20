#include "t_component_planetsystem.h"

t_component_planetsystem::t_component_planetsystem(const t_planetsystem_id_entity id)
    : _id { id }
{
}

t_spaceship_id_entity t_component_planetsystem::id() const { return _id; }
