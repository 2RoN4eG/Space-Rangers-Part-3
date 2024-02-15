#include "t_2d_position_systems.h"
#include "t_2d_vector_systems.h"

namespace {
    t_2d_vector_entity inline_make_2d_vector_system(const t_2d_position_entity& from, const t_2d_position_entity& to) {
        return { t_2d_axis_value (to.x() - from.x()), t_2d_axis_value (to.y() - from.y()) };
    }
}

t_2d_position_entity t_2d_position_subtraction_system(const t_2d_position_entity& lhs, const t_2d_position_entity& rhs) {
    return { lhs.x() - rhs.x(), lhs.y() - lhs.y() };
}

t_2d_position_entity t_2d_position_addition_system(const t_2d_position_entity& lhs, const t_2d_position_entity& rhs) {
    return { lhs.x() + rhs.x(), lhs.y() + lhs.y() };
}

t_2d_vector_entity t_make_2d_vector_system(const t_2d_position_entity& from, const t_2d_position_entity& to) {
    return inline_make_2d_vector_system(from, to);
}

t_2d_vector_length_entity t_2d_distance_length_system(const t_2d_position_entity& from, const t_2d_position_entity& to) {
    const t_2d_vector_entity&& vector = t_make_2d_vector_system(from, to);

    return t_2d_vector_length_system(std::move(vector));
}
