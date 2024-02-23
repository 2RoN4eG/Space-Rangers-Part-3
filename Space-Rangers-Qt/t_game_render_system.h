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


class t_game_render_system
{
public:
    t_game_render_system(const t_render_surface_size& size, t_render_painter& painter, t_scene_components& scene_components);

    void update(const t_delta delta = t_delta_frame_per_second) const;

private:
    void render_player() const;

    void render_spaceships() const;

    void render_trajectory() const;

    void render_planets() const;

    void render_rockets() const;

private:
    t_scene_components& _scene_components;

    t_render_painter& _painter;

    const t_render_surface_size& _size;
};

void set_painter_pen(t_render_painter& painter, const t_render_pen_color& color, int width);

#endif // T_GAME_RENDER_SYSTEM_H
