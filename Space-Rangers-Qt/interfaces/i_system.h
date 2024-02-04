#ifndef I_SYSTEM_H
#define I_SYSTEM_H

#include "../t_common_entities.h"

class i_system {
public:
    i_system(std::string_view system_name);

    virtual ~i_system() = 0;

    virtual void update(const t_delta_timestamp delta = 500) = 0;

    virtual bool requirements_completed() const {
        return {};
    }

    virtual void insert_after(std::string_view system_name) {
    }

    const std::string_view system_name() const;

private:
    std::string_view _system_name;
};

#endif // I_SYSTEM_H
