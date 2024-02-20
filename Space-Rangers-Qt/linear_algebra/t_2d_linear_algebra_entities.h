#ifndef T_2D_LINEAR_ALGEBRA_ENTITIES_H
#define T_2D_LINEAR_ALGEBRA_ENTITIES_H

#include <array>


enum t_3d_axises {
    t_3d_axis_x = 0,
    t_3d_axis_y = 1,
    t_3d_axis_z = 2
};

enum t_2d_axises {
    t_2d_axis_x = t_3d_axis_x,
    t_2d_axis_y = t_3d_axis_y
};


template <typename t_2d_axis>
class t_2d_container {
public:
    t_2d_container()
        : t_2d_container { {}, {} }
    {
    }

    t_2d_container(t_2d_axis x, t_2d_axis y)
        : _axises { x, y }
    {
    }

    inline t_2d_axis x() const {
        return std::get<t_2d_axis_x>(_axises);
    }

    inline t_2d_axis y() const {
        return std::get<t_2d_axis_y>(_axises);
    }

protected:
    std::array<t_2d_axis, 2> _axises { {}, {} };
};

using t_floating_point      = float;

using t_2d_axis             = t_floating_point;

using t_2d_vector_axis      = t_2d_axis;
using t_2d_vector           = t_2d_container<t_2d_vector_axis>;
using t_2d_vector_length    = t_floating_point;
using t_2d_distance_length  = t_floating_point;

using t_2d_scalar           = t_floating_point;

using t_2d_position_axis    = t_2d_axis;
using t_2d_position         = t_2d_container<t_2d_position_axis>;


#endif // T_2D_LINEAR_ALGEBRA_ENTITIES_H
