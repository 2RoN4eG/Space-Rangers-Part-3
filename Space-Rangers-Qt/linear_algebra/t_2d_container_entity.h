#ifndef T_2D_CONTAINER_ENTITY_H
#define T_2D_CONTAINER_ENTITY_H

#include <array>
#include <vector>

//

enum t_3d_axises {
    t_3d_x_axis = 0,
    t_3d_y_axis = 1,
    t_3d_z_axis = 2
};

enum t_2d_axises {
    t_2d_x_axis = t_3d_x_axis,
    t_2d_y_axis = t_3d_y_axis
};

//

template <typename t_2d_container_axis>
class t_2d_container {
public:
    t_2d_container()
        : t_2d_container { {}, {} } { }

    t_2d_container(t_2d_container_axis x, t_2d_container_axis y)
        : _axises { x, y } { }

    inline t_2d_container_axis x() const { return std::get<t_2d_x_axis>(_axises); }

    inline t_2d_container_axis y() const { return std::get<t_2d_y_axis>(_axises); }

private:
    std::array<t_2d_container_axis, 3> _axises { {}, {} };
};

void complex_test_2d_container(std::vector<std::runtime_error>& errors);

#endif // T_2D_CONTAINER_ENTITY_H
