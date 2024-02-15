#ifndef T_MINIMAP_COMPONENT_H
#define T_MINIMAP_COMPONENT_H

#include "t_common_entities.h"

class [[maybe_unused]] t_size_container {
public:
    t_size_container()
        : t_size_container { {}, {} }
    {
    }

    t_size_container(t_size_default_axis width, t_size_default_axis height)
        : _width { width }
        , _height { height }
    {
    }

private:
    t_size_default_axis _width {};
    t_size_default_axis _height {};
};

class [[maybe_unused]] t_minimap_component
{
public:
    t_minimap_component();

private:
    t_size_container _size;
};

#endif // T_MINIMAP_COMPONENT_H
