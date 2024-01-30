#include "../interfaces/i_game_system.h"

i_game_system::i_game_system(std::string_view system_name)
    : _system_name { system_name }
{
}

const std::string_view i_game_system::system_name() const {
    return _system_name;
}
