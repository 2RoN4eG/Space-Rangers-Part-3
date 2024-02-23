#include "t_game_render_system.h"

#include "t_scene_components.h"

#include "QPainter"
#include "QWidget"

void set_painter_pen(t_render_painter& painter, const t_render_pen_color& color, int width) {
    QPen pen { color };
    pen.setCapStyle(Qt::RoundCap);
    pen.setWidth(width);

    painter.setRenderHint(QPainter::Antialiasing, true);
    painter.setPen(pen);
}

t_game_render_system::t_game_render_system(const t_render_surface_size& size, t_render_painter& painter, t_scene_components& scene_components)
    : _scene_components { scene_components }
    , _painter { painter }
    , _size { size }
{
}

void t_game_render_system::update(const t_delta delta) const {
    render_player();

    render_spaceships();

    render_trajectory();

    render_planets();

    render_rockets();
}

void t_game_render_system::render_player() const {
    set_painter_pen(_painter, Qt::green, 8);

    t_spaceship_component& player = _scene_components.player_spaceship();
    _painter.drawPoint(player.get_position().x(), _size.height() - player.get_position().y());
}

void t_game_render_system::render_spaceships() const {
    set_painter_pen(_painter, Qt::yellow, 8);

    for (const t_spaceship_component& spaceship : _scene_components.spaceships()) {
        if (spaceship.is_player()) {
            continue;
        }

        _painter.drawPoint(spaceship.get_position().x(), _size.height() - spaceship.get_position().y());
    }
}

void t_game_render_system::render_trajectory() const {
    set_painter_pen(_painter, Qt::yellow, 2);

    t_spaceship_component& spaceship = _scene_components.spaceship(t_spaceship_id_entity { 2 });
    for (const t_2d_position_entity position : spaceship.trajectory()) {
        _painter.drawPoint(position.x(), _size.height() - position.y());
    }
}

void t_game_render_system::render_planets() const {
    set_painter_pen(_painter, Qt::blue, 20);

    for (const t_component_planet& planet : _scene_components.planets()) {
        _painter.drawPoint(planet.get_position().x(), _size.height() - planet.get_position().y());
    }
}

void t_game_render_system::render_rockets() const {
    set_painter_pen(_painter, Qt::red, 3);

    for (const t_component_rocket& rocket : _scene_components.rockets()) {
        _painter.drawPoint(rocket.get_position().x(), _size.height() - rocket.get_position().y());
    }
}
