#ifndef T_SPACESHIP_DEFENCE_SYSTEM_H
#define T_SPACESHIP_DEFENCE_SYSTEM_H

#include "../interfaces/i_system.h"

// Система уклонения от ракет вражеского корабля
// Необходимо:
// - Радар
// - Устройство уклонения от ракет

class t_spaceship_defence_system : public i_system
{
public:
    t_spaceship_defence_system();

    bool requirements_completed() const;

private:
};

#endif // T_SPACESHIP_DEFENCE_SYSTEM_H
