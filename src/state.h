#pragma once

#include "world.h"

struct WorldState {
    bool heavy_door_unlocked;
};

struct GameState {
    RoomId current_room_id;
    struct WorldState world_state;
};

void state_init();

struct GameState* state_get_state();