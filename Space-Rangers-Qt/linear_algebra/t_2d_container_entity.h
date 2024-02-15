#ifndef T_2D_CONTAINER_ENTITY_H
#define T_2D_CONTAINER_ENTITY_H

#include <array>
#include <vector>


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

    inline t_2d_axis x() const { return std::get<t_2d_axis_x>(_axises); }

    inline t_2d_axis y() const { return std::get<t_2d_axis_y>(_axises); }

protected:
    std::array<t_2d_axis, 2> _axises { {}, {} };
};


void complex_test_2d_container(std::vector<std::runtime_error>& errors);

#endif // T_2D_CONTAINER_ENTITY_H
