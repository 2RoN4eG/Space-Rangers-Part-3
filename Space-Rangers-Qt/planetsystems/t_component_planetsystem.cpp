#include "t_component_planetsystem.h"

t_planetsystem_component::t_planetsystem_component(const t_planetsystem_id_entity id)
    : _id { id }
{
}

t_spaceship_id_entity t_planetsystem_component::id() const { return _id; }
