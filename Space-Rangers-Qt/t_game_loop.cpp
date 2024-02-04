#include "t_game_loop.h"

#include "t_game_components.h"

t_game_loop::t_game_loop(t_game_components& game_components)
    : _game_components { game_components }
{
}

void t_game_loop::update(const t_delta_timestamp delta) {

}
