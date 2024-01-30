#ifndef I_GAME_SYSTEM_H
#define I_GAME_SYSTEM_H

#include <vector>
#include "../t_common_entities.h"


class i_game_system {
public:
    i_game_system(std::string_view system_name);

    const std::string_view system_name() const;

    virtual void update(const t_delta_timestamp delta = 500) = 0;

private:
    std::string_view _system_name;
};

#endif // I_GAME_SYSTEM_H
