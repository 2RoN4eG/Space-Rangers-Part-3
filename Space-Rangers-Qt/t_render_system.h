#ifndef T_RENDER_SYSTEM_H
#define T_RENDER_SYSTEM_H

#include "t_common_entities.h"

class t_game_components;

class QPainter;
class QWidget;
class QSize;
class QColor;

using t_render_surface      = QWidget;
using t_render_surface_size = QSize;
using t_render_painter      = QPainter;
using t_render_pen_color    = QColor;

class [[maybe_unused]] t_render_system
{
public:
    t_render_system(const t_render_surface_size& size, t_render_painter& painter, t_game_components& game_components);

    void update(const t_delta_timestamp delta = 500) const;

    void render_planets() const;

    void render_spaceships() const;

    void render_trajectory() const;

private:
    t_game_components& _game_components;

    t_render_painter& _painter;

    const t_render_surface_size& _size;
};

void set_painter_pen(t_render_painter& painter, const t_render_pen_color& color, int width);

#endif // T_RENDER_SYSTEM_H
