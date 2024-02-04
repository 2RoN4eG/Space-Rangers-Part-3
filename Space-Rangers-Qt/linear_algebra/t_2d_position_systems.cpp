#include "t_2d_position_systems.h"

t_2d_position position_subtraction_system(const t_2d_position& lhs, const t_2d_position& rhs) {
    return { lhs.x() - rhs.x(), lhs.y() - lhs.y() };
}

t_2d_position position_addition_system(const t_2d_position& lhs, const t_2d_position& rhs) {
    return { lhs.x() + rhs.x(), lhs.y() + lhs.y() };
}

t_2d_vector_entity make_2d_vector(const t_2d_position& from, const t_2d_position& to) {
    return { t_2d_vector_value (to.x() - from.x()), t_2d_vector_value (to.y() - from.y()) };
}
