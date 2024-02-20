#include "t_sprite_render_system.h"


t_sprite_render_system::t_sprite_render_system(std::vector<t_sprite_path>&& sprites, t_2d_position& position)
    : _sprites { std::move(sprites) }
    , _position { position }
{
}

void t_sprite_render_system::update(const t_delta delta) {
}
