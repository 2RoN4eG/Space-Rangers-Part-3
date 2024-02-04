#include "t_render_system.h"

#include "t_game_components.h"

#include "QPainter"
#include "QWidget"

void set_painter_pen(t_render_painter& painter, const t_render_pen_color& color, int width) {
    QPen pen { color };
    pen.setCapStyle(Qt::RoundCap);
    pen.setWidth(width);

    painter.setRenderHint(QPainter::Antialiasing, true);
    painter.setPen(pen);
}

t_render_system::t_render_system(const t_render_surface_size& size, t_render_painter& painter, t_game_components& game_components)
    : _game_components { game_components }
    , _painter { painter }
    , _size { size }
{
}

void t_render_system::update(const t_delta_timestamp delta) const {
    // render_planets();
    // render_spaceships();
}

void t_render_system::render_planets() const {
    set_painter_pen(_painter, Qt::blue, 10);
    for (const t_planet_component& planet : _game_components.planets()) {
        _painter.drawPoint(planet.get_position().x(), _size.height() - planet.get_position().y());
    }
}

void t_render_system::render_spaceships() const {
    const t_spaceship_component& player_spaceship = _game_components.player_spaceship();
    set_painter_pen(_painter, Qt::green, 8);
    _painter.drawPoint(player_spaceship.get_position().x(), _size.height() - player_spaceship.get_position().y());

    set_painter_pen(_painter, Qt::red, 4);
    for (const t_spaceship_component& spaceship : _game_components.spaceships()) {
        if (spaceship.is_player()) {
            continue;
        }

        _painter.drawPoint(spaceship.get_position().x(), _size.height() - spaceship.get_position().y());
    }
}

void t_render_system::render_trajectory() const {
    set_painter_pen(_painter, Qt::yellow, 8);

    t_spaceship_component& spaceship = _game_components.spaceship(t_spaceship_id_entity { 2 });
    for (const t_2d_position_entity position : spaceship.trajectory()) {
        _painter.drawPoint(position.x(), _size.height() - position.y());
    }
}
