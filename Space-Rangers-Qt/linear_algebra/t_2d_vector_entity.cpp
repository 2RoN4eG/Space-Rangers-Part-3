#include "t_2d_vector_entity.h"

template <typename t_2d_vector_value, typename std::enable_if_t<std::is_floating_point_v<t_2d_vector_value>, bool> = true>
bool does_not_equal(const t_2d_vector_value lhs, const t_2d_vector_value rhs) {
    return std::abs(lhs - rhs) > std::numeric_limits<t_2d_vector_value>::epsilon();
}

bool operator!=(const t_2d_vector_entity lhs, const t_2d_vector_entity rhs) {
    return does_not_equal(lhs.x(), rhs.x()) || does_not_equal(lhs.y(), rhs.y());
}
