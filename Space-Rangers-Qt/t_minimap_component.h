#ifndef T_MINIMAP_COMPONENT_H
#define T_MINIMAP_COMPONENT_H

#include "t_common_entities.h"

struct t_minimap_size {
public:
    t_minimap_size() {
    }

private:
    int _width {};
    int _height {};
};

class [[maybe_unused]] minimap_component
{
public:
    minimap_component();

private:
    t_minimap_size _size;
};

#endif // T_MINIMAP_COMPONENT_H
