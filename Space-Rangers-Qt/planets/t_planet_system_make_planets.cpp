#include "t_planet_system_make_planets.h"


std::vector<t_component_planet> t_system_make_planets(const size_t amount, t_planet_id_generator planet_id_generator) {
    t_value_stepper<t_radius_entity> radius_generator { 300., 60. };
    t_value_stepper<t_scalar_angle_entity> angle_generator  { 0., 90. / 4 };
    
    std::vector<t_component_planet> planets;

    for (size_t index {}; index < amount; ++index) {
        const t_planet_id_entity planet_id = planet_id_generator.get_value_and_generate_next();
        const t_radius_entity    radius    = radius_generator.get_value_and_generate_next();
        const t_scalar_angle_entity     angle     = angle_generator.get_value_and_generate_next();
        
        planets.emplace_back(t_component_planet { planet_id, radius, angle });
    }

    return planets;
}
