#pragma once

#include <string>

enum class Command {
    Look,
    Move,
    Take,
    Inventory,
    Save,
    Restore,
    Quit,
    Unknown
};

Command parse_command(const std::string& input);
