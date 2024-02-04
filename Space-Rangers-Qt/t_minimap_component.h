#ifndef T_MINIMAP_COMPONENT_H
#define T_MINIMAP_COMPONENT_H

#include "t_common_entities.h"

struct t_minimap_size_entity {
public:
    t_minimap_size_entity() {
    }

private:
    int _width {};
    int _height {};
};

class [[maybe_unused]] t_minimap_component
{
public:
    t_minimap_component();

private:
    t_minimap_size_entity _size;
};

#endif // T_MINIMAP_COMPONENT_H
