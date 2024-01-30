#ifndef T_RENDER_SYSTEM_H
#define T_RENDER_SYSTEM_H

#include "t_common_entities.h"

class [[maybe_unused]] t_render_system
{
public:
    t_render_system();

    void update(const t_delta_timestamp delta);
};

#endif // T_RENDER_SYSTEM_H
