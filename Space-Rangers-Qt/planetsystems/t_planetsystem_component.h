#ifndef T_PLANETSYSTEM_COMPONENT_H
#define T_PLANETSYSTEM_COMPONENT_H

#include "../t_common_entities.h"

class t_planetsystem_component
{
public:
    t_planetsystem_component(const t_planetsystem_id_entity id);

    t_spaceship_id_entity id() const;

private:
    t_planetsystem_id_entity _id;
};

#endif // T_PLANETSYSTEM_COMPONENT_H
