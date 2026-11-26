#pragma once

#define TARGET_MAX_LENGTH 100

enum Action {
    Look,
    Move,
    Take,
    Inventory,
    Save,
    Restore,
    Quit,
    Unknown,
    Unlock
};

struct Command {
    Action action;
    char target[TARGET_MAX_LENGTH] = {};
};
