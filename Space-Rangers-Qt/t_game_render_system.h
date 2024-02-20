#ifndef T_GAME_RENDER_SYSTEM_H
#define T_GAME_RENDER_SYSTEM_H

#include "t_common_entities.h"

#include <vector>

class t_scene_components;

class QPainter;
class QWidget;
class QSize;
class QColor;

using t_render_surface      = QWidget;
using t_render_surface_size = QSize;
using t_render_painter      = QPainter;
using t_render_pen_color    = QColor;

class i_render_system { int v {}; };
using i_render_system_pointer = i_render_system*;
using i_render_system_reference = i_render_system_pointer;

template <typename t_reference>
class reference_wrapper {
};

class [[maybe_unused]] t_game_render_system
{
public:
    t_game_render_system(const t_render_surface_size& size, t_render_painter& painter, t_scene_components& scene_components);

    void update(const t_delta delta = t_delta_frame_per_second) const;

    void register_render_system(i_render_system_reference system);
    void register_render_system_before(i_render_system_reference system, std::string_view before);
    void register_render_system_after(i_render_system_reference system, std::string_view after);

    void unregister_render_system(i_render_system_reference system);

    void render_player() const;

    void render_spaceships() const;

    void render_trajectory() const;

    void render_planets() const;

    void render_rockets() const;

private:
    t_scene_components& _scene_components;

    t_render_painter& _painter;

    const t_render_surface_size& _size;

    std::vector<i_render_system_pointer> _render_systems {};
};

void set_painter_pen(t_render_painter& painter, const t_render_pen_color& color, int width);

#endif // T_GAME_RENDER_SYSTEM_H
