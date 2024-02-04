#include "../interfaces/i_system.h"

#include <iostream>

i_system::i_system(std::string_view system_name)
    : _system_name { system_name }
{
    std::cout << "system: " << system_name << std::endl;
}

i_system::~i_system()
{
}

const std::string_view i_system::system_name() const {
    return _system_name;
}
