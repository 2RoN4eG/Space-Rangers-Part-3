#ifndef T_SPRITE_RENDER_SYSTEM_H
#define T_SPRITE_RENDER_SYSTEM_H

#include <filesystem>
#include <vector>

#include "linear_algebra/t_2d_linear_algebra_entities.h"
#include "t_common_entities.h"


using t_sprite_path = std::string_view;
class t_game_components;


class t_sprite_render_system
{
public:
    t_sprite_render_system(std::vector<t_sprite_path>&& sprites, t_2d_position& position);

    void update(const t_delta delta = t_delta_frame_per_second);

private:
    std::vector<t_sprite_path> _sprites {};

    t_2d_position& _position;
};

#endif // T_SPRITE_RENDER_SYSTEM_H
