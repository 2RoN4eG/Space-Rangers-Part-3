#include "t_game_render_system.h"

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

t_game_render_system::t_game_render_system(const t_render_surface_size& size, t_render_painter& painter, t_game_components& game_components)
    : _game_components { game_components }
    , _painter { painter }
    , _size { size }
{
}

void t_game_render_system::register_render_system([[maybe_unused]] i_render_system_reference reference) {
    // _render_systems.emplece_back(reference);
}

void t_game_render_system::register_render_system_after([[maybe_unused]] i_render_system_reference reference, [[maybe_unused]] std::string_view after) {
}

void t_game_render_system::register_render_system_before([[maybe_unused]] i_render_system_reference reference, [[maybe_unused]] std::string_view before) {
}

void t_game_render_system::unregister_render_system(i_render_system_reference reference) {
    // auto iterator = std::find(_render_systems.begin(), _render_systems.end(), reference);
    // if (iterator != _render_systems.end()) {
    // }
}

void t_game_render_system::update(const t_delta delta) const {
}

void t_game_render_system::render_player() const {
    set_painter_pen(_painter, Qt::green, 4);
    t_spaceship_component& player = _game_components.player_spaceship();
    _painter.drawPoint(player.get_position().x(), _size.height() - player.get_position().y());
}

void t_game_render_system::render_spaceships() const {
    set_painter_pen(_painter, Qt::yellow, 8);
    for (const t_spaceship_component& spaceship : _game_components.spaceships()) {
        if (spaceship.is_player()) {
            continue;
        }

        _painter.drawPoint(spaceship.get_position().x(), _size.height() - spaceship.get_position().y());
    }
}

void t_game_render_system::render_trajectory() const {
    set_painter_pen(_painter, Qt::yellow, 4);

    t_spaceship_component& spaceship = _game_components.spaceship(t_spaceship_id_entity { 2 });
    for (const t_2d_position_entity position : spaceship.trajectory()) {
        _painter.drawPoint(position.x(), _size.height() - position.y());
    }
}

void t_game_render_system::render_planets() const {
    set_painter_pen(_painter, Qt::blue, 10);
    for (const t_component_planet& planet : _game_components.planets()) {
        _painter.drawPoint(planet.get_position().x(), _size.height() - planet.get_position().y());
    }
}

void t_game_render_system::render_rockets() const {
    set_painter_pen(_painter, Qt::red, 4);
    for (const t_component_rocket& rocket : _game_components.rockets()) {
        _painter.drawPoint(rocket.get_position().x(), _size.height() - rocket.get_position().y());
    }
}
