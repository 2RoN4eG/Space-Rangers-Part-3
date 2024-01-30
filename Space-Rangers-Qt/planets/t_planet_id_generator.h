#ifndef T_PLANET_ID_GENERATOR_H
#define T_PLANET_ID_GENERATOR_H

#include "../t_common_entities.h"
#include "../t_stepper.h"

class t_planet_id_generator {
public:
    t_planet_id_entity get_planet_id() const {
        return _planet_ids.next();
    }

private:
    t_stepper<t_planet_id_entity> _planet_ids { 0, 1 };
};


#endif // T_PLANET_ID_GENERATOR_H
