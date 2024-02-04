#include "t_spaceship_defence_system.h"

#include "../t_common_entities.h"

t_spaceship_defence_system::t_spaceship_defence_system()
    : i_system { __CLASS_NAME__ }
{
}

bool t_spaceship_defence_system::requirements_completed() const {
    return {};
}
