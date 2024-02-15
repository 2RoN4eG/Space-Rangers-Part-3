#ifndef I_GAME_SYSTEM_H
#define I_GAME_SYSTEM_H

#include "../t_common_entities.h"

class i_game_system {
public:
    i_game_system(std::string_view system_name);

    virtual ~i_game_system() = 0;
    
    virtual void update(const t_delta delta = t_delta_frame_per_second) = 0;

    virtual bool requirements_completed() const {
        return {};
    }

    const std::string_view system_name() const;

private:
    std::string_view _system_name;
};

#endif // I_GAME_SYSTEM_H
