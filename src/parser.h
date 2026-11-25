#pragma once

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

Command parse_command(char *input);
