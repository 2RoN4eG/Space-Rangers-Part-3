#ifndef T_COMPONENT_PLANETSYSTEM_H
#define T_COMPONENT_PLANETSYSTEM_H

#include "../t_common_entities.h"

class t_component_planetsystem
{
public:
    t_component_planetsystem(const t_planetsystem_id_entity id);

    t_spaceship_id_entity id() const;

private:
    t_planetsystem_id_entity _id;
};

#endif // T_COMPONENT_PLANETSYSTEM_H
