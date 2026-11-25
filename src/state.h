#pragma once

#include "world.h"

struct GameState {
    RoomId current_room_id;
};

void state_init();

struct GameState* state_get_state();